#define _CRT_SECURE_NO_WARNINGS

#include "lab5.h"
#include <cstring>   // Для strlen и strcpy

// Конструктор по умолчанию
STRING5::STRING5() : str(nullptr), length(0) {}

// Конструктор инициализации строкой
STRING5::STRING5(const char* what) {
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
}

// Конструктор копирования
STRING5::STRING5(const STRING5& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

// Конструктор перемещения
STRING5::STRING5(STRING5&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

// Деструктор
STRING5::~STRING5() {
    delete[] str;
}

// Оператор копирующего присваивания
STRING5& STRING5::operator=(const STRING5& other) {
    std::cout << "\nБыло КОПИРОВАНИЕ\n";
    if (this == &other) return *this;

    delete[] str;
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);

    return *this;
}

// Оператор перемещающего присваивания
STRING5& STRING5::operator=(STRING5&& other) noexcept {
    std::cout << "\nБыло ПЕРЕМЕЩЕНИЕ\n";
    if (this == &other) return *this;

    delete[] str;

    str = other.str;
    length = other.length;

    other.str = nullptr;
    other.length = 0;

    return *this;
}

// Изменение строки
STRING5 STRING5::Setstrt(const char* what) {
    std::cout << "\nПроизошло ИЗМЕНЕНИЕ\n";
    delete[] str;
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
    return *this;
}

// Добавление символа к строке
STRING5 STRING5::Strcat(char what) {
    char* newStr = new char[length + 2];
    if (str) {
        strcpy(newStr, str);
    }
    newStr[length] = what;
    newStr[length + 1] = '\0';
    delete[] str;
    str = newStr;
    length++;
    return *this;
}

// Вывод строки
void STRING5::Print() const {
    if (str) std::cout << str << std::endl;
}

// Перегрузка функции Print для вывода строки несколько раз
void STRING5::Print(int times) {
    for (int i = 0; i < times; ++i) {
        Print();
    }
}

// Перегрузка оператора сложения для объединения строк
STRING5 STRING5::operator+(const STRING5& other) const {
    STRING5 result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    if (str) strcpy(result.str, str);
    if (other.str) strcat(result.str, other.str);
    return result;
}

// Перегрузка оператора сравнения на равенство
bool STRING5::operator==(const STRING5& other) const {
    return strcmp(str, other.str) == 0;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const STRING5& obj) {
    std::cout << "\nПроизошел ВЫВОД\n";
    if (obj.str) os << obj.str;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, STRING5& obj) {
    char buffer[1024];
    is.getline(buffer, 1024);
    obj = buffer;  // Используем оператор присваивания
    return is;
}

// Перегрузка оператора () как функтора
int STRING5::operator()() const {
    std::cout << "\nИспользование функтора\n";
    return length;
}
