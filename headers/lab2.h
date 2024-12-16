#ifndef LAB2_H
#define LAB2_H

class Matrix {
private:
    float** array;  // Двумерный массив
    int rows;       // Количество строк
    int cols;       // Количество столбцов

public:
    Matrix();               // Конструктор без параметров
    ~Matrix();              // Деструктор
    void fillMatrix();       // Метод для случайного заполнения массива
    void findMinElements();  // Метод для нахождения и вывода всех минимальных элементов и их индексов
    void findSpecialElement(); // Метод для поиска максимального в строке и минимального в столбце
};

#endif
