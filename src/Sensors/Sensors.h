
#pragma once
#include "SensorData.h"

void sensorsBegin();                  // подключает все датчики, пишет статус в Serial
void sensorsUpdate(SensorData& d);    // читает все, обновляет только то, что удалось
