#ifndef HISTORY_METHOD_H
#define HISTORY_METHOD_H
#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QtXml>

class history_method
{
public:
    static void history(QString expression,QString result);
};

#endif // HISTORY_METHOD_H
