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

            STRING4 baseSTRING4;
            AdvancedSTRING4 advSTRING4;

            // Демонстрация работы с базовым классом
            baseSTRING4.Setstrt((char*)"Hello");
            baseSTRING4.Strcat('!');
            baseSTRING4.Print();

            // Демонстрация работы с производным классом
            advSTRING4.Setstrt((char*)"Advanced");
            advSTRING4.Strcat('#');
            advSTRING4.Print();
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