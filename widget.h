#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QRegExp>
#include <QStringList>
#include <QSvgRenderer>
#include <QSvgWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextBrowser>
#include <QTextStream>
#include <QThread>
#include <QTimer>
#include <QWidget>

#include <videowidget.h>

#define SECOND 1 * 1000
#define MINUTE 60 * SECOND
#define HOUR 60 * MINUTE

#define WEATHERSERVERIP "127.0.0.1"

#define OS_WIN 1
#define OS_LINUX 2
#define OS_MAC 3

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    // Slots of Button
    void on_todayButton_clicked();
    void on_refreshButton_clicked();
    void on_vwButton_clicked();

    // Slots of TcpServer
    void acceptTcp30520();
    void handleTcp30520Recive();
    void acceptTcp30522();
    void handleTcp30522Recive();
    void handleTcp30521ReciveWeather();
    void handleTcp30521ReciveRain();
	void handleTcp30521ReciveAir();

    // Slots of Timer
    void timer1Update();
    void timer2Update();
    void timer3Update();

    // Slots of Process
    void tempReadoutput();
    void loadReadoutput();

private:
    Ui::Widget *ui;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTcpServer *server30520;
    QTcpServer *server30522;
    QTcpSocket *socket;
    QTcpSocket *weatherSocket;
    QTcpSocket *rainSocket;
	QTcpSocket *airSocket;
    QProcess *cmdTemp;
    QProcess *cmdLoad;
    QByteArray imageBuffer;
    qint64 imageSize;

    qint8 weatherTimerCount;
    double cpuTemp;
    double cpuLoad0;
    double cpuLoad1;
    double cpuLoad2;
    QString loadDisplayText;
	void setMessagerImg(QPixmap pixmap);
	void setDefaultImg();

    void updateTime();
    char divideOS();
    void calendarSetToday();
    void displayTemp(char OS_TYPE);
    void displayLoad(char OS_TYPE);
    void weatherRequire();
    void rainRequire();
	void airRequire();
    void weatherImgUpdate(int code);
    void runShell(QProcess *cmd, char OS_TYPE, QString command);
};

#endif // WIDGET_H
