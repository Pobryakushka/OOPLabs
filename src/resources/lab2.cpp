#include "lab2.h"
#include <iostream>
#include <cstdlib>   // Для malloc, calloc и rand
#include <ctime>     // Для генерации случайных чисел

using namespace std;

Matrix::Matrix() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(0)));

    // Генерация случайного числа для строк и столбцов в диапазоне от 1 до 10
    rows = rand() % 10 + 1;  // Размер от 1 до 10
    cols = rand() % 10 + 1;  // Размер от 1 до 10

    // Выделение памяти с использованием calloc
    array = (float**)calloc(rows, sizeof(float*));
    for (int i = 0; i < rows; ++i) {
        array[i] = (float*)calloc(cols, sizeof(float));
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);
}

void Matrix::fillMatrix() {
    cout << "Размер матрицы: " << rows << "x" << cols << endl;
    cout << "Автозаполнение массива случайными числами:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Генерация случайного числа в диапазоне от 0 до 100
            array[i][j] = static_cast<float>(rand() % 101);
            cout << array[i][j] << " ";  // Выводим элемент на экран
        }
        cout << endl;
    }
}

void Matrix::findMinElements() {
    // Находим минимальный элемент
    float min = array[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }

    // Вывод всех минимальных элементов и их индексов
    cout << "Минимальный элемент: " << min << endl;
    cout << "Минимальные элементы находятся по следующим индексам:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] == min) {
                cout << "Элемент [" << i << "][" << j << "] = " << array[i][j] << endl;
            }
        }
    }
}

void Matrix::findSpecialElement() {
    cout << "\nПоиск числа, которое является максимальным в строке и минимальным в столбце:" << endl;

    bool found = false;  // Флаг для определения, найден ли элемент

    for (int i = 0; i < rows; ++i) {
        // Находим максимальный элемент в строке
        float rowMax = array[i][0];
        int colIndex = 0;
        for (int j = 1; j < cols; ++j) {
            if (array[i][j] > rowMax) {
                rowMax = array[i][j];
                colIndex = j;
            }
        }

        // Проверяем, является ли этот элемент минимальным в своем столбце
        bool isMinInCol = true;
        for (int k = 0; k < rows; ++k) {
            if (array[k][colIndex] < rowMax) {
                isMinInCol = false;
                break;
            }
        }

        // Если элемент найден, выводим его и его индексы
        if (isMinInCol) {
            cout << "Элемент [" << i << "][" << colIndex << "] = " << rowMax
                << " является максимальным в строке и минимальным в столбце." << endl;
            found = true;
        }
    }

    // Если не найдено ни одного подходящего элемента
    if (!found) {
        cout << "Таких элементов в матрице нет." << endl;
    }
}
