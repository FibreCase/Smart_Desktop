#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent), ui(new Ui::Widget) {
	ui->setupUi(this);

    // QLabel
    ui->displayLabel->setText("Big Brother is watching you.");

    // QTimer
    timer1 = new QTimer;
    connect(timer1, &QTimer::timeout, this, &Widget::timer1Update);
    timer1->start(SECOND);

	timer2 = new QTimer;
	connect(timer2, &QTimer::timeout, this, &Widget::timer2Update);
	timer2->start(5 * SECOND);

	timer3 = new QTimer;
	connect(timer3, &QTimer::timeout, this, &Widget::timer3Update);
    timer3->start(5 * MINUTE);

    // QCalenderWidget
	ui->calendarWidget->setFirstDayOfWeek(Qt::Sunday);
	calendarSetToday();

	// QTabWidget
	setStyleSheet(QString("QTabBar::tab{height:40;width:%1}").arg(ui->tabWidget->width() / 3));

	// QTcpServer
    server30520 = new QTcpServer;
    server30520->listen(QHostAddress("0.0.0.0"), 30520);
    connect(server30520, &QTcpServer::newConnection, this, &Widget::acceptTcp30520);

    server30522 = new QTcpServer;
    server30522->listen(QHostAddress("0.0.0.0"), 30522);
    connect(server30522, &QTcpServer::newConnection, this, &Widget::acceptTcp30522);

    // QProcess
    cmdTemp = new QProcess;
    connect(cmdTemp, &QProcess::readyReadStandardOutput, this, &Widget::tempReadoutput);
    cmdLoad = new QProcess;
    connect(cmdLoad, &QProcess::readyReadStandardOutput, this, &Widget::loadReadoutput);

	// Weather
    weatherTimerCount = 0;
    indoorRequire();
    QThread::msleep(200);
    weatherRequire();
    rainRequire();
    airRequire();

    // Messager Image
    setDefaultImg();
}

Widget::~Widget() {
	delete ui;

	// QProcess Kill Self
	if (cmdTemp) {
		cmdTemp->close();
		cmdTemp->waitForFinished();
	}
	if (cmdLoad) {
		cmdLoad->close();
		cmdLoad->waitForFinished();
	}
}

// Button Events
/** @brief 今天按钮 */
void Widget::on_todayButton_clicked() {
	calendarSetToday();
}

/** @brief 刷新按钮 */
void Widget::on_refreshButton_clicked() {
    ui->weatherinfoLabel->setText("Refreshing...");
    ui->airInfoLabel->clear();
    ui->raininfoLabel->clear();

    indoorRequire();
    QThread::msleep(200);

    weatherRequire();
    rainRequire();
    airRequire();
}
void Widget::on_vwButton_clicked()
{
    VideoWidget *vw;
    vw = new VideoWidget(nullptr, this);
    vw->show();
    this->hide();
}

// Timer Events
/** @brief 定时器1槽函数 更新时间 */
void Widget::timer1Update() {
	updateTime();
}

/** @brief 定时器2槽函数 更新温度和负载 */
void Widget::timer2Update() {
	displayTemp(divideOS());
	displayLoad(divideOS());
    indoorRequire();
}
/** @brief 定时器3槽函数 更新天气 */
void Widget::timer3Update()
{
    rainRequire();
    if (++weatherTimerCount % 2 == 0) {
        weatherRequire();
    }
    if (weatherTimerCount % 5 == 0) {
        airRequire();
        calendarSetToday();
    }
    if (weatherTimerCount == 10) {
        weatherTimerCount = 0;
    }
}

