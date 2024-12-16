#pragma once

#ifndef LAB5_H
#define LAB5_H

#include <iostream>

class STRING {
public:
    STRING();                     // Конструктор по умолчанию
    STRING(const char* what);      // Конструктор инициализации строкой
    STRING(const STRING& other);   // Конструктор копирования
    STRING(STRING&& other) noexcept; // Конструктор перемещения
    ~STRING();                    // Деструктор

    STRING Setstrt(const char* what);  // Метод изменения строки
    STRING Strcat(char what);      // Метод добавления символа
    void Print() const;            // Метод вывода строки

    // Перегрузка функций
    void Print(int times);         // Перегрузка функции для вывода строки несколько раз

    // Перегрузка операторов
    STRING& operator=(const STRING& other);          // Оператор копирующего присваивания
    STRING& operator=(STRING&& other) noexcept;      // Оператор перемещающего присваивания
    STRING operator+(const STRING& other) const;     // Оператор сложения строк
    bool operator==(const STRING& other) const;      // Оператор сравнения строк

    // Перегрузка ввода/вывода и функтора
    friend std::ostream& operator<<(std::ostream& os, const STRING& obj); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, STRING& obj);       // Оператор ввода
    int operator()() const;  // Оператор функтора, возвращающий длину строки

private:
    char* str;                     // Указатель на строку
    int length;                    // Длина строки
};

#endif
