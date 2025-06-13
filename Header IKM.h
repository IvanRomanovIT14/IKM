#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
class NumberGenerator { //����� ��� ��������� �����, ��������� ������ �� 2, 3 � 5
private:
    queue<long long> x2, x3, x5;
    vector<long long> res;
    long long GetMin(); //����� ������������ �������� ����� ��������
    void RemoveMin(long long minm); //�������� ������������ �������� �� ��������
    void Multiples(long long m); //���������� ������� ����� � �������
public:
    NumberGenerator(); //����������� - ������������� �������� ���������� ����������
    vector<long long> GenerateNumbers(int n); //��������� �����, ��������� �� 2, 3 � 5
    void Print(int n); //����� ��������������� �����
};
class Input { //����� ��� ����� ������ ������� ���������
private:
    NumberGenerator* numbergen;
public:
    Input(); //����������� - �������� ���������� �����
    ~Input(); //���������� - ������������ ������
    void Console(); //���� � �������
    void File(); //���� �� �����
    void Random(); //���� ��������
};
class Menu { //�����, ����������� ���� ���������
private:
    vector<string> menuitems;
    int currentchoice;
public:
    Menu(); //����
    void Show(); //����������� ����
    int GetChoice(); //��������� ������ ������������
};
int Correct(const string& s); //��� ����������� ����� �����
int Randoms(int min, int max); //��������� ���������� �����

