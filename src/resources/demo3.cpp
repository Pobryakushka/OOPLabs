#include "lab3.h"
#include <iostream>

void runDemo3() {
    setlocale(LC_ALL, "rus");
    int n;
    int choice;

    while (true) {
        // Главное меню
        std::cout << "Меню:\n";
        std::cout << "1. Генерация случайной последовательности\n";
        std::cout << "2. Ввод последовательности вручную\n";
        std::cout << "3. Альтернативный режим работы\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите режим работы: ";
        std::cin >> choice;

        if (choice == 4) {
            // Выход из программы
            std::cout << "Завершение программы.\n";
            break;
        }

        if (choice == 1 || choice == 2 || choice == 3) {
            std::cout << "Введите количество элементов последовательности: ";
            std::cin >> n;

            // Создаем объект класса NumberSequence
            NumberSequence seq(n);

            if (choice == 1) {
                // Генерация случайной последовательности
                seq.generate();
                std::cout << "Сгенерированная последовательность:\n";
            }
            else if (choice == 2) {
                // Ручной ввод последовательности
                seq.input();
                std::cout << "Введённая последовательность:\n";
            }
            else if (choice == 3) {
                // Меню выбора в альтернативном режиме
                int altChoice;
                std::cout << "1. Генерация случайной последовательности\n";
                std::cout << "2. Ввод последовательности вручную\n";
                std::cout << "Выберите режим для альтернативного режима: ";
                std::cin >> altChoice;

                if (altChoice == 1) {
                    seq.generate();
                    std::cout << "Сгенерированная последовательность:\n";
                }
                else if (altChoice == 2) {
                    seq.input();
                    std::cout << "Введённая последовательность:\n";
                }
                else {
                    std::cout << "Неверный выбор! Возврат в главное меню.\n";
                    continue;
                }
            }

            // Выводим последовательность
            seq.output();

            // Если выбран альтернативный режим
            if (choice == 3) {
                seq.processAlternative();
                std::cout << "Измененная последовательность:\n";
                seq.output();
            }
            else {
                // Обычная проверка на убывание и переворот, если нужно
                if (seq.isDescending()) {
                    std::cout << "Последовательность уже упорядочена по убыванию.\n";
                }
                else {
                    std::cout << "Последовательность не является убывающей. Переворачиваем:\n";
                    seq.reverse();
                    seq.output();  // Выводим перевёрнутую последовательность
                }
            }
        }
        else {
            std::cout << "Неверный выбор! Попробуйте снова.\n";
        }

        // Возврат в меню после завершения работы
        std::cout << "Возврат в меню...\n\n";
    }
}
