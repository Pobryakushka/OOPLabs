#pragma warning(disable : 4996)

#include "lab4.h"

// Реализация конструктора по умолчанию
STRING::STRING() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

// Конструктор копирования
STRING::STRING(const STRING& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// Оператор присваивания
STRING& STRING::operator=(const STRING& other) {
    if (this == &other) {
        return *this; // защита от самоприсваивания
    }
    delete[] str;
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    return *this;
}

// Виртуальный деструктор
STRING::~STRING() {
    delete[] str;
}

// Метод для изменения строки областью памяти
STRING STRING::Setstrt(char* what) {
    delete[] str;
    str = new char[strlen(what) + 1];
    strcpy(str, what);
    return *this;
}

// Метод для добавления символа к строке
STRING STRING::Strcat(char what) {
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
void STRING::Print() const {
    std::cout << "STRING: " << str << std::endl;
}

// Реализация производного класса AdvancedString
AdvancedString::AdvancedString() : STRING() {}

// Деструктор для класса AdvancedString
AdvancedString::~AdvancedString() {}

// Переопределение функции изменения строки
STRING AdvancedString::Setstrt(char* what) {
    std::cout << "AdvancedString Setstrt called\n";
    return STRING::Setstrt(what);
}

// Переопределение функции добавления символа
STRING AdvancedString::Strcat(char what) {
    std::cout << "AdvancedString Strcat called\n";
    return STRING::Strcat(what);
}

// Переопределение функции вывода строки на экран
void AdvancedString::Print() const {
    std::cout << "AdvancedString: ";
    STRING::Print();
}