// UI Events
/** @brief 更新显示时间 */
void Widget::updateTime() {
	// 获取当前时间并转换为字符串
	QString currentDate = QDateTime::currentDateTime().toString("MMM dd, yyyy  |  dddd");
	QString currentTime = QDateTime::currentDateTime().toString("HH:mm:ss");
	//显示时间的QLabel更新其文本
	ui->timeLabel->setText(currentTime);
	ui->dateLabel->setText(currentDate);
}
/** @brief 显示CPU温度 */
void Widget::displayTemp(char OS_TYPE) {
	switch (OS_TYPE) {
		case OS_WIN:cpuTemp = 55.467;
			break;
		case OS_LINUX:runShell(cmdTemp, OS_LINUX, "cat /sys/class/thermal/thermal_zone0/temp");
			break;
		default:break;
	}
	ui->lcdNumber->display((int)cpuTemp);
}
/** @brief 显示CPU负载 */
void Widget::displayLoad(char OS_TYPE) {
	switch (OS_TYPE) {
		case OS_WIN:loadDisplayText = "1.23 2.46 3.69";
			break;
		case OS_LINUX:runShell(cmdLoad, OS_LINUX, "cat /proc/loadavg | cut -d ' ' -f 1-3");
			loadDisplayText = QString::number(cpuLoad0) + " " + QString::number(cpuLoad1) + " "
				+ QString::number(cpuLoad2);
			break;
		default:break;
	}
	ui->cpuloadLabel->setText(loadDisplayText);
}
/** @brief 设置消息图片 */
void Widget::setMessagerImg(QPixmap pixmap) {
	// 按 QLabel 的尺寸缩放 pixmap，并保持宽高比
	QPixmap scaledPixmap = pixmap.scaled(ui->msgImgLabel->size(),
	                                     Qt::KeepAspectRatio,
	                                     Qt::SmoothTransformation);

	// 将缩放后的 pixmap 设置到 QLabel
	ui->msgImgLabel->setPixmap(scaledPixmap);
	ui->msgImgLabel->setAlignment(Qt::AlignCenter);
}
/** @brief 设置默认图片 */
void Widget::setDefaultImg() {
    QString imgPath = QCoreApplication::applicationDirPath() + QDir::separator()
                      + QString("default.png");
    setMessagerImg(QPixmap(imgPath));
}
/** @brief 设置日历为今天 */
void Widget::calendarSetToday() {
	ui->calendarWidget->setSelectedDate(QDate::currentDate());
}

// Network Events
// TcpServer: 30520 - Neko Messager
/** @brief 接受TCP30520连接 */
void Widget::acceptTcp30520() {
    QTcpSocket *socket = server30520->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Widget::handleTcp30520Recive);
    if (socket->peerAddress().toString() == "127.0.0.1") {
        ui->clientinfoLabel->setText("From Web  "
                                     // + ":" + QString::number(socket->peerPort())
                                     + QDateTime::currentDateTime().toString("HH:mm:ss"));
    } else {
        ui->clientinfoLabel->setText("From "
                                     + socket->peerAddress().toString()
                                     // + ":" + QString::number(socket->peerPort())
                                     + "  " + QDateTime::currentDateTime().toString("HH:mm:ss"));
    }
}
/** @brief 处理TCP30520接收 */
void Widget::handleTcp30520Recive()
{
    QTcpSocket *s = (QTcpSocket *)sender();
	ui->displayLabel->setText(QString(s->readAll()));
	s->write("Recieved");
}

