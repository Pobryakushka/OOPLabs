#include "lab71.h"
#include <iostream>

void runDemo71() {
    setlocale(LC_ALL, "rus"); // Для корректного отображения русских символов
    STRING str1;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Показать текущую строку\n";
        std::cout << "2. Ввести строку с клавиатуры\n";
        std::cout << "3. Изменить строку с помощью Setstrt\n";
        std::cout << "4. Добавить символ в строку с помощью Strcat\n";
        std::cout << "5. Вывести строку с помощью метода Print\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите действие: ";

        int choice;
        std::cin >> choice;

        if (choice == 6) {
            std::cout << "Выход из программы.\n";
            break;
        }

        switch (choice) {
        case 1: // Показать текущую строку
            std::cout << "Текущая строка: " << str1 << std::endl;
            break;

        case 2: { // Ввести строку с клавиатуры
            std::cout << "Введите строку: ";
            std::cin >> str1;
            std::cout << "Вы ввели: " << str1 << std::endl;
            break;
        }

        case 3: { // Изменить строку с помощью Setstrt
            std::string newStr;
            std::cout << "Введите новую строку для Setstrt: ";
            std::cin >> newStr;
            str1.Setstrt(newStr.c_str());
            std::cout << "Строка изменена: " << str1 << std::endl;
            break;
        }

        case 4: { // Добавить символ в строку с помощью Strcat
            char ch;
            std::cout << "Введите символ для добавления: ";
            std::cin >> ch;
            str1.Strcat(ch);
            std::cout << "Строка после добавления символа: " << str1 << std::endl;
            break;
        }

        case 5: // Вывести строку с помощью метода Print
            std::cout << "Содержимое строки (метод Print): ";
            str1.Print();
            std::cout << std::endl;
            break;

        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    }
}