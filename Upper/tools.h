#ifndef TOOLS_H
#define TOOLS_H
#include <QString>
#include <QTextStream>
#include <QDataStream>
class tools
{
public:
    tools();
    static QString ByteArrayToHexString(QByteArray &ba);
    static QString WmicGetByCmd (QString cmd);
    static void WriteLogsToFile(QString content);
    static QString getXORresult(QString str1, QString str2,int len);
};

#endif // TOOLS_H
