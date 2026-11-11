#pragma once

// подключаем фукнцию проверки подключения
bool sht3xBegin();
//подуключение фукнции получение данных
bool sht3xRead(float& temp, float& hum);
