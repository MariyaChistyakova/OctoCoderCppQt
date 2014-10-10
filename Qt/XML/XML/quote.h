#ifndef QUOTE_H
#define QUOTE_H

#include <QWidget>
#include <QtXml>
#include <QFile>

class quote : public QWidget
{
    Q_OBJECT

public:
    quote(QFile* file);
    void traverseNode(const QDomNode& node);

};

#endif // QUOTE_H
