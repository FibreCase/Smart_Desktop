/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *line_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *displayLabel;
    QLabel *clientinfoLabel;
    QLabel *msgImgLabel;
    QLCDNumber *humiLcdNumber;
    QLCDNumber *tempLcdNumber;
    QPushButton *refreshButton;
    QLabel *label_5;
    QLabel *label_6;
    QLCDNumber *airLcdNumber;
    QLabel *label_7;
    QLabel *raininfoLabel_2;
    QFrame *line_5;
    QLabel *weatherimgLabel;
    QFrame *line_3;
    QLCDNumber *inTempLcdNumber;
    QLabel *label_8;
    QLCDNumber *inHumiLcdNumber;
    QLabel *label_9;
    QLabel *label_4;
    QWidget *tab_3;
    QPushButton *vwButton;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QCalendarWidget *calendarWidget;
    QPushButton *todayButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *cpuloadLabel;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *timeLabel;
    QLabel *dateLabel;
    QFrame *line;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *weatherinfoLabel;
    QLabel *airInfoLabel;
    QLabel *raininfoLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1024, 600);
        Widget->setMinimumSize(QSize(1024, 600));
        Widget->setMaximumSize(QSize(1024, 600));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        Widget->setFont(font);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 130, 1001, 461));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        line_4 = new QFrame(tab);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(400, 80, 591, 20));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(400, 10, 591, 71));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        displayLabel = new QLabel(verticalLayoutWidget_3);
        displayLabel->setObjectName("displayLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(26);
        font1.setBold(false);
        displayLabel->setFont(font1);
        displayLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        displayLabel->setWordWrap(true);

        verticalLayout_5->addWidget(displayLabel);

        clientinfoLabel = new QLabel(verticalLayoutWidget_3);
        clientinfoLabel->setObjectName("clientinfoLabel");
        clientinfoLabel->setMinimumSize(QSize(0, 0));
        clientinfoLabel->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(false);
        clientinfoLabel->setFont(font2);
        clientinfoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(clientinfoLabel);

        msgImgLabel = new QLabel(tab);
        msgImgLabel->setObjectName("msgImgLabel");
        msgImgLabel->setGeometry(QRect(400, 100, 591, 311));
        msgImgLabel->setWordWrap(false);
        humiLcdNumber = new QLCDNumber(tab);
        humiLcdNumber->setObjectName("humiLcdNumber");
        humiLcdNumber->setGeometry(QRect(30, 120, 111, 61));
        humiLcdNumber->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        humiLcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        humiLcdNumber->setDigitCount(3);
        humiLcdNumber->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        humiLcdNumber->setProperty("intValue", QVariant(50));
        tempLcdNumber = new QLCDNumber(tab);
        tempLcdNumber->setObjectName("tempLcdNumber");
        tempLcdNumber->setGeometry(QRect(140, 10, 151, 91));
        tempLcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        tempLcdNumber->setDigitCount(3);
        tempLcdNumber->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        tempLcdNumber->setProperty("intValue", QVariant(16));
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(10, 360, 371, 51));
        refreshButton->setMinimumSize(QSize(0, 50));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 120, 51, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(30);
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 10, 81, 91));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(50);
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        airLcdNumber = new QLCDNumber(tab);
        airLcdNumber->setObjectName("airLcdNumber");
        airLcdNumber->setGeometry(QRect(210, 120, 111, 61));
        airLcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        airLcdNumber->setDigitCount(3);
        airLcdNumber->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        airLcdNumber->setProperty("intValue", QVariant(120));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(320, 120, 61, 61));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        raininfoLabel_2 = new QLabel(tab);
        raininfoLabel_2->setObjectName("raininfoLabel_2");
        raininfoLabel_2->setGeometry(QRect(10, 190, 371, 61));
        raininfoLabel_2->setFont(font);
        raininfoLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        raininfoLabel_2->setWordWrap(true);
        line_5 = new QFrame(tab);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(10, 240, 371, 16));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        weatherimgLabel = new QLabel(tab);
        weatherimgLabel->setObjectName("weatherimgLabel");
        weatherimgLabel->setGeometry(QRect(20, 10, 81, 81));
        line_3 = new QFrame(tab);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(7, 100, 371, 20));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        inTempLcdNumber = new QLCDNumber(tab);
        inTempLcdNumber->setObjectName("inTempLcdNumber");
        inTempLcdNumber->setGeometry(QRect(150, 260, 171, 91));
        inTempLcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        inTempLcdNumber->setSmallDecimalPoint(true);
        inTempLcdNumber->setDigitCount(3);
        inTempLcdNumber->setMode(QLCDNumber::Mode::Dec);
        inTempLcdNumber->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        inTempLcdNumber->setProperty("value", QVariant(20.199999999999999));
        inTempLcdNumber->setProperty("intValue", QVariant(20));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(320, 260, 51, 91));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        inHumiLcdNumber = new QLCDNumber(tab);
        inHumiLcdNumber->setObjectName("inHumiLcdNumber");
        inHumiLcdNumber->setGeometry(QRect(10, 290, 71, 61));
        inHumiLcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        inHumiLcdNumber->setDigitCount(3);
        inHumiLcdNumber->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        inHumiLcdNumber->setProperty("value", QVariant(40.000000000000000));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(80, 290, 51, 61));
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 260, 121, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(18);
        font5.setBold(false);
        label_4->setFont(font5);
        label_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        vwButton = new QPushButton(tab_3);
        vwButton->setObjectName("vwButton");
        vwButton->setGeometry(QRect(10, 10, 311, 61));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(580, 10, 411, 401));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(verticalLayoutWidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setMinimumSize(QSize(400, 0));
        calendarWidget->setMaximumSize(QSize(350, 16777215));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(18);
        font6.setBold(false);
        font6.setItalic(false);
        calendarWidget->setFont(font6);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);

        verticalLayout_3->addWidget(calendarWidget);

        todayButton = new QPushButton(verticalLayoutWidget);
        todayButton->setObjectName("todayButton");
        todayButton->setMinimumSize(QSize(80, 50));

        verticalLayout_3->addWidget(todayButton);

        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(290, 10, 281, 401));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lcdNumber = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setMinimumSize(QSize(100, 0));
        lcdNumber->setMaximumSize(QSize(200, 16777215));
        lcdNumber->setFrameShape(QFrame::Shape::NoFrame);
        lcdNumber->setDigitCount(3);

        horizontalLayout_2->addWidget(lcdNumber);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(40, 16777215));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial")});
        font7.setPointSize(24);
        font7.setBold(false);
        label_3->setFont(font7);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        cpuloadLabel = new QLabel(verticalLayoutWidget_2);
        cpuloadLabel->setObjectName("cpuloadLabel");

        horizontalLayout_3->addWidget(cpuloadLabel);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 250, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 332, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        timeLabel = new QLabel(layoutWidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMinimumSize(QSize(330, 60));
        timeLabel->setMaximumSize(QSize(330, 60));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Arial")});
        font8.setPointSize(48);
        font8.setBold(true);
        timeLabel->setFont(font8);

        verticalLayout_2->addWidget(timeLabel);

        dateLabel = new QLabel(layoutWidget);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setMinimumSize(QSize(0, 35));
        dateLabel->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(dateLabel);

        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 110, 1001, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        verticalLayoutWidget_4 = new QWidget(Widget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(360, 10, 651, 101));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        weatherinfoLabel = new QLabel(verticalLayoutWidget_4);
        weatherinfoLabel->setObjectName("weatherinfoLabel");
        weatherinfoLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_7->addWidget(weatherinfoLabel);

        airInfoLabel = new QLabel(verticalLayoutWidget_4);
        airInfoLabel->setObjectName("airInfoLabel");
        airInfoLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_7->addWidget(airInfoLabel);

        raininfoLabel = new QLabel(verticalLayoutWidget_4);
        raininfoLabel->setObjectName("raininfoLabel");
        raininfoLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_7->addWidget(raininfoLabel);

        raininfoLabel->raise();
        airInfoLabel->raise();
        weatherinfoLabel->raise();

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        displayLabel->setText(QCoreApplication::translate("Widget", "Say something.", nullptr));
        clientinfoLabel->setText(QCoreApplication::translate("Widget", "Wish you Good Morning, Good Afternoon and Good Night.", nullptr));
        msgImgLabel->setText(QString());
        refreshButton->setText(QCoreApplication::translate("Widget", "Refresh", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "%", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\302\260C", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "AQI", nullptr));
        raininfoLabel_2->setText(QCoreApplication::translate("Widget", "\351\231\215\346\260\264", nullptr));
        weatherimgLabel->setText(QCoreApplication::translate("Widget", "IMG", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\302\260C", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "%", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\256\244\345\206\205Indoor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "Home", nullptr));
        vwButton->setText(QCoreApplication::translate("Widget", "Extra APP 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Widget", "Extra", nullptr));
        todayButton->setText(QCoreApplication::translate("Widget", "Today", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Temp", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\302\260C", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Load", nullptr));
        cpuloadLabel->setText(QCoreApplication::translate("Widget", "0.00 0.00 0.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "SystemInfo", nullptr));
        timeLabel->setText(QCoreApplication::translate("Widget", "Time", nullptr));
        dateLabel->setText(QCoreApplication::translate("Widget", "Date  ", nullptr));
        weatherinfoLabel->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224", nullptr));
        airInfoLabel->setText(QCoreApplication::translate("Widget", "\347\251\272\346\260\224", nullptr));
        raininfoLabel->setText(QCoreApplication::translate("Widget", "\351\231\215\346\260\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
