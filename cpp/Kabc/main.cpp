#include <iostream>

int main() {
  //double a * x + b = 0 ;
  double a = 2;

  double b = 4;

  std::cout << "a = ";
  std::cin >> a;
  std::cout << "b = ";
  std::cin >> b;


  double x = -b / a;
  std::cout << "x = " << x << std::endl;
  std::cout << "a * x + b = " << (a * x + b) << std::endl;


  return 0;
}
