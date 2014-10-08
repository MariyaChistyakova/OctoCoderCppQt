#include "myclient.h"
#include <QApplication>
#include <QObject>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient* w = new MyClient ("localhost",2323);
    w->show();

    //QTimer::singleShot(1 * 60 * 1000, &w, SLOT(timer()));

    QTimer* ptimer = new QTimer(w);

    ptimer->start(5*60*1000);
    a.connect(ptimer, SIGNAL(timeout()),w, SLOT(timer()));
    return a.exec();
}
