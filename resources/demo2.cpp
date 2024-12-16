#include "lab2.h"
#include <iostream>
using namespace std;

void runDemo2() {
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

            Matrix matrix;               // Создание объекта класса с автогенерацией размеров
            matrix.fillMatrix();         // Автозаполнение массива случайными числами
            matrix.findMinElements();    // Вывод всех минимальных элементов и их индексов
            matrix.findSpecialElement(); // Поиск максимального в строке и минимального в столбце
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