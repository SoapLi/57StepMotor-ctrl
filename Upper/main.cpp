#include <QApplication>
#include  "datamenu.h"
#include "GloableData/gloabledata.h"
#include <macro_define.h>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QTableWidget>
#include "qtablewidget.h"
#include <QWidget>
//#include <QtGui/QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSplashScreen>
#include <QDateTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include "qt_windows.h"
#include <QVariant>
#include <QDebug>
#include <QScrollBar>
#include <QSettings>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include <QtXml>
#include "tools.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataMenu dataMenu;
    dataMenu.show();
    return a.exec();
}
