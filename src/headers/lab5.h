#pragma once

#ifndef LAB5_H
#define LAB5_H

#include <iostream>

class STRING5 {
public:
    STRING5();                     // ����������� �� ���������
    STRING5(const char* what);      // ����������� ������������� �������
    STRING5(const STRING5& other);   // ����������� �����������
    STRING5(STRING5&& other) noexcept; // ����������� �����������
    ~STRING5();                    // ����������

    STRING5 Setstrt(const char* what);  // ����� ��������� ������
    STRING5 Strcat(char what);      // ����� ���������� �������
    void Print() const;            // ����� ������ ������

    // ���������� �������
    void Print(int times);         // ���������� ������� ��� ������ ������ ��������� ���

    // ���������� ����������
    STRING5& operator=(const STRING5& other);          // �������� ����������� ������������
    STRING5& operator=(STRING5&& other) noexcept;      // �������� ������������� ������������
    STRING5 operator+(const STRING5& other) const;     // �������� �������� �����
    bool operator==(const STRING5& other) const;      // �������� ��������� �����

    // ���������� �����/������ � ��������
    friend std::ostream& operator<<(std::ostream& os, const STRING5& obj); // �������� ������
    friend std::istream& operator>>(std::istream& is, STRING5& obj);       // �������� �����
    int operator()() const;  // �������� ��������, ������������ ����� ������

private:
    char* str;                     // ��������� �� ������
    int length;                    // ����� ������
};

#endif
