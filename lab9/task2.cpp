#include "task2.h"
#include <iostream>

using namespace std;
/*
    Функція is_valid
    Призначення:
        Перевірка чи містить рядок хоча б один пробіл
    Вхідні дані:
        str - вхідний рядок
    Вихідні дані:
        true  - якщо рядок містить хоча б один пробіл
        false - якщо пробілів немає
*/

    // Перевірка:
bool is_valid(const string& str) {
    return str.find(' ') != string::npos;
}

/*
    Функція process_string
    Призначення:
        Повертає підрядок, розташований між першим і останнім пробілом
    Вхідні дані:
        str - вхідний рядок
    Вихідні дані:
        підрядок між першим і останнім пробілом
        якщо пробіл лише один — повертається порожній рядок
*/
string process_string(const string& str) {  
    size_t first = str.find(' '); // позиція першого пробілу
    size_t last = str.rfind(' '); // позиція останнього пробілу

    // якщо тільки один пробіл
    if (first == last) return "";

    return str.substr(first + 1, last - first - 1);
}
 /*
    Функція task2
    Призначення:
        Виконати обробку рядка відповідно до умови задачі String40
    Вхідні дані:
        рядок введений користувачем
    Вихідні дані:
        результат обробки виводиться на екран
*/
void task2() {
    cout << "=== Завдання 2: String40 ===\n";

    string str;

    cout << "Введіть рядок: ";
    getline(cin, str);
 
    // перевірка коректності введеного рядка
    if (!is_valid(str)) {
        cout << "Помилка: рядок не містить пробілів\n";
        return;
    }
    // обробка рядка
    
    string result = process_string(str);
    // виведення результату
    cout << "Результат: " << result << endl;
}