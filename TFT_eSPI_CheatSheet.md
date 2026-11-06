TFT_eSPI — шпаргалка по командам
1. Подключение и запуск дисплея
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void loop() {

}


Команда	Назначение
tft.init()	Инициализирует дисплей
tft.setRotation(1)	Устанавливает ориентацию экрана
tft.width()	Возвращает ширину экрана
tft.height()	Возвращает высоту экрана
tft.fillScreen(color)	Заполняет весь экран цветом

2. Как сделать фон чёрным
Главная команда
tft.fillScreen(TFT_BLACK);


Она закрашивает весь экран чёрным цветом.

Если хочешь тёмный, но не абсолютно чёрный фон:
uint16_t background = 0x101820;
tft.fillScreen(background);


Важно: fillScreen() лучше вызывать при переходе на новую страницу или при первоначальной отрисовке. Не вызывай её постоянно в loop(), иначе экран будет очищаться при каждом проходе цикла.
3. Цвета
В TFT_eSPI используется формат RGB565.
Цвет	Команда
Чёрный	TFT_BLACK
Белый	TFT_WHITE
Красный	TFT_RED
Зелёный	TFT_GREEN
Синий	TFT_BLUE
Жёлтый	TFT_YELLOW
Голубой	TFT_CYAN
Пурпурный	TFT_MAGENTA
Серый	TFT_DARKGREY
Оранжевый	TFT_ORANGE

Свой цвет:
uint16_t blue = tft.color565(37, 136, 216);


Аргументы — красный, зелёный и синий компоненты от 0 до 255.
4. Геометрические фигуры
Все координаты задаются в пикселях.
Команда	Что делает	Пример
drawPixel()	Рисует точку	tft.drawPixel(10, 10, TFT_RED);
drawLine()	Рисует линию	tft.drawLine(10, 10, 100, 100, TFT_WHITE);
drawFastHLine()	Горизонтальная линия	tft.drawFastHLine(10, 20, 100, TFT_WHITE);
drawFastVLine()	Вертикальная линия	tft.drawFastVLine(10, 20, 100, TFT_WHITE);
drawRect()	Контур прямоугольника	tft.drawRect(10, 10, 100, 50, TFT_WHITE);
fillRect()	Заполненный прямоугольник	tft.fillRect(10, 10, 100, 50, TFT_BLUE);
drawRoundRect()	Контур закруглённого прямоугольника	tft.drawRoundRect(10, 10, 100, 50, 8, TFT_WHITE);
fillRoundRect()	Заполненный закруглённый прямоугольник	tft.fillRoundRect(10, 10, 100, 50, 8, TFT_BLUE);
drawCircle()	Контур круга	tft.drawCircle(50, 50, 20, TFT_WHITE);
fillCircle()	Заполненный круг	tft.fillCircle(50, 50, 20, TFT_BLUE);
drawTriangle()	Контур треугольника	tft.drawTriangle(10, 10, 50, 10, 30, 50, TFT_WHITE);
fillTriangle()	Заполненный треугольник	tft.fillTriangle(10, 10, 50, 10, 30, 50, TFT_BLUE);

5. Работа с текстом
Основные команды
Команда	Назначение
setTextColor()	Задаёт цвет текста
setTextSize()	Задаёт масштаб стандартного шрифта
setTextFont()	Выбирает встроенный шрифт
drawString()	Выводит текст по координатам
drawCentreString()	Выводит текст с центром в указанной точке
drawRightString()	Выравнивает текст по правому краю относительно координаты
textWidth()	Вычисляет ширину строки
fontHeight()	Возвращает высоту выбранного шрифта
setTextWrap()	Включает или отключает перенос строк

Примеры
Обычный текст:
tft.setTextColor(TFT_WHITE);
tft.drawString("TEMPERATURE", 20, 20, 2);


Текст по центру:
tft.drawCentreString("SETTINGS", 160, 100, 2);


Текст справа:
tft.drawRightString("25.5 C", 300, 20, 4);


Цвет текста:
tft.setTextColor(TFT_CYAN);


Цвет текста и фона:
tft.setTextColor(TFT_WHITE, TFT_BLUE);


Для прозрачного фона текста используй только цвет переднего плана:
tft.setTextColor(TFT_WHITE);


Шрифты
tft.setTextFont(2);


Некоторые встроенные шрифты TFT_eSPI:
- 1 — небольшой стандартный шрифт.
- 2 — средний шрифт.
- 4 — более крупный шрифт.
- 6, 7 — специальные крупные цифровые шрифты.
- 8 — очень крупный цифровой шрифт.
Пример:
tft.setTextFont(2);
tft.drawString("HUMIDITY", 20, 20);


6. Выравнивание текста
Можно задавать точку привязки текста через setTextDatum().
tft.setTextDatum(MC_DATUM);


Полезные варианты:
Константа	Положение относительно точки
TL_DATUM	Верхний левый угол
TC_DATUM	Верхний центр
TR_DATUM	Верхний правый угол
ML_DATUM	Середина слева
MC_DATUM	Центр
MR_DATUM	Середина справа
BL_DATUM	Нижний левый угол
BC_DATUM	Нижний центр
BR_DATUM	Нижний правый угол

Например, чтобы вывести надпись точно по центру кнопки:
tft.setTextDatum(MC_DATUM);
tft.drawString("SETTINGS", 80, 45, 2);


Здесь точка (80, 45) будет центром текста.

Обрати внимание: drawCentreString() сама центрирует строку относительно X, а setTextDatum() меняет точку привязки для обычного drawString().
7. Кнопки
Пример рисования кнопки:
tft.fillRoundRect(
    20, 20,      // Координаты
    120, 50,     // Размер
    8,           // Радиус углов
    TFT_BLUE     // Цвет
);


Добавляем текст:
tft.setTextColor(TFT_WHITE);
tft.setTextDatum(MC_DATUM);

tft.drawString(
    "SETTINGS",
    80,
    45,
    2
);


Теперь у нас есть фон и текст, расположенный по центру.
8. Полезные дополнительные команды
Команда	Назначение
fillScreen()	Очистка и заполнение всего экрана
setTextDatum()	Выбор точки привязки текста
setTextPadding()	Задание области очистки предыдущего текста
setTextWrap()	Управление переносом строк
setSwapBytes()	Управление порядком байтов при работе с изображениями
pushImage()	Вывод изображения из массива
drawBitmap()	Вывод монохромного изображения из массива
setViewport()	Установка области рисования
resetViewport()	Сброс области рисования

9. Пример: простая карточка датчика
// Фон карточки
tft.fillRoundRect(10, 10, 140, 90, 10, 0x202A36);

// Название
tft.setTextColor(TFT_LIGHTGREY);
tft.drawString("TEMPERATURE", 20, 20, 2);

// Значение
tft.setTextColor(TFT_WHITE);
tft.drawString("24.5", 20, 48, 4);

// Единицы измерения
tft.setTextColor(TFT_CYAN);
tft.drawString("C", 105, 58, 2);


10. Полезные правила
1. Сначала рисуй фон, потом текст и иконки.
2. Не очищай весь экран в каждом проходе loop().
3. Используй одинаковые отступы и радиусы в похожих компонентах.
4. Для цветов интерфейса создай отдельную палитру.
5. Повторяющиеся элементы выноси в отдельные функции.
6. Координаты и размеры лучше передавать параметрами, а не прописывать внутри каждой функции.
