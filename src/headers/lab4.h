#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cstring>

class STRING4 {
protected:
    char* str;

public:
    STRING4();                          // Конструктор по умолчанию
    STRING4(const STRING4& other);        // Конструктор копирования
    STRING4& operator=(const STRING4& other); // Оператор присваивания
    virtual ~STRING4();                 // Виртуальный деструктор
    virtual STRING4 Setstrt(char* what); // Виртуальная функция для изменения строки
    virtual STRING4 Strcat(char what);   // Виртуальная функция для добавления символа
    virtual void Print() const;         // Виртуальная функция для вывода строки на экран
};

class AdvancedSTRING4 : public STRING4 {
public:
    AdvancedSTRING4();                   // Конструктор по умолчанию
    ~AdvancedSTRING4();                  // Деструктор
    STRING4 Setstrt(char* what) override; // Переопределение функции изменения строки
    STRING4 Strcat(char what) override;   // Переопределение функции добавления символа
    void Print() const override;         // Переопределение функции вывода на экран
};

#endif // LAB4_H
