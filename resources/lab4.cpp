#pragma warning(disable : 4996)

#include "lab4.h"

// ���������� ������������ �� ���������
STRING::STRING() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

// ����������� �����������
STRING::STRING(const STRING& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// �������� ������������
STRING& STRING::operator=(const STRING& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }
    delete[] str;
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    return *this;
}

// ����������� ����������
STRING::~STRING() {
    delete[] str;
}

// ����� ��� ��������� ������ �������� ������
STRING STRING::Setstrt(char* what) {
    delete[] str;
    str = new char[strlen(what) + 1];
    strcpy(str, what);
    return *this;
}

// ����� ��� ���������� ������� � ������
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

// ����� ��� ������ ������ �� �����
void STRING::Print() const {
    std::cout << "STRING: " << str << std::endl;
}

// ���������� ������������ ������ AdvancedString
AdvancedString::AdvancedString() : STRING() {}

// ���������� ��� ������ AdvancedString
AdvancedString::~AdvancedString() {}

// ��������������� ������� ��������� ������
STRING AdvancedString::Setstrt(char* what) {
    std::cout << "AdvancedString Setstrt called\n";
    return STRING::Setstrt(what);
}

// ��������������� ������� ���������� �������
STRING AdvancedString::Strcat(char what) {
    std::cout << "AdvancedString Strcat called\n";
    return STRING::Strcat(what);
}

// ��������������� ������� ������ ������ �� �����
void AdvancedString::Print() const {
    std::cout << "AdvancedString: ";
    STRING::Print();
}
