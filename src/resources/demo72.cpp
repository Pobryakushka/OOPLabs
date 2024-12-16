#include <iostream>
#include "lab7.h"

using namespace std;

void runDemo72() {
    setlocale(LC_ALL, "RUS");

    Demo demo;

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1 - Ввод значений" << endl;
        cout << "2 - Форматирование значений с помощью манипулятора" << endl;
        cout << "3 - Выход" << endl;
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "Выход из программы." << endl;
            break;
        }
        else if (choice == 1) {
            // Ввод значений
            demo.inputValues();

            // Получение всех полей через tuple
            auto fields = demo.getFields();
            cout << "Значения через tuple: "
                << "i = " << get<1>(fields) << ", "
                << "f1 = " << get<0>(fields) << ", "
                << "c2 = " << get<2>(fields) << ", "
                << "f2 = " << get<3>(fields) << ", "
                << "c1 = " << get<4>(fields) << endl;

            demo.outputValues("output.txt");
        }
        else if (choice == 2) {
            float f_num;
            int int_num;
            char char_value;

            cout << "Введите значение для float: ";
            while (!(cin >> f_num) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неккорекный ввод!";
            }

            cout << "Введите значение для int: ";
            while (!(cin >> int_num) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неккорекный ввод!";
            }

            cout << "Введите значение для char: ";
            while (true){
                string input;
                cin >> input;

                if (input.length() == 1) {
                    char_value = input[0];
                    break;
                }
                else {
                    cout << "Неккоректный ввод!";
                }
            }

            // Объекты манипуляторов
            Manip manip_float(5, 8, 10, '#'); // Точность, Ширина, Основание, Заполнение
            Manip manip_int(0, 10, 16, '*');
            Manip manip_char(0, 5, 10, '.');

            cout << "Результат с манипулятором для float: " << manip_float << f_num << endl;
            cout << "Результат с манипулятором для int: " << manip_int << int_num << endl;
            cout << "Результат с манипулятором для char: " << manip_char << char_value << endl;
        }
        else {
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }
}
