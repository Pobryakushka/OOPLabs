#ifndef LAB6_H
#define LAB6_H

#include <iostream>

// ������ ������ NumberProcessor
template <typename T>
class NumberProcessor {
public:
    NumberProcessor(T* numbers, int size); // ����������� ��������� ������ ����� � ��� ������
    T calculateSum(); // ����� ��� ���������� �����

private:
    T* numbers; // ��������� �� ������ �����
    int size;   // ������ �������
};

// ������ ������� customPrintf
void customPrintf(); // ������� ������ ��� ��������

template <typename T, typename... Args>
void customPrintf(const T& first, const Args&... rest) {
    // ������� ������� �������
    std::cout << first;

    // ���� ���� ��� ��������, ������� ������
    if constexpr (sizeof...(rest) > 0) {
        std::cout << " ";
    }

    // ���������� �������� customPrintf ��� ��������� ����������
    customPrintf(rest...);
}

#endif
