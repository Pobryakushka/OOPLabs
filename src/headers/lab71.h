#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <cstring>

class STRING {
private:
    char* str; // ��������� �� ������
    int length; // ����� ������

public:
    // ������������ � ����������
    STRING(); // ������������� ������ �������
    STRING(const char* what); // ������������� �������
    STRING(const STRING& other); // ����������� �����������
    STRING& operator=(const STRING& other); // �������� ������������
    ~STRING(); // ������������ ������

    // ������
    STRING Setstrt(const char* what); // ��������� ������ �������� ������
    STRING Strcat(char what); // ���������� �������
    void Print() const; // ����� �� �����

    // ���������� ����������
    friend std::ostream& operator<<(std::ostream& os, const STRING& obj); // ���������� <<
    friend std::istream& operator>>(std::istream& is, STRING& obj); // ���������� >>
};

#endif // LAB7_H