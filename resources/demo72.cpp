#include <iostream>
#include "lab7.h"

using namespace std;

void runDemo72() {
    setlocale(LC_ALL, "RUS");

    Demo demo;

    while (true) {
        cout << "�������� ��������:" << endl;
        cout << "1 - ���� ��������" << endl;
        cout << "2 - �������������� �������� � ������� ������������" << endl;
        cout << "3 - �����" << endl;
        cout << "��� �����: ";

        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "����� �� ���������." << endl;
            break;
        }
        else if (choice == 1) {
            // ���� ��������
            demo.inputValues();

            // ��������� ���� ����� ����� tuple
            auto fields = demo.getFields();
            cout << "�������� ����� tuple: "
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

            cout << "������� �������� ��� float: ";
            while (!(cin >> f_num) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������� ����!";
            }

            cout << "������� �������� ��� int: ";
            while (!(cin >> int_num) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������� ����!";
            }

            cout << "������� �������� ��� char: ";
            while (true){
                string input;
                cin >> input;

                if (input.length() == 1) {
                    char_value = input[0];
                    break;
                }
                else {
                    cout << "������������ ����!";
                }
            }

            // ������� �������������
            Manip manip_float(5, 8, 10, '#'); // ��������, ������, ���������, ����������
            Manip manip_int(0, 10, 16, '*');
            Manip manip_char(0, 5, 10, '.');

            cout << "��������� � ������������� ��� float: " << manip_float << f_num << endl;
            cout << "��������� � ������������� ��� int: " << manip_int << int_num << endl;
            cout << "��������� � ������������� ��� char: " << manip_char << char_value << endl;
        }
        else {
            cout << "������������ �����. ���������� �����." << endl;
        }
    }
}
