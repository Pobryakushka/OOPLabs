#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <cstring>

class STRING4 {
protected:
    char* str;

public:
    STRING4();                          // ����������� �� ���������
    STRING4(const STRING4& other);        // ����������� �����������
    STRING4& operator=(const STRING4& other); // �������� ������������
    virtual ~STRING4();                 // ����������� ����������
    virtual STRING4 Setstrt(char* what); // ����������� ������� ��� ��������� ������
    virtual STRING4 Strcat(char what);   // ����������� ������� ��� ���������� �������
    virtual void Print() const;         // ����������� ������� ��� ������ ������ �� �����
};

class AdvancedSTRING4 : public STRING4 {
public:
    AdvancedSTRING4();                   // ����������� �� ���������
    ~AdvancedSTRING4();                  // ����������
    STRING4 Setstrt(char* what) override; // ��������������� ������� ��������� ������
    STRING4 Strcat(char what) override;   // ��������������� ������� ���������� �������
    void Print() const override;         // ��������������� ������� ������ �� �����
};

#endif // LAB4_H
