#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextBrowser>
#include <QTextStream>
#include <QTimer>
#include <QWidget>

#define SECOND 1 * 1000

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
    void on_pushButton_clicked();
    void on_todayButton_clicked();
    void on_refreshButton_clicked();

    // Slots of TcpServer
    void acceptTcp30520();
    void handleTcp30520Recive();
    void handleTcp30521Recive();

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
    QTcpServer *server;
    QTcpSocket *socket;
    QTcpSocket *weatherSocket;
    QProcess *cmdTemp;
    QProcess *cmdLoad;

    double cpuTemp;
    double cpuLoad0;
    double cpuLoad1;
    double cpuLoad2;
    QString loadDisplayText;

    void displayText();
    void updateTime();
    char divideOS();
    void calendarSetToday();
    void displayTemp(char OS_TYPE);
    void displayLoad(char OS_TYPE);
    void weatherRequire();
    void weatherImgUpdate(int code);
    void runShell(QProcess *cmd, char OS_TYPE, QString command);
};
#endif // WIDGET_H
