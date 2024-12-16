#include "lab1.h"
#include <iostream> // Для std::cout

// Вспомогательная функция для вычисления длины строки
unsigned STRING::CalculateLength(const char* str) {
    unsigned length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 1. Инициализация пустой строки
STRING::STRING() : buf(nullptr), len(0) { // Инициализация указателя на nullptr
    buf = static_cast<char*>(malloc(1)); // Выделяем память для пустой строки
    buf[0] = '\0'; // Пустая строка
}

// Конструктор копирования
STRING::STRING(const STRING& other) : len(other.len) {
    buf = static_cast<char*>(malloc(len + 1)); // Выделяем память для новой строки
    if (buf) {
        for (unsigned i = 0; i < len; ++i) {
            buf[i] = other.buf[i]; // Копируем каждый символ из другого объекта
        }
        buf[len] = '\0'; // Добавляем нулевой символ в конец
        std::cout << "Конструктор копирования вызван\n";
    }
}

// Деструктор
STRING::~STRING() {
    free(buf); // Освобождаем память
}

// 6. Изменение строки областью памяти (возвращает STRING)
STRING STRING::Setstrt(const char* what) {
    free(buf); // Освобождаем старую память
    len = CalculateLength(what); // Вычисляем длину строки вручную
    buf = static_cast<char*>(malloc(len + 1)); // Выделяем новую память
    if (buf) {
        for (unsigned i = 0; i < len; ++i) {
            buf[i] = what[i]; // Копируем строку вручную
        }
        buf[len] = '\0'; // Добавляем нулевой символ в конце
    }
    return *this; // Возвращаем текущий объект
}

// 8. Добавление символа (возвращает STRING)
STRING STRING::Strcat(char what) {
    // Перевыделяем память для нового символа (+1 для символа и +1 для нулевого символа)
    buf = static_cast<char*>(realloc(buf, len + 2));
    if (buf) {
        buf[len] = what; // Добавляем символ
        buf[len + 1] = '\0'; // Добавляем нулевой символ в конец
        len++;
    }
    return *this; // Возвращаем текущий объект
}

// 11. Вывод строки на экран
void STRING::Print() {
    std::cout << buf << std::endl; // Вывод строки с помощью std::cout
}

// Дружественная функция для вывода строки
void Print(const STRING& string) {
    std::cout << string.buf << std::endl; // Прямой доступ к приватному члену buf
}
