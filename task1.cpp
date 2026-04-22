#include "task1.h"
#include <iostream>
#include <string>

using namespace std;

/*
    Призначення:
        Виконує вставку одного рядка в інший (аналог методу string::insert)
    Вхідні дані:
        str - вихідний рядок 
        pos - позиція вставки
        insertStr - рядок для вставки
    Вихідні дані:
        змінений рядок після вставки
*/
void my_insert(char* str, int pos, const char* insertStr) {
    int len = 0;
    while (str[len] != '\0') len++; // визначення довжини рядка

    int insertLen = 0;
    while (insertStr[insertLen] != '\0') insertLen++; // довжина рядка вставки

    // перевірка коректності позиції
    if (pos < 0 || pos > len) return;

    // Зсув символів вправо
    for (int i = len; i >= pos; --i) {
        str[i + insertLen] = str[i];
    }

    // Вставка нового рядка
    for (int i = 0; i < insertLen; ++i) {
        str[pos + i] = insertStr[i];
    }
}
 /* Призначення:
        Демонструє роботу стандартного методу string::insert
        та власної функції my_insert
    Вхідні дані:
        input - вихідний рядок
        insertStr - рядок для вставки
        pos - позиція вставки
    Вихідні дані:
    результати роботи виводяться на екран */
    
void task1() {
    cout << "=== Завдання 1: string::insert ===\n";

    string input, insertStr;
    size_t pos;

    cout << "Введіть рядок: ";
    getline(cin, input);

    cout << "Введіть рядок для вставки: ";
    getline(cin, insertStr);

    cout << "Введіть позицію: ";
    cin >> pos;
    cin.ignore();

    // Використання std::string 
    string stdResult = input;

    if (pos <= stdResult.length()) {
        stdResult.insert(pos, insertStr);
        cout << "\nРезультат (std::string):\n" << stdResult << endl;
    } else {
        cout << "Помилка: позиція виходить за межі рядка\n";
    }

    // Робота з масивом char[] 
    char buffer[1000];
    input.copy(buffer, input.length());
    buffer[input.length()] = '\0';

    char insertBuffer[500];
    insertStr.copy(insertBuffer, insertStr.length());
    insertBuffer[insertStr.length()] = '\0';
    
    // виклик власної функції
    if (pos <= input.length()) {
        my_insert(buffer, pos, insertBuffer);
        cout << "Результат (власна функція):\n" << buffer << endl;
    }
}