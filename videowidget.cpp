#include "videowidget.h"
#include "ui_videowidget.h"
#include "widget.h" // 引入主窗口类

VideoWidget::VideoWidget(QWidget *parent, Widget *parentWidget)
    : QWidget(parent)
    , ui(new Ui::VideoWidget)
    , parentWindow(parentWidget) // 保存父窗口指针
{
    ui->setupUi(this);
}

VideoWidget::~VideoWidget()
{
    delete ui;
}

void VideoWidget::on_pushButton_clicked()
{
    if (parentWindow) {
        parentWindow->show(); // 显示主窗口
    }
    this->close(); // 关闭当前窗口
}
