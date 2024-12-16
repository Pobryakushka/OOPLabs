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

            STRING4 baseSTRING4;
            AdvancedSTRING4 advSTRING4;

            // ������������ ������ � ������� �������
            baseSTRING4.Setstrt((char*)"Hello");
            baseSTRING4.Strcat('!');
            baseSTRING4.Print();

            // ������������ ������ � ����������� �������
            advSTRING4.Setstrt((char*)"Advanced");
            advSTRING4.Strcat('#');
            advSTRING4.Print();
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