// TcpClient: 30521 - Weather Server
/** @brief 处理TCP30521接收天气 */
void Widget::handleTcp30521ReciveWeather()
{
	QString msg = weatherSocket->readAll();
	qDebug() << "[INFO] Tcp Recieve: " + msg;
	QStringList weatherList = msg.split(" ");
	QString weatherType = weatherList[0];
	QString temperature = weatherList[1];
	QString humidity = weatherList[2];
	QString wind = weatherList[3];
	int weatherCode = weatherList[4].toInt();
	weatherImgUpdate(weatherCode);
    QString weatherMsg = weatherType + "  " + temperature + "°C  " + humidity + "%  " + wind;
    ui->weatherinfoLabel->setText(weatherMsg);
    // 湿度显示
    if (humidity.toInt() < 40) {
        ui->humiLcdNumber->setStyleSheet("background-color: sandybrown;");
    } else if (humidity.toInt() > 70) {
        ui->humiLcdNumber->setStyleSheet("background-color: turquoise;");
    } else {
        ui->humiLcdNumber->setStyleSheet("background-color: transparent;");
    }
    ui->humiLcdNumber->display(humidity);
    // 温度显示
    if (temperature.toInt() < 0) {
        ui->tempLcdNumber->setStyleSheet("background-color: dodgerblue;");
    } else if (temperature.toInt() < 15) {
        ui->tempLcdNumber->setStyleSheet("background-color: skyblue;");
    } else if (temperature.toInt() > 35) {
        ui->tempLcdNumber->setStyleSheet("background-color: orangered;");
    } else if (temperature.toInt() > 25) {
        ui->tempLcdNumber->setStyleSheet("background-color: coral;");
    } else {
        ui->tempLcdNumber->setStyleSheet("background-color: transparent;");
    }
    ui->tempLcdNumber->display(temperature);
    weatherSocket->disconnectFromHost();
}
/** @brief 处理TCP30521接收降水 */
void Widget::handleTcp30521ReciveRain()
{
	QString msg = rainSocket->readAll();
	qDebug() << "[INFO] Tcp Recieve: " + msg;
    // 降水信息显示
    if (msg.left(msg.size() - 1) == "未来两小时无降水") {
        ui->raininfoLabel_2->setStyleSheet("background-color: transparent;");
    } else {
        ui->raininfoLabel_2->setStyleSheet("background-color: gold;");
    }
    ui->raininfoLabel->setText(msg.left(msg.size() - 1));
    ui->raininfoLabel_2->setText(msg.left(msg.size() - 1));
    rainSocket->disconnectFromHost();
}
/** @brief 处理TCP30521接收空气 */
void Widget::handleTcp30521ReciveAir()
{
	QString msg = airSocket->readAll();
	qDebug() << "[INFO] Tcp Recieve: " + msg;
	QStringList airList = msg.split(" ");
	QString airQuality = airList[0];
	int airAQI = airList[1].toInt();
	QString primary = airList[2];

    if (primary == "NA") {
        ui->airInfoLabel->setText("空气" + airQuality + "  AQI " + QString::number(airAQI));
    } else {
        ui->airInfoLabel->setText("空气" + airQuality + "  主要为" + primary + "  AQI "
                                  + QString::number(airAQI));
    }
    // 空气质量显示
    if (airAQI < 50) {
        ui->airLcdNumber->setStyleSheet("background-color: springgreen;");
    } else if (airAQI < 100) {
        ui->airLcdNumber->setStyleSheet("background-color: transparent;");
    } else if (airAQI < 150) {
        ui->airLcdNumber->setStyleSheet("background-color: orange;");
    } else {
        ui->airLcdNumber->setStyleSheet("background-color: orangered;");
    }

    ui->airLcdNumber->display(airAQI);
    airSocket->disconnectFromHost();
}
/** @brief 处理TCP30521接收室内 */
void Widget::handleTcp30521ReciveIndoor()
{
    QString msg = indoorSocket->readAll();
    qDebug() << "[INFO] Tcp Recieve: " + msg;
    QStringList indoorList = msg.split(" ");
    float indoorTemp = indoorList[0].toFloat();
    int indoorHumi = indoorList[1].toInt();
    // 室内温度显示
    if (indoorTemp < 10) {
        ui->inTempLcdNumber->setStyleSheet("background-color: dodgerblue;");
    } else if (indoorTemp < 18) {
        ui->inTempLcdNumber->setStyleSheet("background-color: skyblue;");
    } else if (indoorTemp > 30) {
        ui->inTempLcdNumber->setStyleSheet("background-color: orangered;");
    } else if (indoorTemp > 23) {
        ui->inTempLcdNumber->setStyleSheet("background-color: coral;");
    } else {
        ui->inTempLcdNumber->setStyleSheet("background-color: transparent;");
    }
    ui->inTempLcdNumber->display(indoorList[0]);
    // 室内湿度显示
    if (indoorHumi < 40) {
        ui->inHumiLcdNumber->setStyleSheet("background-color: sandybrown;");
    } else if (indoorHumi > 70) {
        ui->inHumiLcdNumber->setStyleSheet("background-color: turquoise;");
    } else {
        ui->inHumiLcdNumber->setStyleSheet("background-color: transparent;");
    }
    ui->inHumiLcdNumber->display(indoorHumi);
    indoorSocket->disconnectFromHost();
}

// TcpServer: 30522 - Neko Messager Image
/** @brief 接受TCP30522连接 */
void Widget::acceptTcp30522()
{
    QTcpSocket *socket = server30522->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Widget::handleTcp30522Recive);
    imageBuffer.clear();
    imageSize = 0;
    qDebug() << "New Connection. ";
}
/** @brief 处理TCP30522接收 */
void Widget::handleTcp30522Recive()
{
    QTcpSocket *s = (QTcpSocket *) sender();
    if (imageSize == 0) {
        // 首先获取图片大小信息（假设客户端先发送图片大小）
        if (s->bytesAvailable() < sizeof(qint64)) {
            return; // 如果数据不足够读取图片大小，则等待更多数据
        }
        s->read(reinterpret_cast<char *>(&imageSize), sizeof(qint64)); // 读取图片大小
    }

    // 将接收到的数据追加到缓冲区
    imageBuffer.append(s->readAll());

    // 检查是否接收到了完整的图片
    if (imageBuffer.size() >= imageSize) {
        QImage image;
        image.loadFromData(imageBuffer); // 从缓冲区数据中加载图片

        if (!image.isNull()) {
            // 将 QImage 转换为 QPixmap
            QPixmap pixmap = QPixmap::fromImage(image);
	        setMessagerImg(pixmap);
        } else {
            qDebug() << "Failed to load image from data.";
        }

        imageBuffer.clear(); // 清空缓冲区，为接收下一张图片做准备
        imageSize = 0;       // 重置图片大小
    }
}

