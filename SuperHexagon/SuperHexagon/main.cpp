#include "mainwindow.h"
#include <QApplication>

#include <QFontDatabase>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int fontID = QFontDatabase::addApplicationFont(":/other/resource/bumpitup.ttf");
    QString fontString = QFontDatabase::applicationFontFamilies(fontID).at(0);
    QFont font(fontString);
    QApplication::setFont(font);

    MainWindow w;
    w.show();
    return a.exec();
}
