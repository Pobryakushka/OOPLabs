#pragma once
#include <cstdlib> // ��� malloc � free
#include <iostream> // ��� std::cout

class STRING1 {
private:
    char *buf; // ��������� ��� �������� ������
    unsigned len; // ����� ������

    // ��������������� ������� ��� ���������� ����� ������ �������
    unsigned CalculateLength(const char* str);

public:
    // 1. ������������� ������ �������
    STRING1();

    // ����������� �����������
    STRING1(const STRING1& other);

    // ����������
    ~STRING1(); // ������������ ������

    // 6. ��������� ������ �������� ������
    STRING1 Setstrt(const char* what);

    // 8. ���������� �������
    STRING1 Strcat(char what);

    // 11. ����� ������ �� �����
    void Print();

    // �������� ����� (inline �����)
    inline STRING1 Concat(const STRING1& other) const {
        STRING1 newSTRING1;
        unsigned totalLength = len + other.len;
        newSTRING1.buf = static_cast<char*>(malloc(totalLength + 1)); // �������� ������ ��� ����� ������
        if (newSTRING1.buf) {
            // �������� ������ ������
            for (unsigned i = 0; i < len; ++i) {
                newSTRING1.buf[i] = buf[i];
            }
            // �������� ������ ������
            for (unsigned i = 0; i < other.len; ++i) {
                newSTRING1.buf[len + i] = other.buf[i];
            }
            newSTRING1.len = totalLength;
            newSTRING1.buf[totalLength] = '\0'; // ����������� ������� ������
        }
        return newSTRING1; // ���������� ����� ������ STRING1
    }

    // ������������� ������� ��� ������ ������
    friend void Print(const STRING1& STRING1); // friend ������� ��� ������� � ��������� ������
};