// Process
/** @brief 读取温度输出 */
void Widget::tempReadoutput() {
	cpuTemp = QString(cmdTemp->readAllStandardOutput()).toDouble() / 1000;
}

/** @brief 读取负载输出 */
void Widget::loadReadoutput() {
	QStringList list = QString(cmdLoad->readAllStandardOutput()).split(" ");
	cpuLoad0 = list[0].toDouble();
	cpuLoad1 = list[1].toDouble();
	cpuLoad2 = list[2].toDouble();
}
/** @brief 运行Shell命令 */
void Widget::runShell(QProcess *cmd, char OS_TYPE, QString command) {
	switch (OS_TYPE) {
		case OS_WIN:cmd->start("cmd");
			break;
		case OS_LINUX:cmd->start("bash");
			break;
		default:return;
	}
	cmd->waitForStarted();
	command = command + "\n";
	cmd->write(command.toLocal8Bit());
	cmd->waitForReadyRead();
	cmd->close();
	cmd->waitForFinished();
}

// Weather
/** @brief 请求天气 */
void Widget::weatherRequire() {
	weatherSocket = new QTcpSocket;
    weatherSocket->connectToHost(QHostAddress(WEATHERSERVERIP), 30521);
    connect(weatherSocket, &QTcpSocket::readyRead, this, &Widget::handleTcp30521ReciveWeather);
    weatherSocket->write(QString("weather").toUtf8());
    qDebug() << "[INFO] Weather required!";
}
/** @brief 请求雨情 */
void Widget::rainRequire()
{
	rainSocket = new QTcpSocket;
	rainSocket->connectToHost(QHostAddress(WEATHERSERVERIP), 30521);
	connect(rainSocket, &QTcpSocket::readyRead, this, &Widget::handleTcp30521ReciveRain);
	rainSocket->write(QString("rain").toUtf8());
	qDebug() << "[INFO] Rain required!";
}
/** @brief 请求空气质量 */
void Widget::airRequire()
{
	airSocket = new QTcpSocket;
	airSocket->connectToHost(QHostAddress(WEATHERSERVERIP), 30521);
	connect(airSocket, &QTcpSocket::readyRead, this, &Widget::handleTcp30521ReciveAir);
	airSocket->write(QString("air").toUtf8());
	qDebug() << "[INFO] Air required!";
}
/** @brief 请求室内 */
void Widget::indoorRequire()
{
    indoorSocket = new QTcpSocket;
    indoorSocket->connectToHost(QHostAddress(WEATHERSERVERIP), 30521);
    connect(indoorSocket, &QTcpSocket::readyRead, this, &Widget::handleTcp30521ReciveIndoor);
    indoorSocket->write(QString("indoor").toUtf8());
    qDebug() << "[INFO] Indoor required!";
}
/** @brief 更新天气图片 */
void Widget::weatherImgUpdate(int code)
{
    QString path = QDir::cleanPath(QCoreApplication::applicationDirPath() + QDir::separator()
                                   + QString("/weather_icons/") + QString::number(code)
                                   + QString("-fill.svg"));
    ui->weatherimgLabel->clear();
    // 获取当前的布局
    QLayout *layout = ui->weatherimgLabel->layout();

    // 如果没有布局，则创建一个新的QHBoxLayout
    if (!layout) {
        layout = new QHBoxLayout(ui->weatherimgLabel);
        layout->setContentsMargins(0, 0, 0, 0); // 设置边距为0
    }

    // 清除之前的QSvgWidget
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget(); // 删除布局项中的widget
        delete child;           // 删除布局项
    }

    // 创建新的QSvgWidget
    QSvgWidget *svg = new QSvgWidget(path);
    svg->setFixedSize(ui->weatherimgLabel->size());
    layout->addWidget(svg);

    svg->show();
}

// Other Functions
/** @brief 判断操作系统 */
char Widget::divideOS() {
#ifdef Q_OS_WIN
	return OS_WIN;
#endif
#ifdef Q_OS_LINUX
	return OS_LINUX;
#endif
#ifdef Q_OS_MAC
	return OS_MAC;
#endif
}
