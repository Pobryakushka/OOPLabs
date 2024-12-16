#include "lab4.h"
#include <iostream>

void runDemo4() {
    setlocale(LC_ALL, "rus");

    while (true) {
        // Начальное меню
        std::cout << "Меню:\n";
        std::cout << "1. Начать выполнение программы\n";
        std::cout << "2. Выйти из программы\n";
        std::cout << "Ваш выбор: ";

        int choice;
        std::cin >> choice;

        if (choice == 2) {
            std::cout << "Выход из программы.\n";
            break;
        }
        else if (choice == 1) {
            // Основная логика программы
            std::cout << "=== Выполнение программы ===\n";

            STRING baseString;
            AdvancedString advString;

            // Демонстрация работы с базовым классом
            baseString.Setstrt((char*)"Hello");
            baseString.Strcat('!');
            baseString.Print();

            // Демонстрация работы с производным классом
            advString.Setstrt((char*)"Advanced");
            advString.Strcat('#');
            advString.Print();
        }
        else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

        // Конечное меню
        std::cout << "\nХотите продолжить?\n";
        std::cout << "1. Да\n";
        std::cout << "2. Нет\n";
        std::cout << "Ваш выбор: ";
        int exitChoice;
        std::cin >> exitChoice;

        if (exitChoice == 2) {
            std::cout << "Выход из программы.\n";
            break;
        }
    }
}