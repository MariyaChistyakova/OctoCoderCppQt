#include "quote.h"
#include "ui_quote.h"
#include <QLabel>

quote::quote(QFile* file)
{
   QDomDocument domDoc;

    if(file->open(QIODevice::ReadOnly)) {
    if(domDoc.setContent(file)) {
    QDomElement domElement= domDoc.documentElement();
    traverseNode(domElement);
    }
    file->close();
    }
}

void quote:: traverseNode(const QDomNode& node){
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()) {
    if(domNode.isElement()) {
    QDomElement domElement = domNode.toElement();
    if(!domElement.isNull()) {
    if(domElement.tagName() == "Quote") {
    int a = domElement.attribute("type","").toInt();
    switch(a){
     case 1:
        qDebug() << "Я помню чудное мгновенье: Передо мной явилась ты, Как мимолетное виденье, Как гений чистой красоты.";
        break;
     case 2:
        qDebug() << "Белеет парус одинокой. В тумане моря голубом!";
        break;
    case 3:
       qDebug() << "А вы ноктюрн сыграть смогли бы на флейте водосточных труб?";
       break;
    case 4:
       qDebug() << "Скажи-ка, дядя, ведь не даром. Москва, спаленная пожаром, Французу отдана?";
       break;
    case 5:
       qDebug() << "Я к вам пишу – чего же боле? Что я могу еще сказать?";
       break;
    }
    }
    }
    }
    domNode = domNode.nextSibling();
    traverseNode(domNode);
    }
}
