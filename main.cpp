#include "layout.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

QString readTextFile(QString path)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }
    return "";
}
#include<QStackedWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Layout w;

   QString css = readTextFile(":/Style/Style/qss.qss");

    a.setStyleSheet(css);

    w.setWindowFlags(  Qt::WindowMinimizeButtonHint  | Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint );
    w.setWindowTitle("FindLy");
    w.show();
    w.setFixedSize(700,400);
    return a.exec();
}
