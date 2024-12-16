#include "lab1.h"
#include <iostream>

void runDemo1() {
    setlocale(LC_ALL, "ru");

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

            // 1. ������������� ������ ������
            STRING1 str1;
            str1.Print(); // ��������� �����: ������ ������

            // 6. ��������� ������ �������� ������
            str1.Setstrt("Hello");
            str1.Print(); // ��������� �����: Hello

            // 8. ���������� �������
            str1.Strcat('!');
            str1.Print(); // ��������� �����: Hello!

            // �������� ��� ����� ������
            STRING1 str2;
            str2.Setstrt("World");
            str2.Print(); // ��������� �����: World

            // �������� �����
            STRING1 str3 = str1.Concat(str2); // ���������� str3 � ������������ ���������� ��������
            str3.Print(); // ��������� �����: Hello World

            STRING1 str10(str3);
            str10.Print(); // ��������� �����: Hello!

            // ���������� ������������� ������� ��� ������ ������
            Print(str1); // ��������� �����: Hello!
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