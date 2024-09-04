#include "widget.h"

#include <QApplication>
#include <QStyle>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOverrideCursor(Qt::BlankCursor);
    // QApplication::setStyle(QStyleFactory::create("WindowsVista"));
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    Widget w;
    w.show();
    return a.exec();
}
