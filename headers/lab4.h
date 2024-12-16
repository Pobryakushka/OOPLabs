#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cstring>

class STRING {
protected:
    char* str;

public:
    STRING();                          // ����������� �� ���������
    STRING(const STRING& other);        // ����������� �����������
    STRING& operator=(const STRING& other); // �������� ������������
    virtual ~STRING();                 // ����������� ����������
    virtual STRING Setstrt(char* what); // ����������� ������� ��� ��������� ������
    virtual STRING Strcat(char what);   // ����������� ������� ��� ���������� �������
    virtual void Print() const;         // ����������� ������� ��� ������ ������ �� �����
};

class AdvancedString : public STRING {
public:
    AdvancedString();                   // ����������� �� ���������
    ~AdvancedString();                  // ����������
    STRING Setstrt(char* what) override; // ��������������� ������� ��������� ������
    STRING Strcat(char what) override;   // ��������������� ������� ���������� �������
    void Print() const override;         // ��������������� ������� ������ �� �����
};

#endif // LAB4_H
