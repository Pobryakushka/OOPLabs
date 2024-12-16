#ifndef LAB7_H
#define LAB7_H

#include <tuple>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Demo {
private:
    float f1, f2;
    char c1, c2;
    int i;

public:
    //  онструктор по умолчанию
    Demo() : f1(0), f2(0), c1(' '), i(0), c2(' ') {}

    void inputValues();

    // ћетод дл€ получени€ всех полей в виде кортежа
    tuple<float, int, char, float, char> getFields() const;

    void outputValues(const string& filename) const;
};

class Manip {
private:
    int width;
    int base;
    int precision;
    char fillchar;

public:
    Manip(int p, int w, int b, char f) : precision(p), width(w), base(b), fillchar(f) {}

    friend ostream& operator<<(ostream& os, const Manip& manip);
};

// ѕреобразование float в шестнадцатеричный формат
string floatToHex(float value, int precision = 10);

#endif // LAB7_H
