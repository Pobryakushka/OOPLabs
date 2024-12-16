#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cstring>

class STRING {
protected:
    char* str;

public:
    STRING();                          // Конструктор по умолчанию
    STRING(const STRING& other);        // Конструктор копирования
    STRING& operator=(const STRING& other); // Оператор присваивания
    virtual ~STRING();                 // Виртуальный деструктор
    virtual STRING Setstrt(char* what); // Виртуальная функция для изменения строки
    virtual STRING Strcat(char what);   // Виртуальная функция для добавления символа
    virtual void Print() const;         // Виртуальная функция для вывода строки на экран
};

class AdvancedString : public STRING {
public:
    AdvancedString();                   // Конструктор по умолчанию
    ~AdvancedString();                  // Деструктор
    STRING Setstrt(char* what) override; // Переопределение функции изменения строки
    STRING Strcat(char what) override;   // Переопределение функции добавления символа
    void Print() const override;         // Переопределение функции вывода на экран
};

#endif // LAB4_H
