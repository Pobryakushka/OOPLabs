#include "lab6.h"

// Реализация методов класса NumberProcessor
template <typename T>
NumberProcessor<T>::NumberProcessor(T* numbers, int size) : numbers(numbers), size(size) {}

template <typename T>
T NumberProcessor<T>::calculateSum() {
    T totalSum = 0;

    for (int i = 0; i < size - 1; ++i) {
        // Проверяем, что текущий элемент отрицательный и нечетный
        if (numbers[i] < 0 && static_cast<int>(numbers[i]) % 2 != 0) {
            // Проверяем только следующий элемент
            if (numbers[i + 1] > 0) {
                totalSum += numbers[i + 1];
            }
        }
    }

    return totalSum;
}

// Базовый случай для customPrintf
void customPrintf() {
}

// Явная инстанцизация шаблона класса
template class NumberProcessor<int>;
template class NumberProcessor<double>;
