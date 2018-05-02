#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "starting application" << endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
