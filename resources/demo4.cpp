#include "lab4.h"
#include <iostream>

void runDemo4() {
    setlocale(LC_ALL, "rus");

    while (true) {
        // ��������� ����
        std::cout << "����:\n";
        std::cout << "1. ������ ���������� ���������\n";
        std::cout << "2. ����� �� ���������\n";
        std::cout << "��� �����: ";

        int choice;
        std::cin >> choice;

        if (choice == 2) {
            std::cout << "����� �� ���������.\n";
            break;
        }
        else if (choice == 1) {
            // �������� ������ ���������
            std::cout << "=== ���������� ��������� ===\n";

            STRING baseString;
            AdvancedString advString;

            // ������������ ������ � ������� �������
            baseString.Setstrt((char*)"Hello");
            baseString.Strcat('!');
            baseString.Print();

            // ������������ ������ � ����������� �������
            advString.Setstrt((char*)"Advanced");
            advString.Strcat('#');
            advString.Print();
        }
        else {
            std::cout << "�������� �����. ���������� �����.\n";
        }

        // �������� ����
        std::cout << "\n������ ����������?\n";
        std::cout << "1. ��\n";
        std::cout << "2. ���\n";
        std::cout << "��� �����: ";
        int exitChoice;
        std::cin >> exitChoice;

        if (exitChoice == 2) {
            std::cout << "����� �� ���������.\n";
            break;
        }
    }
}