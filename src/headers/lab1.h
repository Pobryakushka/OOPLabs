#pragma once
#include <cstdlib> // Для malloc и free
#include <iostream> // Для std::cout

class STRING1 {
private:
    char *buf; // Указатель для хранения строки
    unsigned len; // Длина строки

    // Вспомогательная функция для вычисления длины строки вручную
    unsigned CalculateLength(const char* str);

public:
    // 1. Инициализация пустой строкой
    STRING1();

    // Конструктор копирования
    STRING1(const STRING1& other);

    // Деструктор
    ~STRING1(); // Освобождение памяти

    // 6. Изменение строки областью памяти
    STRING1 Setstrt(const char* what);

    // 8. Добавление символа
    STRING1 Strcat(char what);

    // 11. Вывод строки на экран
    void Print();

    // Сложение строк (inline метод)
    inline STRING1 Concat(const STRING1& other) const {
        STRING1 newSTRING1;
        unsigned totalLength = len + other.len;
        newSTRING1.buf = static_cast<char*>(malloc(totalLength + 1)); // Выделяем память для новой строки
        if (newSTRING1.buf) {
            // Копируем первую строку
            for (unsigned i = 0; i < len; ++i) {
                newSTRING1.buf[i] = buf[i];
            }
            // Копируем вторую строку
            for (unsigned i = 0; i < other.len; ++i) {
                newSTRING1.buf[len + i] = other.buf[i];
            }
            newSTRING1.len = totalLength;
            newSTRING1.buf[totalLength] = '\0'; // Завершающий нулевой символ
        }
        return newSTRING1; // Возвращаем новый объект STRING1
    }

    // Дружественная функция для вывода строки
    friend void Print(const STRING1& STRING1); // friend функция для доступа к приватным данным
};
