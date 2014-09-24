#include "myclient.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient w("localhost",2323);
    w.show();
    QTimer::singleShot(1 * 60 * 1000, &w, SLOT(timer()));
    return a.exec();
}
