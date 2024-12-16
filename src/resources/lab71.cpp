#define _CRT_SECURE_NO_WARNINGS

#include "lab71.h"

// Конструктор по умолчанию: создаёт пустую строку
STRING::STRING() : str(nullptr), length(0) {}

// Конструктор с параметром: инициализирует строку переданным значением
STRING::STRING(const char* what) {
    length = std::strlen(what);
    str = new char[length + 1];
    std::strcpy(str, what);
}

// Конструктор копирования: создаёт глубокую копию строки
STRING::STRING(const STRING& other) : str(nullptr), length(other.length) {
    if (other.str) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
}

// Оператор присваивания: освобождает старую строку и копирует новую
STRING& STRING::operator=(const STRING& other) {
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    delete[] str; // Освобождаем текущую строку
    str = nullptr;
    length = other.length;

    if (other.str) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    return *this;
}

// Деструктор: освобождает память, выделенную под строку
STRING::~STRING() {
    delete[] str;
    str = nullptr; // Предотвращение повторного освобождения
}

// Метод Setstrt: изменяет строку на переданную
STRING STRING::Setstrt(const char* what) {
    delete[] str; // Удаляем старую строку
    length = std::strlen(what);
    str = new char[length + 1];
    std::strcpy(str, what);
    return *this;
}

// Метод Strcat: добавляет символ в конец строки
STRING STRING::Strcat(char what) {
    char* newStr = new char[length + 2]; // +1 для символа и +1 для '\0'
    if (str) {
        std::strcpy(newStr, str);
    }
    newStr[length] = what;
    newStr[length + 1] = '\0';

    delete[] str; // Удаляем старую строку
    str = newStr;
    length++;
    return *this;
}

// Метод Print: выводит строку на экран
void STRING::Print() const {
    if (str) {
        std::cout << str;
    }
    else {
        std::cout << "(empty)";
    }
}

// Перегрузка оператора << для вывода строки
std::ostream& operator<<(std::ostream& os, const STRING& obj) {
    if (obj.str) {
        os << obj.str;
    }
    else {
        os << "(empty)";
    }
    return os;
}

// Перегрузка оператора >> для ввода строки
std::istream& operator>>(std::istream& is, STRING& obj) {
    char buffer[1024]; // Буфер для ввода строки
    is >> buffer;

    obj.Setstrt(buffer); // Устанавливаем новую строку
    return is;
}