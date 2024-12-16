
#include "lab5.h"

void TestAssignments() {
    std::cout << "\n=== Тест оператора присваивания ===" << std::endl;
    STRING str1("Hello");
    STRING str2("Assignment");
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    // Копирующее присваивание
    str1 = str2;
    std::cout << "После присваивания str1 = str2:" << std::endl;
    std::cout << "str1: " << str1 << std::endl;

    // Перемещающее присваивание
    STRING str3("Temporary");
    std::cout << "str3 (до move): " << str3 << std::endl;
    str1 = std::move(str3);
    std::cout << "После перемещения str1 = std::move(str3):" << std::endl;
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str3 (после move): " << str3 << std::endl;
}

void TestFunctor() {
    std::cout << "\n=== Тест функтора (оператор()) ===" << std::endl;
    STRING str("Hello Functor");
    std::cout << "Строка: " << str << std::endl;
    std::cout << "Длина строки (str()): " << str() << std::endl;
}

void TestInputOutputOperators() {
    std::cout << "\n=== Тест операторов ввода/вывода ===" << std::endl;
    STRING inputStr;
    std::cout << "Введите строку: ";
    std::cin >> inputStr;
    std::cout << "Введенная строка: " << inputStr << std::endl;
}

void TestComparisonAndConcatenation() {
    std::cout << "\n=== Тест операторов сравнения и сложения ===" << std::endl;
    STRING str1("Hello");
    STRING str2("World");
    STRING str3("Hello");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    // Проверка сравнения
    if (str1 == str3) {
        std::cout << "str1 и str3 равны" << std::endl;
    }
    else {
        std::cout << "str1 и str3 не равны" << std::endl;
    }

    // Конкатенация строк
    STRING concatenated = str1 + str2;
    std::cout << "Результат str1 + str2: " << concatenated << std::endl;
}

void runDemo5() {
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

            TestAssignments();
            TestFunctor();
            TestInputOutputOperators();
            TestComparisonAndConcatenation();
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
