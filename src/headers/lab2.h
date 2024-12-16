#ifndef LAB2_H
#define LAB2_H

class Matrix {
private:
    float** array;  // ��������� ������
    int rows;       // ���������� �����
    int cols;       // ���������� ��������

public:
    Matrix();               // ����������� ��� ����������
    ~Matrix();              // ����������
    void fillMatrix();       // ����� ��� ���������� ���������� �������
    void findMinElements();  // ����� ��� ���������� � ������ ���� ����������� ��������� � �� ��������
    void findSpecialElement(); // ����� ��� ������ ������������� � ������ � ������������ � �������
};

#endif
