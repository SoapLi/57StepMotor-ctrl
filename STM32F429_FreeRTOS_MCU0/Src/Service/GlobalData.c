#include "GlobalData.h"
#include "marco.h"
#include "FreeRTOS.h"
#include "semphr.h"

SemaphoreHandle_t BinarySemaphoreACKSync;
QueueHandle_t Spi_Int_Queue;