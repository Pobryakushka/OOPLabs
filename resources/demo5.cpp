
#include "lab5.h"

void TestAssignments() {
    std::cout << "\n=== ���� ��������� ������������ ===" << std::endl;
    STRING str1("Hello");
    STRING str2("Assignment");
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // ���������� ������������
    str1 = str2;
    std::cout << "����� ������������ str1 = str2:" << std::endl;
    std::cout << "str1: " << str1 << std::endl;

    // ������������ ������������
    STRING str3("Temporary");
    std::cout << "str3 (�� move): " << str3 << std::endl;
    str1 = std::move(str3);
    std::cout << "����� ����������� str1 = std::move(str3):" << std::endl;
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str3 (����� move): " << str3 << std::endl;
}

void TestFunctor() {
    std::cout << "\n=== ���� �������� (��������()) ===" << std::endl;
    STRING str("Hello Functor");
    std::cout << "������: " << str << std::endl;
    std::cout << "����� ������ (str()): " << str() << std::endl;
}

void TestInputOutputOperators() {
    std::cout << "\n=== ���� ���������� �����/������ ===" << std::endl;
    STRING inputStr;
    std::cout << "������� ������: ";
    std::cin >> inputStr;
    std::cout << "��������� ������: " << inputStr << std::endl;
}

void TestComparisonAndConcatenation() {
    std::cout << "\n=== ���� ���������� ��������� � �������� ===" << std::endl;
    STRING str1("Hello");
    STRING str2("World");
    STRING str3("Hello");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    // �������� ���������
    if (str1 == str3) {
        std::cout << "str1 � str3 �����" << std::endl;
    }
    else {
        std::cout << "str1 � str3 �� �����" << std::endl;
    }

    // ������������ �����
    STRING concatenated = str1 + str2;
    std::cout << "��������� str1 + str2: " << concatenated << std::endl;
}

void runDemo5() {
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

            TestAssignments();
            TestFunctor();
            TestInputOutputOperators();
            TestComparisonAndConcatenation();
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
