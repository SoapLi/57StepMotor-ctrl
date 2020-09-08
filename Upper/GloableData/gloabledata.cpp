#include "gloabledata.h"

GloableData::GloableData()
{
    serial = NULL;
}


GloableData::~GloableData()
{
    delete serial;
}

GloableData *GloableData::GetInstance()
{
    static GloableData * gloableData = NULL;
    if(NULL == gloableData)
    {
        gloableData = new GloableData();
    }
    return gloableData;
}
