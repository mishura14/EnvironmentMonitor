#pragma once

//функция подключение датчика
bool scd41Begin();
//фукнция чтение данных
bool scd41Read(float& co2, float& temp, float& hum);
