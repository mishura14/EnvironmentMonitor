#pragma once
// подключаеся к датчику
bool lightBegin(); //true если датчик ответил
// полечаем значение датчика
bool lightRead(float& lux); // tre если заничение датчика полученно
