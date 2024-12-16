#include "lab3.h"
#include <iostream>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()

// Конструктор, выделяющий память под последовательность
NumberSequence::NumberSequence(int n) {
    size = n;  // сохраняем размер
    sequence = new double[size];  // динамически выделяем память
}

// Деструктор, освобождающий память
NumberSequence::~NumberSequence() {
    delete[] sequence;  // освобождаем память
}

// Генерация случайной последовательности
void NumberSequence::generate() {
    std::srand(static_cast<unsigned>(std::time(0)));  // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        sequence[i] = (std::rand() % 200 - 100) + static_cast<double>(std::rand()) / RAND_MAX;
        // Генерируем числа в диапазоне от -100 до 100 с дробной частью
    }
}

// Ручной ввод последовательности
void NumberSequence::input() {
    std::cout << "Введите последовательность из " << size << " чисел:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> sequence[i];
    }
}

// Вывод последовательности
void NumberSequence::output() const {
    for (int i = 0; i < size; ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

// Проверка, является ли последовательность убывающей (правильная реализация)
bool NumberSequence::isDescending() const {
    for (int i = 1; i < size; ++i) {
        if (sequence[i - 1] < sequence[i]) {
            return false;  // Если найдено нарушение убывания, возвращаем false
        }
    }
    return true;  // Все элементы упорядочены по убыванию
}

// Проверка, является ли последовательность возрастающей
bool NumberSequence::isAscending() const {
    for (int i = 1; i < size; ++i) {
        if (sequence[i - 1] > sequence[i]) {
            return false;  // Если найдено нарушение возрастания, возвращаем false
        }
    }
    return true;  // Все элементы упорядочены по возрастанию
}

// Переворот последовательности (если не убывающая)
void NumberSequence::reverse() {
    for (int i = 0; i < size / 2; ++i) {
        double temp = sequence[i];
        sequence[i] = sequence[size - i - 1];
        sequence[size - i - 1] = temp;
    }
}

// Альтернативная обработка последовательности без использования sort
void NumberSequence::processAlternative() {
    if (isDescending()) {
        std::cout << "Последовательность убывающая. Переставляем отрицательные числа в начало.\n";

        // Разделение на отрицательные и положительные числа вручную
        int negCount = 0; // Счётчик для отрицательных чисел
        for (int i = 0; i < size; ++i) {
            if (sequence[i] < 0) {
                double temp = sequence[i];
                for (int j = i; j > negCount; --j) {
                    sequence[j] = sequence[j - 1];
                }
                sequence[negCount++] = temp;
            }
        }

        // Сортировка отрицательных чисел по убыванию вручную (сортировка пузырьком)
        for (int i = 0; i < negCount - 1; ++i) {
            for (int j = 0; j < negCount - 1 - i; ++j) {
                if (sequence[j] < sequence[j + 1]) {
                    double temp = sequence[j];
                    sequence[j] = sequence[j + 1];
                    sequence[j + 1] = temp;
                }
            }
        }
    }
    else if (isAscending()) {
        std::cout << "Последовательность возрастающая. Переставляем положительные числа в начало.\n";

        // Разделение на положительные и отрицательные числа вручную
        int posCount = 0; // Счётчик для положительных чисел
        for (int i = 0; i < size; ++i) {
            if (sequence[i] > 0) {
                double temp = sequence[i];
                for (int j = i; j > posCount; --j) {
                    sequence[j] = sequence[j - 1];
                }
                sequence[posCount++] = temp;
            }
        }

        // Сортировка положительных чисел по убыванию вручную (сортировка пузырьком)
        for (int i = 0; i < posCount - 1; ++i) {
            for (int j = 0; j < posCount - 1 - i; ++j) {
                if (sequence[j] < sequence[j + 1]) {
                    double temp = sequence[j];
                    sequence[j] = sequence[j + 1];
                    sequence[j + 1] = temp;
                }
            }
        }
    }
    else {
        std::cout << "Последовательность не упорядочена. Никаких изменений не производится.\n";
    }
}
