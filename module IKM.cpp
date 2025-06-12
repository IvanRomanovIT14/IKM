#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <random>
#include <ctime>
#include "Header.h"
int Correct(const string& s) { //��� ����������� ����� �����
    int m;
    while (3 != 0) {
        cout << s;
        cin >> m;
        if (cin.fail()) {
            cout << "������� ����� ������ �����, ������� �����: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "������� ����� ������ �����, ������� �����: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        cin.ignore(1000000, '\n');
        return m;
    }
}
int Randoms(int min, int max) { //��������� ���������� �����
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
NumberGenerator::NumberGenerator() { //����������� - ������������� �������� ���������� ����������
    x2.push(2);
    x3.push(3);
    x5.push(5);
}
long long NumberGenerator::GetMin() { //����� ������������ �������� ����� ��������
    long long minm = 1000000;
    if (!x2.empty()) minm = min(minm, x2.front());
    if (!x3.empty()) minm = min(minm, x3.front());
    if (!x5.empty()) minm = min(minm, x5.front());
    return minm;
}
void NumberGenerator::RemoveMin(long long minm) { //�������� ������������ �������� �� ��������
    if (!x2.empty() and x2.front() == minm) 
        x2.pop();
    if (!x3.empty() and x3.front() == minm) 
        x3.pop();
    if (!x5.empty() and x5.front() == minm) 
        x5.pop();
}
void NumberGenerator::Multiples(long long m) { //���������� ������� ����� � �������
    x2.push(m * 2);
    x3.push(m * 3);
    x5.push(m * 5);
}
vector<long long> NumberGenerator::GenerateNumbers(int n) { //��������� �����, ��������� �� 2, 3 � 5
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
void NumberGenerator::Print(int n) { //����� ��������������� �����
    vector<long long> numbers = GenerateNumbers(n);
    cout << "������ " << n << " �����, ��������� ������ �� 2, 3 � 5:" << endl;
    for (auto i = 0; i < numbers.size(); ++i) {
        cout << numbers[i];
        if (i < numbers.size() - 1) cout << ", ";
    }
    cout << endl;
}
Input::Input() { //����������� - �������� ���������� �����
    numbergen = new NumberGenerator();
}
Input::~Input() { //���������� - ������������ ������
    delete numbergen;
}
void Input::Console() { //���� � �������
    int n = Correct("������� ���������� ����� ��� ���������: ");
    if (n > 0) {
        numbergen->Print(n);
    }
}
void Input::File() { //����� �� �����
    ifstream file("filename.txt");
    if (!file) {
        cout << "������ ��� �������� �����!" << endl;
        return;
    }
    int n;
    if (!(file >> n) or n <= 0) {
        cout << "������ ������ ����� �� �����!" << endl;
        file.close();
        return;
    }
    file.close();
    numbergen->Print(n);
}
void Input::Random() { //���� ��������
    int n = Randoms(1, 100);
    cout << "������������� ��������� �����: " << n << endl;
    numbergen->Print(n);
}
Menu::Menu() : currentchoice(0) { //����
    menuitems = {
        "1) � �������",
        "2) �� �����",
        "3) ��������",
        "0) �����"
    };
}
void Menu::Show() { //����������� ����
    cout << endl;
    for (const auto& item : menuitems) {
        cout << item << endl;
    }
}
int Menu::GetChoice() { //��������� ������ ������������
    int choice;
    while (3 != 0) {
        cout << "�������� ��������: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "������� ����� ������ �����, ������� �����: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "������� ����� ������ �����, ������� �����: " << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
            continue;
        } 
        if (choice < 0 or choice > 3) {
            cout << "����� ����� �������� ������ �� ��������� �� 0 �� 3!" << endl;
            cin.ignore(1000000, '\n');
            continue;
        }
        cin.ignore(1000000, '\n');
        return choice;
    }
}