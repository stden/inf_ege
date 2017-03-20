#include <iostream> // Подключение cout
#include <cmath> // math - математические функции

using namespace std; // STL - Standart Template Library (стандартная библиотека шаблонов)

void sqEq(double a, double b, double c) {
  // b^2 - 4ac
  double D = pow(b, 2) - 4 * a * c;
  cout << "D = " << pow(b, 2) << " - 4 * " << a << " * " << c << " = " << D << endl;
  //
  if (D == 0) {
    double x = -b / (2 * a);
    cout << "1: x = " << x << endl;
  }
  // sqrt = square root = квадратный корень
  if (D > 0) {
    cout << "x_1,2 = (" << -b << " +- " << sqrt(D) << ") / (2 * " << a << ")" << endl;
    double x1 = (-b - sqrt(D)) / (2 * a);
    double x2 = (-b + sqrt(D)) / (2 * a);
    cout << "2: x1 = " << x1 << " x2 = " << x2 << endl;
  }
  if (D < 0)
    cout << "No solutions" << endl;
}

int main() {
  // Вывод на консоль (текст на экран)
  cout << "x + y = d" << endl;
  cout << "x^2 + y^2 = e" << endl;
  double d;
  cout << "d = ";
  cin >> d;
  double e;
  cout << "e = ";
  cin >> e;
  double f;
  cout << "f = ";
  cin >> f;
  double g;
  cout << "g = ";
  cin >> g;
  // (x-1)(x-2) = 0      (x-6)(x-7)(x-10) = 0
  std::cout << "ax^2 + bx + c = 0" << endl;
  double a = pow(g, 2) + pow(f, 2); // 541.67   541
  double b = -2 * d * f;
  double c = pow(d, 2) - e * pow(g, 2);

  sqEq(a, b, c);

  sqEq(2, 3, 1);


  return 0;
}