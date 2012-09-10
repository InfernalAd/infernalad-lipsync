#include <QtGui/QApplication>
#include "mainwindow.h"
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainWidget w;
    w.show();
    
    return a.exec();
}
