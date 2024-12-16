#define _CRT_SECURE_NO_WARNINGS

#include "lab71.h"

// ����������� �� ���������: ������ ������ ������
STRING::STRING() : str(nullptr), length(0) {}

// ����������� � ����������: �������������� ������ ���������� ���������
STRING::STRING(const char* what) {
    length = std::strlen(what);
    str = new char[length + 1];
    std::strcpy(str, what);
}

// ����������� �����������: ������ �������� ����� ������
STRING::STRING(const STRING& other) : str(nullptr), length(other.length) {
    if (other.str) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
}

// �������� ������������: ����������� ������ ������ � �������� �����
STRING& STRING::operator=(const STRING& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }

    delete[] str; // ����������� ������� ������
    str = nullptr;
    length = other.length;

    if (other.str) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    return *this;
}

// ����������: ����������� ������, ���������� ��� ������
STRING::~STRING() {
    delete[] str;
    str = nullptr; // �������������� ���������� ������������
}

// ����� Setstrt: �������� ������ �� ����������
STRING STRING::Setstrt(const char* what) {
    delete[] str; // ������� ������ ������
    length = std::strlen(what);
    str = new char[length + 1];
    std::strcpy(str, what);
    return *this;
}

// ����� Strcat: ��������� ������ � ����� ������
STRING STRING::Strcat(char what) {
    char* newStr = new char[length + 2]; // +1 ��� ������� � +1 ��� '\0'
    if (str) {
        std::strcpy(newStr, str);
    }
    newStr[length] = what;
    newStr[length + 1] = '\0';

    delete[] str; // ������� ������ ������
    str = newStr;
    length++;
    return *this;
}

// ����� Print: ������� ������ �� �����
void STRING::Print() const {
    if (str) {
        std::cout << str;
    }
    else {
        std::cout << "(empty)";
    }
}

// ���������� ��������� << ��� ������ ������
std::ostream& operator<<(std::ostream& os, const STRING& obj) {
    if (obj.str) {
        os << obj.str;
    }
    else {
        os << "(empty)";
    }
    return os;
}

// ���������� ��������� >> ��� ����� ������
std::istream& operator>>(std::istream& is, STRING& obj) {
    char buffer[1024]; // ����� ��� ����� ������
    is >> buffer;

    obj.Setstrt(buffer); // ������������� ����� ������
    return is;
}