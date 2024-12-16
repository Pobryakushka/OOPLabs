#define _CRT_SECURE_NO_WARNINGS

#include "lab5.h"
#include <cstring>   // ��� strlen � strcpy

// ����������� �� ���������
STRING::STRING() : str(nullptr), length(0) {}

// ����������� ������������� �������
STRING::STRING(const char* what) {
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
}

// ����������� �����������
STRING::STRING(const STRING& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

// ����������� �����������
STRING::STRING(STRING&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

// ����������
STRING::~STRING() {
    delete[] str;
}

// �������� ����������� ������������
STRING& STRING::operator=(const STRING& other) {
    std::cout << "\n���� �����������\n";
    if (this == &other) return *this;

    delete[] str;
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);

    return *this;
}

// �������� ������������� ������������
STRING& STRING::operator=(STRING&& other) noexcept {
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
STRING STRING::Setstrt(const char* what) {
    std::cout << "\n��������� ���������\n";
    delete[] str;
    length = strlen(what);
    str = new char[length + 1];
    strcpy(str, what);
    return *this;
}

// ���������� ������� � ������
STRING STRING::Strcat(char what) {
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
void STRING::Print() const {
    if (str) std::cout << str << std::endl;
}

// ���������� ������� Print ��� ������ ������ ��������� ���
void STRING::Print(int times) {
    for (int i = 0; i < times; ++i) {
        Print();
    }
}

// ���������� ��������� �������� ��� ����������� �����
STRING STRING::operator+(const STRING& other) const {
    STRING result;
    result.length = length + other.length;
    result.str = new char[result.length + 1];
    if (str) strcpy(result.str, str);
    if (other.str) strcat(result.str, other.str);
    return result;
}

// ���������� ��������� ��������� �� ���������
bool STRING::operator==(const STRING& other) const {
    return strcmp(str, other.str) == 0;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const STRING& obj) {
    std::cout << "\n��������� �����\n";
    if (obj.str) os << obj.str;
    return os;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& is, STRING& obj) {
    char buffer[1024];
    is.getline(buffer, 1024);
    obj = buffer;  // ���������� �������� ������������
    return is;
}

// ���������� ��������� () ��� ��������
int STRING::operator()() const {
    std::cout << "\n������������� ��������\n";
    return length;
}
