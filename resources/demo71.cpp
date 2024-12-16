#include "lab71.h"
#include <iostream>

void runDemo71() {
    setlocale(LC_ALL, "rus"); // ��� ����������� ����������� ������� ��������
    STRING str1;

    while (true) {
        std::cout << "\n����:\n";
        std::cout << "1. �������� ������� ������\n";
        std::cout << "2. ������ ������ � ����������\n";
        std::cout << "3. �������� ������ � ������� Setstrt\n";
        std::cout << "4. �������� ������ � ������ � ������� Strcat\n";
        std::cout << "5. ������� ������ � ������� ������ Print\n";
        std::cout << "6. �����\n";
        std::cout << "�������� ��������: ";

        int choice;
        std::cin >> choice;

        if (choice == 6) {
            std::cout << "����� �� ���������.\n";
            break;
        }

        switch (choice) {
        case 1: // �������� ������� ������
            std::cout << "������� ������: " << str1 << std::endl;
            break;

        case 2: { // ������ ������ � ����������
            std::cout << "������� ������: ";
            std::cin >> str1;
            std::cout << "�� �����: " << str1 << std::endl;
            break;
        }

        case 3: { // �������� ������ � ������� Setstrt
            std::string newStr;
            std::cout << "������� ����� ������ ��� Setstrt: ";
            std::cin >> newStr;
            str1.Setstrt(newStr.c_str());
            std::cout << "������ ��������: " << str1 << std::endl;
            break;
        }

        case 4: { // �������� ������ � ������ � ������� Strcat
            char ch;
            std::cout << "������� ������ ��� ����������: ";
            std::cin >> ch;
            str1.Strcat(ch);
            std::cout << "������ ����� ���������� �������: " << str1 << std::endl;
            break;
        }

        case 5: // ������� ������ � ������� ������ Print
            std::cout << "���������� ������ (����� Print): ";
            str1.Print();
            std::cout << std::endl;
            break;

        default:
            std::cout << "������������ �����. ���������� �����.\n";
            break;
        }
    }
}