#pragma once
#include <cstdlib> // ��� malloc � free
#include <iostream> // ��� std::cout

class STRING {
private:
    char *buf; // ��������� ��� �������� ������
    unsigned len; // ����� ������

    // ��������������� ������� ��� ���������� ����� ������ �������
    unsigned CalculateLength(const char* str);

public:
    // 1. ������������� ������ �������
    STRING();

    // ����������� �����������
    STRING(const STRING& other);

    // ����������
    ~STRING(); // ������������ ������

    // 6. ��������� ������ �������� ������
    STRING Setstrt(const char* what);

    // 8. ���������� �������
    STRING Strcat(char what);

    // 11. ����� ������ �� �����
    void Print();

    // �������� ����� (inline �����)
    inline STRING Concat(const STRING& other) const {
        STRING newString;
        unsigned totalLength = len + other.len;
        newString.buf = static_cast<char*>(malloc(totalLength + 1)); // �������� ������ ��� ����� ������
        if (newString.buf) {
            // �������� ������ ������
            for (unsigned i = 0; i < len; ++i) {
                newString.buf[i] = buf[i];
            }
            // �������� ������ ������
            for (unsigned i = 0; i < other.len; ++i) {
                newString.buf[len + i] = other.buf[i];
            }
            newString.len = totalLength;
            newString.buf[totalLength] = '\0'; // ����������� ������� ������
        }
        return newString; // ���������� ����� ������ STRING
    }

    // ������������� ������� ��� ������ ������
    friend void Print(const STRING& string); // friend ������� ��� ������� � ��������� ������
};
