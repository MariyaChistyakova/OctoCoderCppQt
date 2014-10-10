#include "quote.h"
#include "createrxml.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreaterXML xml(1,3,5);
    QFile file("Quote.xml");
    if(file.open(QIODevice::WriteOnly)) {
    QTextStream(&file) << xml.doc.toString();
    file.close();
    }
    quote q(&file);
    return a.exec();
}
