#include <iostream>

// ���������� ��� ������
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab71.h"
#include "lab7.h"

// ��������� ������� �� ���������������� ������
void runDemo1();
void runDemo2();
void runDemo3();
void runDemo4();
void runDemo5();
void runDemo6();
void runDemo71();
void runDemo72();

int main() {
    system("chcp 1251");

    while (true) {
        std::cout << "\n������� ����:\n";
        std::cout << "1. ������ 1 (demo1)\n";
        std::cout << "2. ������ 2 (demo2)\n";
        std::cout << "3. ������ 3 (demo3)\n";
        std::cout << "4. ������ 4 (demo4)\n";
        std::cout << "5. ������ 5 (demo5)\n";
        std::cout << "6. ������ 6 (demo6)\n";
        std::cout << "7. ������ 7.1 (demo71)\n";
        std::cout << "8. ������ 7.2 (demo7)\n";
        std::cout << "9. �����\n";
        std::cout << "�������� ������ ��� ������������: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                runDemo1();
                break;
            case 2:
                runDemo2();
                break;
            case 3:
                runDemo3();
                break;
            case 4:
                runDemo4();
                break;
            case 5:
                runDemo5();
                break;
            case 6:
                runDemo6();
                break;
            case 7:
                runDemo71();
                break;
            case 8:
                runDemo72();
                break;
            case 9:
                std::cout << "����� �� ���������.\n";
                return 0;
            default:
                std::cout << "������������ �����. ���������� �����.\n";
                break;
        }
    }

    return 0;
}