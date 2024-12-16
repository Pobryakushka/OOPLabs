#include "lab7.h"

void Demo::inputValues() {
    cout << "Введите значения f1, i, c1, f2, c2 (через пробел): ";
    cin >> f1 >> i >> c1 >> f2 >> c2;
    cout << endl;
}

tuple<float, int, char, float, char> Demo::getFields() const {
    return make_tuple(f1, i, c1, f2, c2);
}

string floatToHex(float value, int precision) {
    // Сохраняем знак
    bool isNegative = value < 0;
    if (isNegative) {
        value = fabs(value); // Берем абсолютное значение
    }

    // Разделяем целую и дробную части
    int intPart = static_cast<int>(value);              // Целая часть
    float fracPart = fabs(value - intPart);             // Дробная часть (положительная)

    stringstream ss;
    if (isNegative) {
        ss << "-"; // Добавляем знак минус для отрицательных чисел
    }
    ss << hex << uppercase << intPart;                  // Конвертируем целую часть в шестнадцатеричный формат

    string hexIntPart = ss.str();                       // Сохраняем целую часть
    ss.str("");                                         // Очищаем строку
    ss.clear();

    // Конвертируем дробную часть
    ss << ".";
    for (int i = 0; i < precision; ++i) {
        fracPart *= 16;                                 // Умножаем на основание системы (16)
        int digit = static_cast<int>(fracPart);         // Извлекаем целую часть
        fracPart -= digit;                              // Вычитаем целую часть
        ss << hex << uppercase << digit;               // Добавляем в строку
    }

    return hexIntPart + ss.str();                       // Объединяем целую и дробную части
}

void Demo::outputValues(const string& filename) const {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    cout << setfill('*') << setw(9);
    outFile << setfill('*') << setw(9);

    cout << "a" << endl;
    outFile << "a" << endl;

    // Вывод i в шестнадцатеричной системе
    cout << setw(9) << hex << uppercase << i << endl;
    outFile << setw(9) << hex << uppercase << i << endl;

    // Вывод f1 в шестнадцатеричной системе с 1, 2 и 3 знаками после запятой
    string f1Hex = floatToHex(f1, 1); // Преобразуем f1 в hex с 1 знаком после запятой
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    f1Hex = floatToHex(f1, 2); // Преобразуем f1 в hex с 3 знаками после запятой
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    f1Hex = floatToHex(f1, 3); // Преобразуем f1 в hex с 2 знаками после запятой
    cout << setw(9) << f1Hex << endl;
    outFile << setw(9) << f1Hex << endl;

    // Вывод c2 как символ
    cout << setw(9) << c2 << endl;
    outFile << setw(9) << c2 << endl;

    // Вывод f2 в шестнадцатеричной системе с 1, 2 и 3 знаками после запятой
    string f2Hex = floatToHex(f2, 1); // Преобразуем f2 в hex с 1 знаком после запятой
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    f2Hex = floatToHex(f2, 2); // Преобразуем f2 в hex с 3 знаками после запятой
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    f2Hex = floatToHex(f2, 3); // Преобразуем f2 в hex с 2 знаками после запятой
    cout << setw(9) << f2Hex << endl;
    outFile << setw(9) << f2Hex << endl;

    // Вывод c1 как символ
    cout << setw(9) << c1 << endl;
    outFile << setw(9) << c1 << endl;

    cout << "b" << endl;
    outFile << "b" << endl;

    outFile.close();

    cout << "Результат записан в файл " << filename << endl;
}


ostream& operator<<(ostream& os, const Manip& manip) {

    os << setw(manip.width);

    switch (manip.base) {
    case 8:
        os << oct; // Восьмеричная система
        break;
    case 16:
        os << hex; // Шестнадцатеричная система
        break;
    default:
        os << dec; // Десятичная система
        break;
    }

    os << fixed << setprecision(manip.precision);

    os << setfill(manip.fillchar);

    return os;
}