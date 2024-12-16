#pragma once

#ifndef LAB5_H
#define LAB5_H

#include <iostream>

class STRING {
public:
    STRING();                     // ����������� �� ���������
    STRING(const char* what);      // ����������� ������������� �������
    STRING(const STRING& other);   // ����������� �����������
    STRING(STRING&& other) noexcept; // ����������� �����������
    ~STRING();                    // ����������

    STRING Setstrt(const char* what);  // ����� ��������� ������
    STRING Strcat(char what);      // ����� ���������� �������
    void Print() const;            // ����� ������ ������

    // ���������� �������
    void Print(int times);         // ���������� ������� ��� ������ ������ ��������� ���

    // ���������� ����������
    STRING& operator=(const STRING& other);          // �������� ����������� ������������
    STRING& operator=(STRING&& other) noexcept;      // �������� ������������� ������������
    STRING operator+(const STRING& other) const;     // �������� �������� �����
    bool operator==(const STRING& other) const;      // �������� ��������� �����

    // ���������� �����/������ � ��������
    friend std::ostream& operator<<(std::ostream& os, const STRING& obj); // �������� ������
    friend std::istream& operator>>(std::istream& is, STRING& obj);       // �������� �����
    int operator()() const;  // �������� ��������, ������������ ����� ������

private:
    char* str;                     // ��������� �� ������
    int length;                    // ����� ������
};

#endif
