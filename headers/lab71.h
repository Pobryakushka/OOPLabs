#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <cstring>

class STRING {
private:
    char* str; // Указатель на строку
    int length; // Длина строки

public:
    // Конструкторы и деструктор
    STRING(); // Инициализация пустой строкой
    STRING(const char* what); // Инициализация строкой
    STRING(const STRING& other); // Конструктор копирования
    STRING& operator=(const STRING& other); // Оператор присваивания
    ~STRING(); // Освобождение памяти

    // Методы
    STRING Setstrt(const char* what); // Изменение строки областью памяти
    STRING Strcat(char what); // Добавление символа
    void Print() const; // Вывод на экран

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const STRING& obj); // Перегрузка <<
    friend std::istream& operator>>(std::istream& is, STRING& obj); // Перегрузка >>
};

#endif // LAB7_H