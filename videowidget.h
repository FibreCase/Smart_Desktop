#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>

class Widget; // 前向声明，避免头文件循环包含

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = nullptr, Widget *parentWidget = nullptr);
    ~VideoWidget();

private slots:
    void on_pushButton_clicked(); // 按钮点击槽函数

private:
    Ui::VideoWidget *ui;
    Widget *parentWindow; // 保存父窗口指针
};

#endif // VIDEOWIDGET_H
