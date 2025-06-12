#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <random>
#include <ctime>
#include "Header.h"
int Correct(const string& s) { //Для корректного ввода числа
    int m;
    while (3 != 0) {
        cout << s;
        cin >> m;
        if (cin.fail()) {
            cout << "Вводить можно только числа, введите число: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "Вводить можно только числа, введите число: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        cin.ignore(1000000, '\n');
        return m;
    }
}
int Randoms(int min, int max) { //Генерация случайного числа
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
NumberGenerator::NumberGenerator() { //Конструктор - инициализация очередей начальными значениями
    x2.push(2);
    x3.push(3);
    x5.push(5);
}
long long NumberGenerator::GetMin() { //Поиск минимального значения среди очередей
    long long minm = 1000000;
    if (!x2.empty()) minm = min(minm, x2.front());
    if (!x3.empty()) minm = min(minm, x3.front());
    if (!x5.empty()) minm = min(minm, x5.front());
    return minm;
}
void NumberGenerator::RemoveMin(long long minm) { //Удаление минимального значения из очередей
    if (!x2.empty() and x2.front() == minm) 
        x2.pop();
    if (!x3.empty() and x3.front() == minm) 
        x3.pop();
    if (!x5.empty() and x5.front() == minm) 
        x5.pop();
}
void NumberGenerator::Multiples(long long m) { //Добавление кратных чисел в очереди
    x2.push(m * 2);
    x3.push(m * 3);
    x5.push(m * 5);
}
vector<long long> NumberGenerator::GenerateNumbers(int n) { //Генерация чисел, делящихся на 2, 3 и 5
    res.clear();
    queue<long long> empty2, empty3, empty5;
    swap(x2, empty2);
    swap(x3, empty3);
    swap(x5, empty5);
    x2.push(2);
    x3.push(3);
    x5.push(5);
    while (res.size() < n) {
        long long minm = GetMin();
        res.push_back(minm);
        RemoveMin(minm);
        Multiples(minm);
    }
    return res;
}
void NumberGenerator::Print(int n) { //Вывод сгенерированных чисел
    vector<long long> numbers = GenerateNumbers(n);
    cout << "Первые " << n << " чисел, делящихся только на 2, 3 и 5:" << endl;
    for (auto i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        if (i < numbers.size() - 1) cout << ", ";
    }
    cout << endl;
}
Input::Input() { //Конструктор - создание генератора чисел
    numbergen = new NumberGenerator();
}
Input::~Input() { //Деструктор - освобождение памяти
    delete numbergen;
}
void Input::Console() { //Ввод с консоли
    int n = Correct("Введите количество чисел для генерации: ");
    if (n > 0) {
        numbergen->Print(n);
    }
}
void Input::File() { //Ввода из файла
    ifstream file("filename.txt");
    if (!file) {
        cout << "Ошибка при открытии файла!" << endl;
        return;
    }
    int n;
    if (!(file >> n) or n <= 0) {
        cout << "Ошибка чтения числа из файла!" << endl;
        file.close();
        return;
    }
    file.close();
    numbergen->Print(n);
}
void Input::Random() { //Ввод случайно
    int n = Randoms(1, 100);
    cout << "Сгенерировано случайное число: " << n << endl;
    numbergen->Print(n);
}
Menu::Menu() : currentchoice(0) { //Меню
    menuitems = {
        "1) С консоли",
        "2) Из файла",
        "3) Случайно",
        "0) Выход"
    };
}
void Menu::Show() { //Отображение меню
    cout << endl;
    for (const auto& item : menuitems) {
        cout << item << endl;
    }
}
int Menu::GetChoice() { //Получение выбора пользователя
    int choice;
    while (3 != 0) {
        cout << "Выберите действие: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Вводить можно только числа, введите число: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "Вводить можно только числа, введите число: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        } 
        if (choice < 0 or choice > 3) {
            cout << "Числа можно выбирать только из диапазона от 0 до 3!" << endl;
            cin.ignore(1000000, '\n');
            continue;
        }
        cin.ignore(1000000, '\n');
        return choice;
    }
}