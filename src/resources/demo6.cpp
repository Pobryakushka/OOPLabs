#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lab6.h"

void runDemo6() {
    setlocale(LC_ALL, "rus");
    std::srand(static_cast<unsigned int>(std::time(0))); // Инициализация генератора случайных чисел

    while (true) {
        int n, choice;
        customPrintf("Выберите способ ввода массива:", "\n",
            "1. Ввести массив вручную", "\n",
            "2. Сгенерировать массив случайным образом", "\n",
            "Ваш выбор: ");
        std::cin >> choice;

        customPrintf("Введите количество чисел: ");
        std::cin >> n;

        // Создаем массив фиксированного размера
        int* numbers = new int[n];

        if (choice == 1) {
            // Ручной ввод
            customPrintf("Введите ", n, " целых чисел:\n");
            for (int i = 0; i < n; ++i) {
                std::cin >> numbers[i];
            }
        }
        else if (choice == 2) {
            // Генерация случайных целых чисел
            for (int i = 0; i < n; ++i) {
                numbers[i] = std::rand() % 201 - 100; // Генерируем числа в диапазоне [-100, 100]
            }

            // Выводим сгенерированный массив
            customPrintf("Сгенерированный массив: ", 13, "a", "\n");
            for (int i = 0; i < n; ++i) {
                customPrintf(numbers[i], " ");
            }
            customPrintf("\n");
        }
        else {
            customPrintf("Неверный выбор!\n");
            delete[] numbers; // Освобождаем память
            continue;
        }

        // Создание объекта и вычисление результата
        NumberProcessor<int> processor(numbers, n);
        int result = processor.calculateSum();

        customPrintf("Сумма положительных чисел, стоящих после нечетных отрицательных чисел: ", result, "\n");

        // Освобождаем память
        delete[] numbers;

        // Проверка на продолжение
        char repeat;
        customPrintf("Хотите выполнить ещё раз? (y/n): ");
        std::cin >> repeat;
        if (repeat != 'y' && repeat != 'Y') {
            break;
        }
    }
}
