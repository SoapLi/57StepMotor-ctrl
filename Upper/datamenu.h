void on_pushButtonNSPoleNumApply_clicked();
#ifndef DATAMENU_H
#define DATAMENU_H

#include <QWidget>
#include <QTimer>
#include <QWidget>
#include <QChart>
#include <QLineSeries>
#include <QVector>
#include <QTimer>
#include <QtCharts/QChart>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QValueAxis>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <macro_define.h>


#include <QVector>
#include <QButtonGroup>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class DataMenu;
}


class DataMenu : public QWidget
{
    Q_OBJECT

public:
    explicit DataMenu(QWidget *parent = 0);
    ~DataMenu();


    void initSerialPortBox();
    bool initPlcSerialService();
    void reqHeartBeats();

protected:


signals:


private slots:
    void serialPlcReciveMannage();
    void on_pushButtonUsartStart_clicked();

    void on_pushButton_Test_clicked();

    void on_pushButton_GetDevId_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButton_home_clicked();

    void on_pushButton_park_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_pos_clicked();

    void on_pushButton_res_clicked();

    void on_pushButton_readconfig_clicked();

    void on_pushButton_writeconfig_clicked();

    void on_pushButton_writeconfig_2_clicked();

    void on_pushButton_rev_clicked();

    void on_pushButton_fwd_clicked();

    void on_pushButton_stop_clicked();



    void on_horizontalSlider_moto_valueChanged(int value);

    void on_pushButton_lock_clicked();

    void on_pushButton_unlock_clicked();

private:

    Ui::DataMenu *ui;
    QSerialPort *serial;
    QByteArray byteArrayReciveBuff;
    int ack_flag;
    QTimer *timer ;

public slots:
    void handleTimeout();  //超时处理函数
};

#endif // DATAMENU_H
