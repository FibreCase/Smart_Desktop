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
    timer3->start(10 * 60 * SECOND);

    // QCalenderWidget
	ui->calendarWidget->setFirstDayOfWeek(Qt::Sunday);
	calendarSetToday();

	// QTabWidget
	setStyleSheet(QString("QTabBar::tab{height:40;width:%1}").arg(ui->tabWidget->width() / 3));

	// QTcpServer
	server = new QTcpServer;
	server->listen(QHostAddress("0.0.0.0"), 30520);
	connect(server, &QTcpServer::newConnection, this, &Widget::acceptTcp30520);

	// QProcess
	cmdTemp = new QProcess;
	connect(cmdTemp, &QProcess::readyReadStandardOutput, this, &Widget::tempReadoutput);
	cmdLoad = new QProcess;
	connect(cmdLoad, &QProcess::readyReadStandardOutput, this, &Widget::loadReadoutput);

	// QTextBrowser
	ui->htmlBrowser->setOpenExternalLinks(true);

	// Weather
	weatherRequire();
	rainRequire();
	airRequire();
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
/** @brief 关闭按钮 */
void Widget::on_pushButton_clicked() {
	this->close();
}

/** @brief 今天按钮 */
void Widget::on_todayButton_clicked() {
	calendarSetToday();
}

/** @brief 刷新按钮 */
void Widget::on_refreshButton_clicked() {
	// displayText();
	weatherRequire();
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
}
/** @brief 定时器3槽函数 更新天气 */
void Widget::timer3Update() {
	weatherRequire();
}

/** @brief 更新显示时间 */
void Widget::updateTime() {
	// 获取当前时间并转换为字符串
	QString currentDate = QDateTime::currentDateTime().toString("MMM dd, yyyy  |  dddd");
	QString currentTime = QDateTime::currentDateTime().toString("HH:mm:ss");
	//显示时间的QLabel更新其文本
	ui->timeLabel->setText(currentTime);
	ui->dateLabel->setText(currentDate);
}

/** @brief 显示温度 */
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

/** @brief 显示负载 */
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

// Network Events
/** @brief 接受TCP连接 */
void Widget::acceptTcp30520() {
	QTcpSocket *socket = server->nextPendingConnection();
	connect(socket, &QTcpSocket::readyRead, this, &Widget::handleTcp30520Recive);
	// 获取客户端信息
	// socket->peerAddress();
	// socket->peerPort();
	if (socket->peerAddress().toString() == "127.0.0.1") {
		ui->clientinfoLabel->setText("From Web  "
			                             // + ":" + QString::number(socket->peerPort())
			                             + QDateTime::currentDateTime().toString("HH:mm:ss"));
	}
	else {
		ui->clientinfoLabel->setText("From "
			                             + socket->peerAddress().toString()
				                             // + ":" + QString::number(socket->peerPort())
			                             + "  " + QDateTime::currentDateTime().toString("HH:mm:ss"));
	}
}

/** @brief 处理TCP接收 */
void Widget::handleTcp30520Recive() {
	QTcpSocket *s = (QTcpSocket *)sender();
	ui->displayLabel->setText(QString(s->readAll()));
	s->write("Recieved");
}
/** @brief 处理TCP30521接收 */
void Widget::handleTcp30521ReciveWeather()
{
    QString msg = weatherSocket->readAll();
    qDebug() << "[INFO] Tcp Recieve: " + msg;
    QStringList weatherList = msg.split(" ");
    QString weatherType = weatherList[0];
    QString temperature = weatherList[1];
    QString wind = weatherList[2];
    int weatherCode = weatherList[3].toInt();
    weatherImgUpdate(weatherCode);
    QString weatherMsg = weatherType + "  " + temperature + "  " + wind;
    ui->weatherinfoLabel->setText(weatherMsg);
    weatherSocket->disconnectFromHost();
}
/** @brief 处理TCP30521接收 */
void Widget::handleTcp30521ReciveRain()
{
	QString msg = rainSocket->readAll();
	qDebug() << "[INFO] Tcp Recieve: " + msg;
	ui->raininfoLabel->setText(msg);
	rainSocket->disconnectFromHost();
}
/** @brief 处理TCP30521接收 */
void Widget::handleTcp30521ReciveAir()
{
	QString msg = airSocket->readAll();
	qDebug() << "[INFO] Tcp Recieve: " + msg;
	QStringList airList = msg.split(" ");
	QString airQuality = airList[0];
	int airAQI = airList[1].toInt();
    ui->airinfoLabel->setText("空气质量：" + airQuality + "  AQI：" + QString::number(airAQI));
    airSocket->disconnectFromHost();
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

// TextBrowser
/** @brief 显示文本 */
void Widget::displayText() {
	const QString qstr_file_name = QFileDialog::getOpenFileName(this,
	                                                            "选择HTML文件",
	                                                            "",
	                                                            "HTML Files (*.html)");
	if (qstr_file_name.isEmpty()) {
		return;
	}
	ui->htmlBrowser->clear();
	ui->htmlBrowser->setSource(QUrl::fromLocalFile(qstr_file_name));
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
/** @brief 更新天气图片 */
void Widget::weatherImgUpdate(int code) {
    QString path = QDir::cleanPath(QCoreApplication::applicationDirPath() + QDir::separator()
                                   + QString("/weather_icons/") + QString::number(code)
                                   + QString("-fill.svg"));
    QPixmap img(path);
    ui->weatherimgLabel->setPixmap(img.scaled(ui->weatherimgLabel->size()));
    ui->weatherimgLabel->show();

    // QString svg_path = QSvgRenderer svg_remder(folder_icon_path);
    // QSize label_size = ui->label->size(); //取控件的大小即可
    // QImage image(QSize(label_size.width() * g_fGlobalDPI, label_size.height() * g_fGlobalDPI),
    //              QImage::Format_ARGB32_Premultiplied);
    // 输出的img一定要是拉伸dpi倍数之后尺寸 img.fill(Qt::transparent);
    // QPainter painter(&image);
    // painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing
    //                        | QPainter::SmoothPixmapTransform);
    // svg_remder.render(&painter);
    // QPixmap pix;
    // pix = pix.fromImage(image);
    // pix.setDevicePixelRatio(g_fGlobalDPI);
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

/** @brief 设置日历为今天 */
void Widget::calendarSetToday() {
	ui->calendarWidget->setSelectedDate(QDate::currentDate());
}
