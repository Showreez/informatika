#include <iostream>
#include <climits>
using namespace std;

int main() {
    int a, b;
    char op, target;

    cout << "Введите два числа: ";
    cin >> a >> b;

    cout << "\nВыберите операцию:\n";
    cout << "+  Сложение\n";
    cout << "-  Вычитание\n";
    cout << "*  Умножение\n";
    cout << "/  Деление\n";
    cout << "i  Инкремент (++ )\n";
    cout << "d  Декремент (-- )\n";
    cout << "Ваш выбор: ";
    cin >> op;

    if (op == 'i' || op == 'd') {
        cout << "Выберите переменную (a или b): ";
        cin >> target;

        if (target != 'a' && target != 'b') {
            cout << "Ошибка: неизвестная переменная.\n";
            return 0;
        }

        if (target == 'a') {
            if (op == 'i') {
                if (a == INT_MAX) {
                    cout << "Ошибка: переполнение при инкременте.\n";
                    return 0;
                }
                ++a;
            } else {
                if (a == INT_MIN) {
                    cout << "Ошибка: переполнение при декременте.\n";
                    return 0;
                }
                --a;
            }
            cout << "Результат: a = " << a << '\n';
        } else {
            if (op == 'i') {
                if (b == INT_MAX) {
                    cout << "Ошибка: переполнение при инкременте.\n";
                    return 0;
                }
                ++b;
            } else {
                if (b == INT_MIN) {
                    cout << "Ошибка: переполнение при декременте.\n";
                    return 0;
                }
                --b;
            }
            cout << "Результат: b = " << b << '\n';
        }

        return 0;
    }

    switch (op) {
        case '+':
            if ((b > 0 && a > INT_MAX - b) ||
                (b < 0 && a < INT_MIN - b)) {
                cout << "Ошибка: переполнение при сложении.\n";
                return 0;
            }
            a += b;
            break;

        case '-':
            if ((b < 0 && a > INT_MAX + b) ||
                (b > 0 && a < INT_MIN + b)) {
                cout << "Ошибка: переполнение при вычитании.\n";
                return 0;
            }
            a -= b;
            break;

        case '*':
            if (a > 0) {
                if ((b > 0 && a > INT_MAX / b) ||
                    (b < 0 && b < INT_MIN / a)) {
                    cout << "Ошибка: переполнение при умножении.\n";
                    return 0;
                }
            } else if (a < 0) {
                if ((b > 0 && a < INT_MIN / b) ||
                    (b < 0 && b < INT_MAX / a)) {
                    cout << "Ошибка: переполнение при умножении.\n";
                    return 0;
                }
            }
            a *= b;
            break;

        case '/':
            if (b == 0) {
                cout << "Ошибка: деление на ноль.\n";
                return 0;
            }
            if (a == INT_MIN && b == -1) {
                cout << "Ошибка: переполнение при делении.\n";
                return 0;
            }
            a /= b;
            break;

        default:
            cout << "Ошибка: неизвестная операция.\n";
            return 0;
    }

    cout << "Результат: " << a << '\n';

    return 0;
}
