#include "lab2.h"
#include <iostream>
using namespace std;

void runDemo2() {
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

            Matrix matrix;               // �������� ������� ������ � �������������� ��������
            matrix.fillMatrix();         // �������������� ������� ���������� �������
            matrix.findMinElements();    // ����� ���� ����������� ��������� � �� ��������
            matrix.findSpecialElement(); // ����� ������������� � ������ � ������������ � �������
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