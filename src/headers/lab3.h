#ifndef LAB3_H
#define LAB3_H

class NumberSequence {
private:
    double* sequence;  // Указатель на динамический массив
    int size;          // Размер последовательности

public:
    // Конструктор и деструктор
    NumberSequence(int n);
    ~NumberSequence();

    // Метод для генерации случайной последовательности
    void generate();

    // Метод для ручного ввода последовательности
    void input();

    // Метод для вывода последовательности
    void output() const;

    // Метод для проверки, является ли последовательность убывающей
    bool isDescending() const;

    // Метод для проверки, является ли последовательность возрастающей
    bool isAscending() const;

    // Метод для переворота последовательности
    void reverse();

    // Метод для обработки в альтернативном режиме
    void processAlternative();
};

#endif // LABN_H
