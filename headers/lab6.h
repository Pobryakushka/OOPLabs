#ifndef LAB6_H
#define LAB6_H

#include <iostream>

// Шаблон класса NumberProcessor
template <typename T>
class NumberProcessor {
public:
    NumberProcessor(T* numbers, int size); // Конструктор принимает массив чисел и его размер
    T calculateSum(); // Метод для вычисления суммы

private:
    T* numbers; // Указатель на массив чисел
    int size;   // Размер массива
};

// Шаблон функции customPrintf
void customPrintf(); // Базовый случай для рекурсии

template <typename T, typename... Args>
void customPrintf(const T& first, const Args&... rest) {
    // Выводим текущий элемент
    std::cout << first;

    // Если есть еще элементы, выводим пробел
    if constexpr (sizeof...(rest) > 0) {
        std::cout << " ";
    }

    // Рекурсивно вызываем customPrintf для остальных аргументов
    customPrintf(rest...);
}

#endif
