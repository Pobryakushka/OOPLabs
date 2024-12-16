#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lab6.h"

void runDemo6() {
    setlocale(LC_ALL, "rus");
    std::srand(static_cast<unsigned int>(std::time(0))); // ������������� ���������� ��������� �����

    while (true) {
        int n, choice;
        customPrintf("�������� ������ ����� �������:", "\n",
            "1. ������ ������ �������", "\n",
            "2. ������������� ������ ��������� �������", "\n",
            "��� �����: ");
        std::cin >> choice;

        customPrintf("������� ���������� �����: ");
        std::cin >> n;

        // ������� ������ �������������� �������
        int* numbers = new int[n];

        if (choice == 1) {
            // ������ ����
            customPrintf("������� ", n, " ����� �����:\n");
            for (int i = 0; i < n; ++i) {
                std::cin >> numbers[i];
            }
        }
        else if (choice == 2) {
            // ��������� ��������� ����� �����
            for (int i = 0; i < n; ++i) {
                numbers[i] = std::rand() % 201 - 100; // ���������� ����� � ��������� [-100, 100]
            }

            // ������� ��������������� ������
            customPrintf("��������������� ������: ", 13, "a", "\n");
            for (int i = 0; i < n; ++i) {
                customPrintf(numbers[i], " ");
            }
            customPrintf("\n");
        }
        else {
            customPrintf("�������� �����!\n");
            delete[] numbers; // ����������� ������
            continue;
        }

        // �������� ������� � ���������� ����������
        NumberProcessor<int> processor(numbers, n);
        int result = processor.calculateSum();

        customPrintf("����� ������������� �����, ������� ����� �������� ������������� �����: ", result, "\n");

        // ����������� ������
        delete[] numbers;

        // �������� �� �����������
        char repeat;
        customPrintf("������ ��������� ��� ���? (y/n): ");
        std::cin >> repeat;
        if (repeat != 'y' && repeat != 'Y') {
            break;
        }
    }
}
