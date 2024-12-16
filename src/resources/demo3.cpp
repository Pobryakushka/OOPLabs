#include "lab3.h"
#include <iostream>

void runDemo3() {
    setlocale(LC_ALL, "rus");
    int n;
    int choice;

    while (true) {
        // ������� ����
        std::cout << "����:\n";
        std::cout << "1. ��������� ��������� ������������������\n";
        std::cout << "2. ���� ������������������ �������\n";
        std::cout << "3. �������������� ����� ������\n";
        std::cout << "4. �����\n";
        std::cout << "�������� ����� ������: ";
        std::cin >> choice;

        if (choice == 4) {
            // ����� �� ���������
            std::cout << "���������� ���������.\n";
            break;
        }

        if (choice == 1 || choice == 2 || choice == 3) {
            std::cout << "������� ���������� ��������� ������������������: ";
            std::cin >> n;

            // ������� ������ ������ NumberSequence
            NumberSequence seq(n);

            if (choice == 1) {
                // ��������� ��������� ������������������
                seq.generate();
                std::cout << "��������������� ������������������:\n";
            }
            else if (choice == 2) {
                // ������ ���� ������������������
                seq.input();
                std::cout << "�������� ������������������:\n";
            }
            else if (choice == 3) {
                // ���� ������ � �������������� ������
                int altChoice;
                std::cout << "1. ��������� ��������� ������������������\n";
                std::cout << "2. ���� ������������������ �������\n";
                std::cout << "�������� ����� ��� ��������������� ������: ";
                std::cin >> altChoice;

                if (altChoice == 1) {
                    seq.generate();
                    std::cout << "��������������� ������������������:\n";
                }
                else if (altChoice == 2) {
                    seq.input();
                    std::cout << "�������� ������������������:\n";
                }
                else {
                    std::cout << "�������� �����! ������� � ������� ����.\n";
                    continue;
                }
            }

            // ������� ������������������
            seq.output();

            // ���� ������ �������������� �����
            if (choice == 3) {
                seq.processAlternative();
                std::cout << "���������� ������������������:\n";
                seq.output();
            }
            else {
                // ������� �������� �� �������� � ���������, ���� �����
                if (seq.isDescending()) {
                    std::cout << "������������������ ��� ����������� �� ��������.\n";
                }
                else {
                    std::cout << "������������������ �� �������� ���������. ��������������:\n";
                    seq.reverse();
                    seq.output();  // ������� ����������� ������������������
                }
            }
        }
        else {
            std::cout << "�������� �����! ���������� �����.\n";
        }

        // ������� � ���� ����� ���������� ������
        std::cout << "������� � ����...\n\n";
    }
}
