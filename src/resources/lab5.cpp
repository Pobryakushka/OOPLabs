#define _CRT_SECURE_NO_WARNINGS

#include "lab5.h"
#include <cstring>   // ��� strlen � strcpy

// ����������� �� ���������
STRING5::STRING5() : str(nullptr), length(0) {}

// ����������� ������������� �������
STRING5::STRING5(const char* what) {
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
}

// ����������� �����������
STRING5::STRING5(const STRING5& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

// ����������� �����������
STRING5::STRING5(STRING5&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

// ����������
STRING5::~STRING5() {
    delete[] str;
}

// �������� ����������� ������������
STRING5& STRING5::operator=(const STRING5& other) {
    std::cout << "\n���� �����������\n";
    if (this == &other) return *this;

    delete[] str;
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);

    return *this;
}

// �������� ������������� ������������
STRING5& STRING5::operator=(STRING5&& other) noexcept {
    std::cout << "\n���� �����������\n";
    if (this == &other) return *this;

    delete[] str;

    str = other.str;
    length = other.length;

    other.str = nullptr;
    other.length = 0;

    return *this;
}

// ��������� ������
STRING5 STRING5::Setstrt(const char* what) {
    std::cout << "\n��������� ���������\n";
    delete[] str;
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
    return *this;
}

// ���������� ������� � ������
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

// ����� ������
void STRING5::Print() const {
    if (str) std::cout << str << std::endl;
}

// ���������� ������� Print ��� ������ ������ ��������� ���
void STRING5::Print(int times) {
    for (int i = 0; i < times; ++i) {
        Print();
    }
}

// ���������� ��������� �������� ��� ����������� �����
STRING5 STRING5::operator+(const STRING5& other) const {
    STRING5 result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    if (str) strcpy(result.str, str);
    if (other.str) strcat(result.str, other.str);
    return result;
}

// ���������� ��������� ��������� �� ���������
bool STRING5::operator==(const STRING5& other) const {
    return strcmp(str, other.str) == 0;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const STRING5& obj) {
    std::cout << "\n��������� �����\n";
    if (obj.str) os << obj.str;
    return os;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& is, STRING5& obj) {
    char buffer[1024];
    is.getline(buffer, 1024);
    obj = buffer;  // ���������� �������� ������������
    return is;
}

// ���������� ��������� () ��� ��������
int STRING5::operator()() const {
    std::cout << "\n������������� ��������\n";
    return length;
}
