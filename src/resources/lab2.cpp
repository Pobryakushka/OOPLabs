#include "lab2.h"
#include <iostream>
#include <cstdlib>   // ��� malloc, calloc � rand
#include <ctime>     // ��� ��������� ��������� �����

using namespace std;

Matrix::Matrix() {
    // ������������� ���������� ��������� �����
    srand(static_cast<unsigned>(time(0)));

    // ��������� ���������� ����� ��� ����� � �������� � ��������� �� 1 �� 10
    rows = rand() % 10 + 1;  // ������ �� 1 �� 10
    cols = rand() % 10 + 1;  // ������ �� 1 �� 10

    // ��������� ������ � �������������� calloc
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
    cout << "������ �������: " << rows << "x" << cols << endl;
    cout << "�������������� ������� ���������� �������:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // ��������� ���������� ����� � ��������� �� 0 �� 100
            array[i][j] = static_cast<float>(rand() % 101);
            cout << array[i][j] << " ";  // ������� ������� �� �����
        }
        cout << endl;
    }
}

void Matrix::findMinElements() {
    // ������� ����������� �������
    float min = array[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }

    // ����� ���� ����������� ��������� � �� ��������
    cout << "����������� �������: " << min << endl;
    cout << "����������� �������� ��������� �� ��������� ��������:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] == min) {
                cout << "������� [" << i << "][" << j << "] = " << array[i][j] << endl;
            }
        }
    }
}

void Matrix::findSpecialElement() {
    cout << "\n����� �����, ������� �������� ������������ � ������ � ����������� � �������:" << endl;

    bool found = false;  // ���� ��� �����������, ������ �� �������

    for (int i = 0; i < rows; ++i) {
        // ������� ������������ ������� � ������
        float rowMax = array[i][0];
        int colIndex = 0;
        for (int j = 1; j < cols; ++j) {
            if (array[i][j] > rowMax) {
                rowMax = array[i][j];
                colIndex = j;
            }
        }

        // ���������, �������� �� ���� ������� ����������� � ����� �������
        bool isMinInCol = true;
        for (int k = 0; k < rows; ++k) {
            if (array[k][colIndex] < rowMax) {
                isMinInCol = false;
                break;
            }
        }

        // ���� ������� ������, ������� ��� � ��� �������
        if (isMinInCol) {
            cout << "������� [" << i << "][" << colIndex << "] = " << rowMax
                << " �������� ������������ � ������ � ����������� � �������." << endl;
            found = true;
        }
    }

    // ���� �� ������� �� ������ ����������� ��������
    if (!found) {
        cout << "����� ��������� � ������� ���." << endl;
    }
}
