#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
class NumberGenerator { //Класс для генерации чисел, делящихся только на 2, 3 и 5
private:
    queue<long long> x2, x3, x5;
    vector<long long> res;
    long long GetMin(); //Поиск минимального значения среди очередей
    void RemoveMin(long long minm); //Удаление минимального значения из очередей
    void Multiples(long long m); //Добавление кратных чисел в очереди
public:
    NumberGenerator(); //Конструктор - инициализация очередей начальными значениями
    vector<long long> GenerateNumbers(int n); //Генерация чисел, делящихся на 2, 3 и 5
    void Print(int n); //Вывод сгенерированных чисел
};
class Input { //Класс для ввода данных разными способами
private:
    NumberGenerator* numbergen;
public:
    Input(); //Конструктор - создание генератора чисел
    ~Input(); //Деструктор - освобождение памяти
    void Console(); //Ввод с консоли
    void File(); //Ввод из файла
    void Random(); //Ввод случайно
};
class Menu { //Класс, управляющий меню программы
private:
    vector<string> menuitems;
    int currentchoice;
public:
    Menu(); //Меню
    void Show(); //Отображение меню
    int GetChoice(); //Получение выбора пользователя
};
int Correct(const string& s); //Для корректного ввода числа
int Randoms(int min, int max); //Генерация случайного числа

