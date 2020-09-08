/********************************************************************************
** Form generated from reading UI file 'datamenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMENU_H
#define UI_DATAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMenu
{
public:
    QGroupBox *groupBox_2;
    QPushButton *pushButtonUsartStart;
    QComboBox *rateCbx_plc;
    QComboBox *portCbx_plc;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QPushButton *pushButton_GetDevId;
    QPushButton *pushButtonStart;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_home;
    QPushButton *pushButton_pos;
    QLineEdit *lineEdit_boat;
    QLineEdit *lineEdit_col;
    QLineEdit *lineEdit_row;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_next;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_readconfig;
    QPushButton *pushButton_writeconfig;
    QLabel *label_4;
    QLineEdit *lineEdit_value_write;
    QLabel *label_5;
    QLineEdit *lineEdit_addr_read;
    QLineEdit *lineEdit_addr_write;
    QLabel *label_7;
    QPushButton *pushButton_writeconfig_2;
    QProgressBar *progressBar;
    QLabel *labelCurRowNumT;
    QLabel *label_img;
    QPushButton *pushButton_fwd;
    QPushButton *pushButton_rev;
    QLineEdit *lineEdit_FRQ;
    QLabel *label_8;
    QLineEdit *lineEdit_SC;
    QLabel *label_6;
    QPushButton *pushButton_stop;
    QSlider *horizontalSlider_moto;
    QPushButton *pushButton_lock;
    QPushButton *pushButton_unlock;

    void setupUi(QWidget *DataMenu)
    {
        if (DataMenu->objectName().isEmpty())
            DataMenu->setObjectName(QString::fromUtf8("DataMenu"));
        DataMenu->resize(1112, 748);
        DataMenu->setMinimumSize(QSize(600, 0));
        DataMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"QWidget{border-top-left-radius:15px;border-top-right-radius:5px;}"));
        groupBox_2 = new QGroupBox(DataMenu);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 651, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0#D3D3D3, stop: 1 #D3D3D3);\n"
"border:2px solid gray;\n"
"border-radius:5px;\n"
"margin-top:1ex;/* leave space at the top for the title */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top left;\n"
"padding: 0 5px;\n"
"}"));
        pushButtonUsartStart = new QPushButton(groupBox_2);
        pushButtonUsartStart->setObjectName(QString::fromUtf8("pushButtonUsartStart"));
        pushButtonUsartStart->setGeometry(QRect(230, 10, 161, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButtonUsartStart->setFont(font1);
        pushButtonUsartStart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 24pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        rateCbx_plc = new QComboBox(groupBox_2);
        rateCbx_plc->setObjectName(QString::fromUtf8("rateCbx_plc"));
        rateCbx_plc->setGeometry(QRect(130, 40, 80, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rateCbx_plc->sizePolicy().hasHeightForWidth());
        rateCbx_plc->setSizePolicy(sizePolicy);
        rateCbx_plc->setMinimumSize(QSize(80, 20));
        rateCbx_plc->setMaximumSize(QSize(80, 20));
        portCbx_plc = new QComboBox(groupBox_2);
        portCbx_plc->setObjectName(QString::fromUtf8("portCbx_plc"));
        portCbx_plc->setGeometry(QRect(30, 40, 80, 20));
        sizePolicy.setHeightForWidth(portCbx_plc->sizePolicy().hasHeightForWidth());
        portCbx_plc->setSizePolicy(sizePolicy);
        portCbx_plc->setMinimumSize(QSize(80, 20));
        portCbx_plc->setMaximumSize(QSize(80, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("SimSun-ExtB"));
        font2.setPointSize(9);
        portCbx_plc->setFont(font2);
        textEdit = new QTextEdit(DataMenu);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 110, 651, 621));
        textEdit->setStyleSheet(QString::fromUtf8("font: 18pt \"Agency FB\";\n"
"font: 14pt \"Consolas\";"));
        groupBox = new QGroupBox(DataMenu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(680, 20, 421, 711));
        groupBox->setFont(font);
        pushButton_GetDevId = new QPushButton(groupBox);
        pushButton_GetDevId->setObjectName(QString::fromUtf8("pushButton_GetDevId"));
        pushButton_GetDevId->setGeometry(QRect(20, 20, 75, 23));
        pushButtonStart = new QPushButton(groupBox);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(110, 20, 75, 23));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 50, 181, 421));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_3->setFont(font3);
        pushButton_home = new QPushButton(groupBox_3);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        pushButton_home->setGeometry(QRect(10, 40, 161, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        pushButton_home->setFont(font4);
        pushButton_home->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        pushButton_pos = new QPushButton(groupBox_3);
        pushButton_pos->setObjectName(QString::fromUtf8("pushButton_pos"));
        pushButton_pos->setGeometry(QRect(10, 310, 161, 71));
        pushButton_pos->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        lineEdit_boat = new QLineEdit(groupBox_3);
        lineEdit_boat->setObjectName(QString::fromUtf8("lineEdit_boat"));
        lineEdit_boat->setGeometry(QRect(90, 220, 71, 20));
        lineEdit_col = new QLineEdit(groupBox_3);
        lineEdit_col->setObjectName(QString::fromUtf8("lineEdit_col"));
        lineEdit_col->setGeometry(QRect(90, 250, 71, 20));
        lineEdit_row = new QLineEdit(groupBox_3);
        lineEdit_row->setObjectName(QString::fromUtf8("lineEdit_row"));
        lineEdit_row->setGeometry(QRect(90, 280, 71, 20));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 220, 71, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        label->setFont(font5);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(18, 250, 71, 16));
        label_2->setFont(font5);
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(18, 280, 71, 16));
        label_3->setFont(font5);
        pushButton_next = new QPushButton(groupBox_3);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(10, 120, 161, 71));
        pushButton_next->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(216, 50, 181, 421));
        groupBox_4->setFont(font3);
        pushButton_readconfig = new QPushButton(groupBox_4);
        pushButton_readconfig->setObjectName(QString::fromUtf8("pushButton_readconfig"));
        pushButton_readconfig->setGeometry(QRect(10, 70, 161, 71));
        pushButton_readconfig->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        pushButton_writeconfig = new QPushButton(groupBox_4);
        pushButton_writeconfig->setObjectName(QString::fromUtf8("pushButton_writeconfig"));
        pushButton_writeconfig->setGeometry(QRect(10, 230, 161, 71));
        pushButton_writeconfig->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(8, 40, 81, 20));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(10);
        label_4->setFont(font6);
        lineEdit_value_write = new QLineEdit(groupBox_4);
        lineEdit_value_write->setObjectName(QString::fromUtf8("lineEdit_value_write"));
        lineEdit_value_write->setGeometry(QRect(100, 200, 71, 20));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(8, 200, 81, 20));
        label_5->setFont(font6);
        lineEdit_addr_read = new QLineEdit(groupBox_4);
        lineEdit_addr_read->setObjectName(QString::fromUtf8("lineEdit_addr_read"));
        lineEdit_addr_read->setGeometry(QRect(100, 40, 71, 20));
        lineEdit_addr_write = new QLineEdit(groupBox_4);
        lineEdit_addr_write->setObjectName(QString::fromUtf8("lineEdit_addr_write"));
        lineEdit_addr_write->setGeometry(QRect(100, 170, 71, 20));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 170, 81, 20));
        label_7->setFont(font6);
        pushButton_writeconfig_2 = new QPushButton(groupBox_4);
        pushButton_writeconfig_2->setObjectName(QString::fromUtf8("pushButton_writeconfig_2"));
        pushButton_writeconfig_2->setGeometry(QRect(10, 310, 161, 71));
        pushButton_writeconfig_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(17, 390, 151, 23));
        progressBar->setValue(24);
        labelCurRowNumT = new QLabel(groupBox);
        labelCurRowNumT->setObjectName(QString::fromUtf8("labelCurRowNumT"));
        labelCurRowNumT->setGeometry(QRect(740, 510, 40, 40));
        sizePolicy.setHeightForWidth(labelCurRowNumT->sizePolicy().hasHeightForWidth());
        labelCurRowNumT->setSizePolicy(sizePolicy);
        labelCurRowNumT->setMinimumSize(QSize(40, 40));
        labelCurRowNumT->setMaximumSize(QSize(40, 40));
        labelCurRowNumT->setStyleSheet(QString::fromUtf8("font: 14pt \"Agency FB\";\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_img = new QLabel(groupBox);
        label_img->setObjectName(QString::fromUtf8("label_img"));
        label_img->setGeometry(QRect(10, 620, 191, 81));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Consolas"));
        font7.setPointSize(18);
        font7.setBold(false);
        font7.setWeight(50);
        label_img->setFont(font7);
        pushButton_fwd = new QPushButton(groupBox);
        pushButton_fwd->setObjectName(QString::fromUtf8("pushButton_fwd"));
        pushButton_fwd->setGeometry(QRect(280, 480, 51, 71));
        pushButton_fwd->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        pushButton_rev = new QPushButton(groupBox);
        pushButton_rev->setObjectName(QString::fromUtf8("pushButton_rev"));
        pushButton_rev->setGeometry(QRect(220, 480, 51, 71));
        pushButton_rev->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        lineEdit_FRQ = new QLineEdit(groupBox);
        lineEdit_FRQ->setObjectName(QString::fromUtf8("lineEdit_FRQ"));
        lineEdit_FRQ->setGeometry(QRect(110, 520, 71, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(38, 520, 71, 16));
        label_8->setFont(font5);
        lineEdit_SC = new QLineEdit(groupBox);
        lineEdit_SC->setObjectName(QString::fromUtf8("lineEdit_SC"));
        lineEdit_SC->setGeometry(QRect(110, 490, 71, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(38, 490, 71, 16));
        label_6->setFont(font5);
        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(340, 480, 51, 71));
        pushButton_stop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        horizontalSlider_moto = new QSlider(groupBox);
        horizontalSlider_moto->setObjectName(QString::fromUtf8("horizontalSlider_moto"));
        horizontalSlider_moto->setGeometry(QRect(230, 650, 160, 22));
        horizontalSlider_moto->setOrientation(Qt::Horizontal);
        pushButton_lock = new QPushButton(groupBox);
        pushButton_lock->setObjectName(QString::fromUtf8("pushButton_lock"));
        pushButton_lock->setGeometry(QRect(220, 560, 81, 71));
        pushButton_lock->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));
        pushButton_unlock = new QPushButton(groupBox);
        pushButton_unlock->setObjectName(QString::fromUtf8("pushButton_unlock"));
        pushButton_unlock->setGeometry(QRect(310, 560, 81, 71));
        pushButton_unlock->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 18pt \"\351\273\221\344\275\223\";\n"
"\n"
"\n"
"	color: rgb(0, 170, 0);\n"
"background-color:gray;\n"
"color: white;   border-radius: 10px;  \n"
"border: 2px groove gray;                                            \n"
"border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:white; color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"font: 12pt \"\351\273\221\344\275\223\";\n"
"background-color:rgb(85, 170, 255);                                                           border-style: inset; \n"
"}"));

        retranslateUi(DataMenu);

        QMetaObject::connectSlotsByName(DataMenu);
    } // setupUi

    void retranslateUi(QWidget *DataMenu)
    {
        DataMenu->setWindowTitle(QCoreApplication::translate("DataMenu", "cmd test", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DataMenu", "Port Config", nullptr));
        pushButtonUsartStart->setText(QCoreApplication::translate("DataMenu", "connect", nullptr));
        textEdit->setHtml(QCoreApplication::translate("DataMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Agency FB'; font-size:18pt;\"><br /></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DataMenu", "Other Config", nullptr));
        pushButton_GetDevId->setText(QCoreApplication::translate("DataMenu", "Gen Key", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("DataMenu", "start", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DataMenu", "ROBOT CMD TEST", nullptr));
        pushButton_home->setText(QCoreApplication::translate("DataMenu", "home", nullptr));
        pushButton_pos->setText(QCoreApplication::translate("DataMenu", "pos", nullptr));
        label->setText(QCoreApplication::translate("DataMenu", "Boat", nullptr));
        label_2->setText(QCoreApplication::translate("DataMenu", "Col", nullptr));
        label_3->setText(QCoreApplication::translate("DataMenu", "Row", nullptr));
        pushButton_next->setText(QCoreApplication::translate("DataMenu", "next", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DataMenu", "DUT TEST(E2ROM 24c02)", nullptr));
        pushButton_readconfig->setText(QCoreApplication::translate("DataMenu", "read config", nullptr));
        pushButton_writeconfig->setText(QCoreApplication::translate("DataMenu", "write config", nullptr));
        label_4->setText(QCoreApplication::translate("DataMenu", "Address(Hex)", nullptr));
        label_5->setText(QCoreApplication::translate("DataMenu", "Value(Hex)", nullptr));
        label_7->setText(QCoreApplication::translate("DataMenu", "Address(Hex)", nullptr));
        pushButton_writeconfig_2->setText(QCoreApplication::translate("DataMenu", "AUTO W 0-255", nullptr));
        labelCurRowNumT->setText(QString());
        label_img->setText(QCoreApplication::translate("DataMenu", "DEMO ", nullptr));
        pushButton_fwd->setText(QCoreApplication::translate("DataMenu", "FWD", nullptr));
        pushButton_rev->setText(QCoreApplication::translate("DataMenu", "REV", nullptr));
        lineEdit_FRQ->setText(QCoreApplication::translate("DataMenu", "50000", nullptr));
        label_8->setText(QCoreApplication::translate("DataMenu", "Frq", nullptr));
        lineEdit_SC->setText(QCoreApplication::translate("DataMenu", "10000", nullptr));
        label_6->setText(QCoreApplication::translate("DataMenu", "Step Cnt", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("DataMenu", "STOP", nullptr));
        pushButton_lock->setText(QCoreApplication::translate("DataMenu", "LOCK", nullptr));
        pushButton_unlock->setText(QCoreApplication::translate("DataMenu", "UNLOCK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataMenu: public Ui_DataMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMENU_H
