#pragma warning(disable : 4996)

#include "lab4.h"

// ���������� ������������ �� ���������
STRING4::STRING4() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

// ����������� �����������
STRING4::STRING4(const STRING4& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// �������� ������������
STRING4& STRING4::operator=(const STRING4& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }
    delete[] str;
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    return *this;
}

// ����������� ����������
STRING4::~STRING4() {
    delete[] str;
}

// ����� ��� ��������� ������ �������� ������
STRING4 STRING4::Setstrt(char* what) {
    delete[] str;
    str = new char[strlen(what) + 1];
    strcpy(str, what);
    return *this;
}

// ����� ��� ���������� ������� � ������
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

// ����� ��� ������ ������ �� �����
void STRING4::Print() const {
    std::cout << "STRING4: " << str << std::endl;
}

// ���������� ������������ ������ AdvancedSTRING4
AdvancedSTRING4::AdvancedSTRING4() : STRING4() {}

// ���������� ��� ������ AdvancedSTRING4
AdvancedSTRING4::~AdvancedSTRING4() {}

// ��������������� ������� ��������� ������
STRING4 AdvancedSTRING4::Setstrt(char* what) {
    std::cout << "AdvancedSTRING4 Setstrt called\n";
    return STRING4::Setstrt(what);
}

// ��������������� ������� ���������� �������
STRING4 AdvancedSTRING4::Strcat(char what) {
    std::cout << "AdvancedSTRING4 Strcat called\n";
    return STRING4::Strcat(what);
}

// ��������������� ������� ������ ������ �� �����
void AdvancedSTRING4::Print() const {
    std::cout << "AdvancedSTRING4: ";
    STRING4::Print();
}
