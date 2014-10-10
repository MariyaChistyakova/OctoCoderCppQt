#include "createrxml.h"

CreaterXML::CreaterXML(int a,int b, int c)
{
    //doc.setPrefix("MyXML");
    QDomElement domElement = doc.createElement("Quotes");
    doc.appendChild(domElement);

    QString name = "Quote";

    QDomElement quote1 = makeElement(doc, name ,a);
    QDomElement quote2 = makeElement(doc, name,b);
    QDomElement quote3 = makeElement(doc, name,c);

    domElement.appendChild(quote1);
    domElement.appendChild(quote2);
    domElement.appendChild(quote3);


}

QDomElement CreaterXML:: makeElement( QDomDocument& domDoc, QString& strName,  int& type)
{
    QDomElement domElement = domDoc.createElement(strName);
    QDomAttr domAttr = domDoc.createAttribute("type");
    domAttr.setValue(QString().setNum(type));
    domElement.setAttributeNode(domAttr);
    return domElement;
}
