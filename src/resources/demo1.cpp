#include "lab1.h"
#include <iostream>

void runDemo1() {
    setlocale(LC_ALL, "ru");

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

            // 1. Инициализация пустой строки
            STRING1 str1;
            str1.Print(); // Ожидаемый вывод: пустая строка

            // 6. Изменение строки областью памяти
            str1.Setstrt("Hello");
            str1.Print(); // Ожидаемый вывод: Hello

            // 8. Добавление символа
            str1.Strcat('!');
            str1.Print(); // Ожидаемый вывод: Hello!

            // Создание еще одной строки
            STRING1 str2;
            str2.Setstrt("World");
            str2.Print(); // Ожидаемый вывод: World

            // Сложение строк
            STRING1 str3 = str1.Concat(str2); // Объявление str3 и присваивание результата сложения
            str3.Print(); // Ожидаемый вывод: Hello World

            STRING1 str10(str3);
            str10.Print(); // Ожидаемый вывод: Hello!

            // Используем дружественную функцию для вывода строки
            Print(str1); // Ожидаемый вывод: Hello!
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