#ifndef CREATERXML_H
#define CREATERXML_H

#include <QtXml>
#include <QFile>

class CreaterXML
{
public:
    QFile file;
    QDomDocument doc;
public:
    CreaterXML(int a, int b, int c);
    QDomElement  makeElement( QDomDocument& domDoc, QString& strName,  int& type);
};

#endif // CREATERXML_H
