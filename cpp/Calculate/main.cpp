#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Одна дробь
struct Fraction {
  Fraction(const char* name) {
    cout << name << ". Введите все коэффициенты:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
  }

  double a, b; // Числитель
  double c, d; // Знаменатель дроби

  // Вывод числителя дроби
  void showNumerator() {
    cout << "    " << setw(6) << a << "*x + " << setw(6) << b;
  }

  // Вывод знаменателя дроби
  void showDenominator() {
    cout << "    " << setw(6) << c << "*x + " << setw(6) << d;
  }

  // Вывод области допустимых значений
  // (чему не может быть равен x)
  void ODZ() {
    cout << "    x != " << -d / c << endl;
  }
};


// Массив решений уравнения
double x[2];

int sqEq(double a, double b, double c) { // Возвращает количество решений
  // b^2 - 4ac
  double D = pow(b, 2) - 4 * a * c;
  cout << "D = " << pow(b, 2) << " - 4 * " << a << " * " << c << " = " << D << endl;
  // Одно решение
  if (D == 0) {
    x[0] = -b / (2 * a);
    cout << "1: x = " << x[0] << endl;
    return 1;
  }
  // sqrt = square root = квадратный корень
  if (D > 0) {
    cout << "x_1,2 = (" << -b << " +- " << sqrt(D) << ") / (2 * " << a << ")" << endl;
    x[0] = (-b - sqrt(D)) / (2 * a);
    x[1] = (-b + sqrt(D)) / (2 * a);
    cout << "2: x1 = " << x[0] << " x2 = " << x[1] << endl;
    return 2; // 2 решения
  }
  if (D < 0)
    cout << "No solutions" << endl;
  return 0;
}


int main() {
  cout << "Программа для решения уравнений вида:" << endl;
  cout << " 2*x+3    5*x + 2" << endl;
  cout << "------- + ------- = 0" << endl;
  cout << " 4*x-1    5*x + 2" << endl;

  cout << "В общем виде уравнение выглядит так:" << endl;
  cout << "    f1.a*x + f1.b     f2.a*x + f2.b" << endl;
  cout << "   --------------- + --------------- = 0" << endl;
  cout << "    f1.c*x + f1.d     f1.c*x + f1.d " << endl;

  // Две дроби
  Fraction f1("Первая дробь");
  Fraction f2("Вторая дробь");
  f1.showNumerator();
  cout << "       ";
  f2.showNumerator();
  cout << endl;
  cout << "   -------------------------- + ----------------------- = 0" << endl;
  f1.showDenominator();
  cout << "       ";
  f2.showDenominator();
  cout << endl;

  // Выводим чему не равен x
  f1.ODZ();
  f2.ODZ();

  // (f1.a*x+f1.b)*(f2.c*x+f2.d)+(f2.a*x+f2.b)*(f1.c*x+f1.d)
  int roots = sqEq(
                f1.a * f2.c + f2.a * f1.c,     // a
                f1.a * f2.d + f1.b * f2.c + f2.a * f1.d + f2.b * f1.c, // b
                f1.b * f2.d + f2.b * f1.d  // с
              );
  // Сейчас roots - количество корней
  // Теперь проверяем эти корни
  for (int i = 0; i < roots; i++) {
    double v = (f1.a * x[i] + f1.b) * (f2.c * x[i] + f2.d) +
               (f2.a * x[i] + f2.b) * (f1.c * x[i] + f1.d);
    cout << "Для x = " << x[i] << " получается " << v << endl;
  }

  return 0;
}

