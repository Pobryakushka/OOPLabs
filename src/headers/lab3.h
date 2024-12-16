#ifndef LAB3_H
#define LAB3_H

class NumberSequence {
private:
    double* sequence;  // ��������� �� ������������ ������
    int size;          // ������ ������������������

public:
    // ����������� � ����������
    NumberSequence(int n);
    ~NumberSequence();

    // ����� ��� ��������� ��������� ������������������
    void generate();

    // ����� ��� ������� ����� ������������������
    void input();

    // ����� ��� ������ ������������������
    void output() const;

    // ����� ��� ��������, �������� �� ������������������ ���������
    bool isDescending() const;

    // ����� ��� ��������, �������� �� ������������������ ������������
    bool isAscending() const;

    // ����� ��� ���������� ������������������
    void reverse();

    // ����� ��� ��������� � �������������� ������
    void processAlternative();
};

#endif // LABN_H
