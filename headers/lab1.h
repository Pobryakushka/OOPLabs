#pragma once
#include <cstdlib> // Для malloc и free
#include <iostream> // Для std::cout

class STRING {
private:
    char *buf; // Указатель для хранения строки
    unsigned len; // Длина строки

    // Вспомогательная функция для вычисления длины строки вручную
    unsigned CalculateLength(const char* str);

public:
    // 1. Инициализация пустой строкой
    STRING();

    // Конструктор копирования
    STRING(const STRING& other);

    // Деструктор
    ~STRING(); // Освобождение памяти

    // 6. Изменение строки областью памяти
    STRING Setstrt(const char* what);

    // 8. Добавление символа
    STRING Strcat(char what);

    // 11. Вывод строки на экран
    void Print();

    // Сложение строк (inline метод)
    inline STRING Concat(const STRING& other) const {
        STRING newString;
        unsigned totalLength = len + other.len;
        newString.buf = static_cast<char*>(malloc(totalLength + 1)); // Выделяем память для новой строки
        if (newString.buf) {
            // Копируем первую строку
            for (unsigned i = 0; i < len; ++i) {
                newString.buf[i] = buf[i];
            }
            // Копируем вторую строку
            for (unsigned i = 0; i < other.len; ++i) {
                newString.buf[len + i] = other.buf[i];
            }
            newString.len = totalLength;
            newString.buf[totalLength] = '\0'; // Завершающий нулевой символ
        }
        return newString; // Возвращаем новый объект STRING
    }

    // Дружественная функция для вывода строки
    friend void Print(const STRING& string); // friend функция для доступа к приватным данным
};
