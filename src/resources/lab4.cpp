#pragma warning(disable : 4996)

#include "lab4.h"

// Реализация конструктора по умолчанию
STRING4::STRING4() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

// Конструктор копирования
STRING4::STRING4(const STRING4& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// Оператор присваивания
STRING4& STRING4::operator=(const STRING4& other) {
    if (this == &other) {
        return *this; // защита от самоприсваивания
    }
    delete[] str;
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    return *this;
}

// Виртуальный деструктор
STRING4::~STRING4() {
    delete[] str;
}

// Метод для изменения строки областью памяти
STRING4 STRING4::Setstrt(char* what) {
    delete[] str;
    str = new char[strlen(what) + 1];
    strcpy(str, what);
    return *this;
}

// Метод для добавления символа к строке
STRING4 STRING4::Strcat(char what) {
    size_t len = strlen(str);
    char* temp = new char[len + 2];
    strcpy(temp, str);
    temp[len] = what;
    temp[len + 1] = '\0';
    delete[] str;
    str = temp;
    return *this;
}

// Метод для вывода строки на экран
void STRING4::Print() const {
    std::cout << "STRING4: " << str << std::endl;
}

// Реализация производного класса AdvancedSTRING4
AdvancedSTRING4::AdvancedSTRING4() : STRING4() {}

// Деструктор для класса AdvancedSTRING4
AdvancedSTRING4::~AdvancedSTRING4() {}

// Переопределение функции изменения строки
STRING4 AdvancedSTRING4::Setstrt(char* what) {
    std::cout << "AdvancedSTRING4 Setstrt called\n";
    return STRING4::Setstrt(what);
}

// Переопределение функции добавления символа
STRING4 AdvancedSTRING4::Strcat(char what) {
    std::cout << "AdvancedSTRING4 Strcat called\n";
    return STRING4::Strcat(what);
}

// Переопределение функции вывода строки на экран
void AdvancedSTRING4::Print() const {
    std::cout << "AdvancedSTRING4: ";
    STRING4::Print();
}
