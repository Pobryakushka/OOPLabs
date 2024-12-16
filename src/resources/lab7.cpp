#include "lab7.h"

void Demo::inputValues() {
    cout << "������� �������� f1, i, c1, f2, c2 (����� ������): ";
    cin >> f1 >> i >> c1 >> f2 >> c2;
    cout << endl;
}

tuple<float, int, char, float, char> Demo::getFields() const {
    return make_tuple(f1, i, c1, f2, c2);
}

string floatToHex(float value, int precision) {
    // ��������� ����
    bool isNegative = value < 0;
    if (isNegative) {
        value = fabs(value); // ����� ���������� ��������
    }

    // ��������� ����� � ������� �����
    int intPart = static_cast<int>(value);              // ����� �����
    float fracPart = fabs(value - intPart);             // ������� ����� (�������������)

    stringstream ss;
    if (isNegative) {
        ss << "-"; // ��������� ���� ����� ��� ������������� �����
    }
    ss << hex << uppercase << intPart;                  // ������������ ����� ����� � ����������������� ������

    string hexIntPart = ss.str();                       // ��������� ����� �����
    ss.str("");                                         // ������� ������
    ss.clear();

    // ������������ ������� �����
    ss << ".";
    for (int i = 0; i < precision; ++i) {
        fracPart *= 16;                                 // �������� �� ��������� ������� (16)
        int digit = static_cast<int>(fracPart);         // ��������� ����� �����
        fracPart -= digit;                              // �������� ����� �����
        ss << hex << uppercase << digit;               // ��������� � ������
    }

    return hexIntPart + ss.str();                       // ���������� ����� � ������� �����
}

void Demo::outputValues(const string& filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "������ �������� ����� ��� ������." << endl;
        return;
    }

    cout << setfill('*') << setw(9);
    outFile << setfill('*') << setw(9);

    cout << "a" << endl;
    outFile << "a" << endl;

    // ����� i � ����������������� �������
    cout << setw(9) << hex << uppercase << i << endl;
    outFile << setw(9) << hex << uppercase << i << endl;

    // ����� f1 � ����������������� ������� � 1, 2 � 3 ������� ����� �������
    string f1Hex = floatToHex(f1, 1); // ����������� f1 � hex � 1 ������ ����� �������
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    f1Hex = floatToHex(f1, 2); // ����������� f1 � hex � 3 ������� ����� �������
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    f1Hex = floatToHex(f1, 3); // ����������� f1 � hex � 2 ������� ����� �������
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    // ����� c2 ��� ������
    cout << setw(9) << c2 << endl;
    outFile << setw(9) << c2 << endl;

    // ����� f2 � ����������������� ������� � 1, 2 � 3 ������� ����� �������
    string f2Hex = floatToHex(f2, 1); // ����������� f2 � hex � 1 ������ ����� �������
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    f2Hex = floatToHex(f2, 2); // ����������� f2 � hex � 3 ������� ����� �������
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    f2Hex = floatToHex(f2, 3); // ����������� f2 � hex � 2 ������� ����� �������
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    // ����� c1 ��� ������
    cout << setw(9) << c1 << endl;
    outFile << setw(9) << c1 << endl;

    cout << "b" << endl;
    outFile << "b" << endl;

    outFile.close();

    cout << "��������� ������� � ���� " << filename << endl;
}


ostream& operator<<(ostream& os, const Manip& manip) {

    os << setw(manip.width);

    switch (manip.base) {
    case 8:
        os << oct; // ������������ �������
        break;
    case 16:
        os << hex; // ����������������� �������
        break;
    default:
        os << dec; // ���������� �������
        break;
    }

    os << fixed << setprecision(manip.precision);

    os << setfill(manip.fillchar);

    return os;
}