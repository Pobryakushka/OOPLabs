#pragma once

#ifndef LAB5_H
#define LAB5_H

#include <iostream>

class STRING5 {
public:
    STRING5();                     // Конструктор по умолчанию
    STRING5(const char* what);      // Конструктор инициализации строкой
    STRING5(const STRING5& other);   // Конструктор копирования
    STRING5(STRING5&& other) noexcept; // Конструктор перемещения
    ~STRING5();                    // Деструктор

    STRING5 Setstrt(const char* what);  // Метод изменения строки
    STRING5 Strcat(char what);      // Метод добавления символа
    void Print() const;            // Метод вывода строки

    // Перегрузка функций
    void Print(int times);         // Перегрузка функции для вывода строки несколько раз

    // Перегрузка операторов
    STRING5& operator=(const STRING5& other);          // Оператор копирующего присваивания
    STRING5& operator=(STRING5&& other) noexcept;      // Оператор перемещающего присваивания
    STRING5 operator+(const STRING5& other) const;     // Оператор сложения строк
    bool operator==(const STRING5& other) const;      // Оператор сравнения строк

    // Перегрузка ввода/вывода и функтора
    friend std::ostream& operator<<(std::ostream& os, const STRING5& obj); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, STRING5& obj);       // Оператор ввода
    int operator()() const;  // Оператор функтора, возвращающий длину строки

private:
    char* str;                     // Указатель на строку
    int length;                    // Длина строки
};

#endif
