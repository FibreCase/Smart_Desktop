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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *todayButton;
    QPushButton *refreshButton;
    QFrame *line_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *displayLabel;
    QLabel *clientinfoLabel;
    QTextBrowser *htmlBrowser;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *timeLabel;
    QLabel *dateLabel;
    QFrame *line;
    QLabel *weatherimgLabel;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *weatherstatusLabel;
    QLabel *weatherinfoLabel;

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
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(960, 10, 51, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(14);
        pushButton->setFont(font1);
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
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 402, 401));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(layoutWidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setMinimumSize(QSize(400, 0));
        calendarWidget->setMaximumSize(QSize(350, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        calendarWidget->setFont(font2);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);

        verticalLayout->addWidget(calendarWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        todayButton = new QPushButton(layoutWidget);
        todayButton->setObjectName("todayButton");
        todayButton->setMinimumSize(QSize(80, 50));

        horizontalLayout->addWidget(todayButton);

        refreshButton = new QPushButton(layoutWidget);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(refreshButton);


        verticalLayout->addLayout(horizontalLayout);

        line_4 = new QFrame(tab);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(420, 80, 571, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(420, 10, 571, 71));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        displayLabel = new QLabel(verticalLayoutWidget_3);
        displayLabel->setObjectName("displayLabel");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(26);
        font3.setBold(false);
        displayLabel->setFont(font3);
        displayLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(displayLabel);

        clientinfoLabel = new QLabel(verticalLayoutWidget_3);
        clientinfoLabel->setObjectName("clientinfoLabel");
        clientinfoLabel->setMinimumSize(QSize(0, 0));
        clientinfoLabel->setMaximumSize(QSize(16777215, 20));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        font4.setBold(false);
        clientinfoLabel->setFont(font4);
        clientinfoLabel->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_5->addWidget(clientinfoLabel);

        htmlBrowser = new QTextBrowser(tab);
        htmlBrowser->setObjectName("htmlBrowser");
        htmlBrowser->setGeometry(QRect(420, 100, 571, 311));
        htmlBrowser->setFont(font4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(310, 10, 681, 401));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(tab_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(3, 10, 291, 401));
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
        lcdNumber->setDigitCount(3);

        horizontalLayout_2->addWidget(lcdNumber);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(40, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(24);
        font5.setBold(false);
        label_3->setFont(font5);

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
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 402, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        timeLabel = new QLabel(layoutWidget1);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMinimumSize(QSize(400, 60));
        timeLabel->setMaximumSize(QSize(400, 60));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(48);
        font6.setBold(true);
        timeLabel->setFont(font6);

        verticalLayout_2->addWidget(timeLabel);

        dateLabel = new QLabel(layoutWidget1);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setMinimumSize(QSize(0, 35));
        dateLabel->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(dateLabel);

        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 110, 1001, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        weatherimgLabel = new QLabel(Widget);
        weatherimgLabel->setObjectName("weatherimgLabel");
        weatherimgLabel->setGeometry(QRect(420, 10, 100, 100));
        weatherimgLabel->setMinimumSize(QSize(100, 100));
        weatherimgLabel->setMaximumSize(QSize(100, 100));
        verticalLayoutWidget_4 = new QWidget(Widget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(530, 20, 381, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        weatherstatusLabel = new QLabel(verticalLayoutWidget_4);
        weatherstatusLabel->setObjectName("weatherstatusLabel");

        verticalLayout_6->addWidget(weatherstatusLabel);

        weatherinfoLabel = new QLabel(verticalLayoutWidget_4);
        weatherinfoLabel->setObjectName("weatherinfoLabel");

        verticalLayout_6->addWidget(weatherinfoLabel);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "EXIT", nullptr));
        todayButton->setText(QCoreApplication::translate("Widget", "Today", nullptr));
        refreshButton->setText(QCoreApplication::translate("Widget", "Refresh", nullptr));
        displayLabel->setText(QCoreApplication::translate("Widget", "Say something.", nullptr));
        clientinfoLabel->setText(QCoreApplication::translate("Widget", "Wish you Good Morning, Good Afternoon and Good Night.", nullptr));
        htmlBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<h1 style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700;\">Good Day! </span></h1>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\350\277\231\346\230\257FibreCase\347\232\204\346\231\272\350\203\275\346\241\214\351\235\242 </span></p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-lef"
                        "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700;\">FibreCase</span></h3></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "Calendar", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Temp", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\302\260C", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Load", nullptr));
        cpuloadLabel->setText(QCoreApplication::translate("Widget", "0.00 0.00 0.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "SystemInfo", nullptr));
        timeLabel->setText(QCoreApplication::translate("Widget", "Time", nullptr));
        dateLabel->setText(QCoreApplication::translate("Widget", "Date  ", nullptr));
        weatherimgLabel->setText(QCoreApplication::translate("Widget", "PNG", nullptr));
        weatherstatusLabel->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224\345\246\202\344\275\225\357\274\237", nullptr));
        weatherinfoLabel->setText(QCoreApplication::translate("Widget", "Weather", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
