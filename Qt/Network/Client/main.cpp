#include <QApplication>
#include "MyClient.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>
 #include <QApplication>

int main(int argc, char** argv)
{
 QApplication app(argc, argv);
 MyClient client("localhost", 2323);

 client.show();


 return app.exec();
}
