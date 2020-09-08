#ifndef GLOABLEDATA_H
#define GLOABLEDATA_H

#include "datatype.h"
#include <QMutex>
#include <QSerialPort>
#include <QTableWidget>
#include <QVector>
#include <QComboBox>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE
class GloableData
{

public:
    ~GloableData();
    static GloableData* GetInstance();

private:
    GloableData();

public:

    QSerialPort* serial;
};

#endif // GLOABLEDATA_H
