#include <iostream>

using namespace std;

void main() {

    setlocale(0, "");
    int a = 3;
    int b = 5;

    int temp = a;
    a = b;
    b = temp;

    cout << "Новое значение a = " << a << endl;
    cout << "Новое значение b = " << b << endl;
}