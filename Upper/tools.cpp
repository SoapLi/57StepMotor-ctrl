#include "tools.h"
#include <QProcess>
#include <QMutex>
#include <QDate>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
tools::tools()
{


}

 QString tools::ByteArrayToHexString(QByteArray &ba)
 {
     QDataStream out(&ba,QIODevice::ReadWrite);
     QString buf;
     while(!out.atEnd())
     {
         qint8 outChar = 0;
         out >> outChar;
         QString str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0')).toUpper() + QString(" ");
         buf += str;
     }
     return buf;
 }

 QString tools::WmicGetByCmd(QString cmd)
 {
     QProcess p;
     p.start(cmd);
     p.waitForFinished();
     QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
     QStringList list = cmd.split(" ");
     result = result.remove(list.last(), Qt::CaseInsensitive);
     result = result.replace("\r", "");
     result = result.replace("\n", "");
     result = result.simplified();
     return result;
 }


void tools::WriteLogsToFile(QString content)
{
    QDateTime da_time;
    QString time_str=da_time.currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString runPath = QCoreApplication::applicationFilePath();

    QDir *TEST = new QDir;
    bool exist = TEST->exists("LIST");
    if(!exist)
         bool ok = TEST->mkdir("LIST");
    QString fileName = "LIST/list.txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
    {

      qDebug("file fail");
    }
    QTextStream in(&file);
    in<<":"+content<<"\n";
    file.close();
}

QString tools::getXORresult(QString str1, QString str2,int len)
{
    QString result;
    QByteArray bs1 = str1.toLatin1();
    QByteArray bs2 = str2.toLatin1();
    int size = bs1.size();
    int size2 = bs2.size();
    if(size != size2)
    {
        for(int i=0; i<len; i++)
        {
            bs1[i] = bs1[i] ^ bs2[i];
        }
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            bs1[i] = bs1[i] ^ bs2[i];
        }
    }
    return result.prepend(bs1);
}







