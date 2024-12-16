#include "lab3.h"
#include <iostream>
#include <cstdlib>  // ��� rand() � srand()
#include <ctime>    // ��� time()

// �����������, ���������� ������ ��� ������������������
NumberSequence::NumberSequence(int n) {
    size = n;  // ��������� ������
    sequence = new double[size];  // ����������� �������� ������
}

// ����������, ������������� ������
NumberSequence::~NumberSequence() {
    delete[] sequence;  // ����������� ������
}

// ��������� ��������� ������������������
void NumberSequence::generate() {
    std::srand(static_cast<unsigned>(std::time(0)));  // ������������� ���������� ��������� �����
    for (int i = 0; i < size; ++i) {
        sequence[i] = (std::rand() % 200 - 100) + static_cast<double>(std::rand()) / RAND_MAX;
        // ���������� ����� � ��������� �� -100 �� 100 � ������� ������
    }
}

// ������ ���� ������������������
void NumberSequence::input() {
    std::cout << "������� ������������������ �� " << size << " �����:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> sequence[i];
    }
}

// ����� ������������������
void NumberSequence::output() const {
    for (int i = 0; i < size; ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

// ��������, �������� �� ������������������ ��������� (���������� ����������)
bool NumberSequence::isDescending() const {
    for (int i = 1; i < size; ++i) {
        if (sequence[i - 1] < sequence[i]) {
            return false;  // ���� ������� ��������� ��������, ���������� false
        }
    }
    return true;  // ��� �������� ����������� �� ��������
}

// ��������, �������� �� ������������������ ������������
bool NumberSequence::isAscending() const {
    for (int i = 1; i < size; ++i) {
        if (sequence[i - 1] > sequence[i]) {
            return false;  // ���� ������� ��������� �����������, ���������� false
        }
    }
    return true;  // ��� �������� ����������� �� �����������
}

// ��������� ������������������ (���� �� ���������)
void NumberSequence::reverse() {
    for (int i = 0; i < size / 2; ++i) {
        double temp = sequence[i];
        sequence[i] = sequence[size - i - 1];
        sequence[size - i - 1] = temp;
    }
}

// �������������� ��������� ������������������ ��� ������������� sort
void NumberSequence::processAlternative() {
    if (isDescending()) {
        std::cout << "������������������ ���������. ������������ ������������� ����� � ������.\n";

        // ���������� �� ������������� � ������������� ����� �������
        int negCount = 0; // ������� ��� ������������� �����
        for (int i = 0; i < size; ++i) {
            if (sequence[i] < 0) {
                double temp = sequence[i];
                for (int j = i; j > negCount; --j) {
                    sequence[j] = sequence[j - 1];
                }
                sequence[negCount++] = temp;
            }
        }

        // ���������� ������������� ����� �� �������� ������� (���������� ���������)
        for (int i = 0; i < negCount - 1; ++i) {
            for (int j = 0; j < negCount - 1 - i; ++j) {
                if (sequence[j] < sequence[j + 1]) {
                    double temp = sequence[j];
                    sequence[j] = sequence[j + 1];
                    sequence[j + 1] = temp;
                }
            }
        }
    }
    else if (isAscending()) {
        std::cout << "������������������ ������������. ������������ ������������� ����� � ������.\n";

        // ���������� �� ������������� � ������������� ����� �������
        int posCount = 0; // ������� ��� ������������� �����
        for (int i = 0; i < size; ++i) {
            if (sequence[i] > 0) {
                double temp = sequence[i];
                for (int j = i; j > posCount; --j) {
                    sequence[j] = sequence[j - 1];
                }
                sequence[posCount++] = temp;
            }
        }

        // ���������� ������������� ����� �� �������� ������� (���������� ���������)
        for (int i = 0; i < posCount - 1; ++i) {
            for (int j = 0; j < posCount - 1 - i; ++j) {
                if (sequence[j] < sequence[j + 1]) {
                    double temp = sequence[j];
                    sequence[j] = sequence[j + 1];
                    sequence[j + 1] = temp;
                }
            }
        }
    }
    else {
        std::cout << "������������������ �� �����������. ������� ��������� �� ������������.\n";
    }
}
