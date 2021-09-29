#include<iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "Введите а: ";
    cin >> a;
    cout << a;
    return 0;
}