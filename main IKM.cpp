#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <random>
#include <ctime>
#include "Header.h"
int main() {
    setlocale(LC_ALL, "Russian");
    Menu menu;
    Input input;
    bool r = true;
    cout << "����� ���������� � ��������� ��������� �����!" << endl;
    cout << "��������� ���������� �����, ��������� ������ �� 2, 3 � 5" << endl;
    while (r) {
        menu.Show();
        int choice = menu.GetChoice();
        switch (choice) {
            case 1:
                input.Console();
                break;
            case 2:
                input.File();
                break;
            case 3:
                input.Random();
                break;
            case 0:
                r = false;
                cout << "������� �� ������������� ���������!" << endl;
                break;
        }
    }
}

