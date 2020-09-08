#include "datamenu.h"
#include "ui_datamenu.h"
#include <QDateTime>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtMath>
#include "GloableData/gloabledata.h"
#include "GloableData/datatype.h"
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <stdlib.h>
#include "string.h"
#include "qt_windows.h"
#include <QVariant>
#include <QDebug>
#include <QScrollBar>
#include <QSettings>
#include <QFileDialog>
#include <QSettings>
#include "macro_define.h"
#include <QApplication>
#include <QScreen>
#include <QInputDialog>
#include "tools.h"
#include "tea123.h"
#include <QProcess>
#include <QTextCodec>
#include <ctime>
//#include <QHostAddress>
//#include <QNetworkInterface>
//#include <QNetworkAddressEntry>

DataMenu::DataMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMenu)
{
    ui->setupUi(this);
    initSerialPortBox();
    ack_flag = 0;
    QRegExp regExp("[a-fA-F0-9]{4}");
    ui->lineEdit_addr_read->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_addr_read->setPlaceholderText("e.g. A1/a1");
    ui->lineEdit_addr_write->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_addr_write->setPlaceholderText("e.g. A1/a1");
    ui->lineEdit_value_write->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_value_write->setPlaceholderText("e.g. A1/a1");

    ui->progressBar->setMinimum(0);  // 最小值
    ui->progressBar->setMaximum(255);  // 最大值
    ui->progressBar->setValue(0);  // 当前进度
    ui->label_img->resize(191, 81);
    //ui->label_img->move(0, 0);
    ui->label_img->setAlignment(Qt::AlignCenter);
    ui->label_img->setScaledContents(true);
    //我这边两个接口都调用，但是最后调用的setPixmap覆盖了setText
    ui->label_img->setText("This is pixmap");
  //  ui->label_img->setPixmap(QPixmap("C:/PRJ/1.png"));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}




DataMenu::~DataMenu()
{
    delete ui;
}

void DataMenu::serialPlcReciveMannage()
{
    QByteArray temp = GloableData::GetInstance()->serial->readAll();
    qDebug()<<"recv :"<<QString(temp);
    ui->textEdit->append("["+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")+"]"+"ACK -> "+QString(temp));
    ui->textEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
    ack_flag = 0;
}

void DataMenu::initSerialPortBox()
{
    auto portsPlc = QSerialPortInfo::availablePorts();
    for (auto portPlc : portsPlc)
    {
        ui->portCbx_plc->addItem(portPlc.portName());
    }
    QList<int> rateListPlc;
    rateListPlc  << 230400 << 115200 << 19200 << 9600;
    for (auto ratePlc : rateListPlc)
    {
        ui->rateCbx_plc->addItem(QString::number(ratePlc));
    }
}

bool DataMenu::initPlcSerialService()
{
    this->serial = new QSerialPort;
    serial->setPortName(ui->portCbx_plc->currentText());
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(ui->rateCbx_plc->currentText().toInt());
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(NULL != GloableData::GetInstance()->serial)
    {
        return true;
    }
    if(!serial->isOpen())
    {
        QMessageBox::about(NULL, "warnning", QString("open fail"));
        ui->textEdit->append("COM open fail");
        return false;
    }
    ui->textEdit->append(ui->portCbx_plc->currentText()+" open success！");
    ui->textEdit->append("Master MCU0 conneted.");
    GloableData::GetInstance()->serial= serial;
    connect(GloableData::GetInstance()->serial, SIGNAL(readyRead()), this, SLOT(serialPlcReciveMannage()));


    return true;
}


void DataMenu::reqHeartBeats()
{

    unsigned char sentDataDES0[BLOCK_SIZE+1] = {0};
    unsigned char sentDataUnixTime[4] = {};
    uint time = QDateTime::currentDateTime().toTime_t();
    sentDataUnixTime[0]  = (unsigned char)(0x000000ff & time);
    sentDataUnixTime[1]  = (unsigned char)((0x0000ff00 & time) >> 8);
    sentDataUnixTime[2]  = (unsigned char)((0x00ff0000 & time) >> 16);
    sentDataUnixTime[3]  = (unsigned char)((0xff000000 & time) >> 24);
    for(int i=0;i<28;i++)
    {
        sentDataDES0[i] = sentDataUnixTime[i%4];
    }
    TEA123::btea_encrypt(sentDataDES0,TEA_key0);
    QByteArray sentData ;
    sentData.resize(34);
    sentData[0] = 0x11;
    for(int j=1;j<33;j++) {
        sentData[j] = sentDataDES0[j-1];
    }
    sentData[33] = 0x0D;
    sentData[34] = 0x0A;
    this->serial->write(sentData);
}

void DataMenu::on_pushButtonUsartStart_clicked()
{
    if(GET_DEV_ID_MODE)
    {
        QMessageBox::about(NULL, "warnning", QString("permission denied"));
        return;
    }
    initPlcSerialService();
}

void DataMenu::on_pushButton_Test_clicked()
{

}

void DataMenu::on_pushButton_GetDevId_clicked()
{
    QString strXORKey = "huang135792468s15769236086liasdfghjklzxcvbnmqwertyhgfd";
    QString cpuName  = tools::WmicGetByCmd("wmic cpu get name");
    //ui->textEdit->append(cpuName);
    //tools::WriteLogsToFile(cpuName);
    QString cpuId  = tools::WmicGetByCmd("wmic cpu get processorid");
    //ui->textEdit->append(cpuId);
    //tools::WriteLogsToFile(cpuId);
    QString diskId  = tools::WmicGetByCmd("wmic diskdrive where index=0 get serialnumber");
    //ui->textEdit->append(diskId);
    //tools::WriteLogsToFile(diskId);
    uint time = QDateTime::currentDateTime().toTime_t();
    //ui->textEdit->append(QString::number(time));
    // tools::WriteLogsToFile(QString::number(time));
    QString baseStr = QString::number(time-200*qrand())+"_"+cpuName+"_"+QString::number(time-600*qrand())+"_"+cpuId+"_"+QString::number(time-900*qrand())+"_"+diskId+"_"+QString::number(time);
    // qDebug()<<baseStr;
    //1.xor with base key
    QString baseStrXOR = tools::getXORresult(baseStr, strXORKey,strXORKey.size());
    //qDebug()<<baseStrXOR;
    //2.encrypt
    QByteArray encryptByteArray = baseStrXOR.toLocal8Bit().toBase64();
    QString encryptStr = QString(encryptByteArray);
    //qDebug()<<encryptStr;
    if(encryptStr.size()<100)
    {
        QMessageBox::about(NULL, "warnning", QString("pls try again!"));
        return;
    }
    tools::WriteLogsToFile(encryptStr);
    ui->textEdit->append(encryptStr);
    //3.decrypt
    QString ts = "WUBZV1MDBAEPCW19WEwWXR1lHxlqVlleEGRFSTEfBRIOBh8GTEJKVU8hN00yJzBSNFlaSVNUR0h6XzE1NzcyMDUwODBfMEY4QkZCRkYwMDA1MDY1N18xNTg0NDg5NjgwXzJ6ZWg2am1iZWZqMHpteXFmcXhtXzE1OTQ4MTk4ODA=";
    QString decryptStr = QTextCodec::codecForName("GBK")->toUnicode(QByteArray::fromBase64(ts.toLocal8Bit()));
    qDebug()<<decryptStr;
    //4.xor with base key
    QString result = tools::getXORresult(decryptStr, strXORKey,strXORKey.size());
    qDebug()<<result;
    QMessageBox::about(NULL, "msg", QString("success!"));
    QApplication* app;
    app->exit(0);
}

#define APP_APTH "C:\\Users\\LJH\\Desktop\\code\\WindowsFormsApp1.exe"
#define APP_CPUID "BFEBFBFF000806EA"
#define APP_USE_SK1 "1"

void DataMenu::on_pushButtonStart_clicked()
{
    QStringList arguments;
    QString program = APP_APTH;
    //args[0]:cpuid
    //args[1]:cur unix time
    //args[2]:para for alg
    arguments << APP_CPUID << QString::number(QDateTime::currentDateTime().toTime_t()) << APP_USE_SK1;
    QProcess *process = new QProcess(this);
    process->start(program, arguments);
}

void DataMenu::on_pushButton_home_clicked()
{
    this->serial->write("home\r\n");
}

void DataMenu::on_pushButton_park_clicked()
{
    this->serial->write("park\r\n");
}

void DataMenu::on_pushButton_next_clicked()
{
    this->serial->write("next\r\n");

}

void DataMenu::on_pushButton_pos_clicked()
{
    QString xx =  "pos "+ui->lineEdit_boat->text()+" "+ui->lineEdit_col->text()+" "+ui->lineEdit_row->text()+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}


void DataMenu::on_pushButton_res_clicked()
{

}

void DataMenu::on_pushButton_readconfig_clicked()
{
    // QString::number(ui->lineEdit_addr_read->text().toInt(NULL, 16), 10)
    QString xx =  "rc "+QString::number(ui->lineEdit_addr_read->text().toInt(NULL, 16), 10)+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}

void DataMenu::on_pushButton_writeconfig_clicked()
{
    QString xx =  "wc "+QString::number(ui->lineEdit_addr_write->text().toInt(NULL, 16), 10)+" "+QString::number(ui->lineEdit_value_write->text().toInt(NULL, 16), 10)+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}

void DataMenu::on_pushButton_writeconfig_2_clicked()
{
on_pushButton_fwd_clicked();
    this->timer->start(2000);
   // ui->progressBar->setValue(0);
}

void DataMenu::handleTimeout()
{

    // QString::number(ui->lineEdit_addr_read->text().toInt(NULL, 16), 10)
    QString xx =  "rc "+QString::number(ui->lineEdit_addr_read->text().toInt(NULL, 16), 10)+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
  this->timer->stop();
//    QString xx;
//    static int i = 0;
//    xx =  "wc "+QString::number(i, 10)+" "+QString::number(ui->lineEdit_value_write->text().toInt(NULL, 16), 10)+"\r\n";
//    qDebug()<< xx;
//    this->serial->write(xx.toUtf8());
//    ui->progressBar->setValue(i);  // 当前进度
//    i++;
//    if(i==256)
//    {

//        this->timer->stop();
//        i =0;
//    }

}



void DataMenu::on_pushButton_rev_clicked()
{
    QString xx =  "rev  "+ui->lineEdit_SC->text()+" "+ui->lineEdit_FRQ->text()+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}

void DataMenu::on_pushButton_fwd_clicked()
{
    QString xx =  "fwd  "+ui->lineEdit_SC->text()+" "+ui->lineEdit_FRQ->text()+"\r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}

void DataMenu::on_pushButton_stop_clicked()
{
    QString xx =  "stop \r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}


void DataMenu::on_horizontalSlider_moto_valueChanged(int value)
{
    static int cur_pos = 0;
    qDebug()<< "value" << value ;

    if(value>cur_pos)
    {
        QString xx =  "fwd  "+ui->lineEdit_SC->text()+" "+ui->lineEdit_FRQ->text()+"\r\n";
        qDebug()<< xx;
        this->serial->write(xx.toUtf8());

    }else{
        QString xx =  "rev  "+ui->lineEdit_SC->text()+" "+ui->lineEdit_FRQ->text()+"\r\n";
        qDebug()<< xx;
        this->serial->write(xx.toUtf8());
    }


    cur_pos = value;
}

void DataMenu::on_pushButton_lock_clicked()
{
    QString xx =  "lock \r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}

void DataMenu::on_pushButton_unlock_clicked()
{
    QString xx =  "unlock \r\n";
    qDebug()<< xx;
    this->serial->write(xx.toUtf8());
}
