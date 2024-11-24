/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName("VideoWidget");
        VideoWidget->resize(1024, 600);
        VideoWidget->setMinimumSize(QSize(1024, 600));
        VideoWidget->setMaximumSize(QSize(1024, 600));
        pushButton = new QPushButton(VideoWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 71, 41));
        QFont font;
        font.setPointSize(22);
        pushButton->setFont(font);

        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QCoreApplication::translate("VideoWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("VideoWidget", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
