#include <iostream>

using namespace std;

int main() {
  // Целые числа
  int i = 10; // int - 32-битный  -2000000000..2000000000
  // 00000000=0   11111111=255
  short si; // Короткое целое
  long li; // Длинное целое
  long long lli; // Целое максимальной длины

  // С плавающей точкой
  float f = 1.1f; // Одинарная точность
  double d = 2.35; // Двойная точность (самые часто используемые)

  char cc = 'A'; // Символы

  bool logic = true; // true - истина, false - ложь

  double b = 2, c = 4; // ax + b = 0
  double x = -b / c;
  cout << "x = " << x << endl;
  //
  // Для разработки под iPhone:
  // 1. MacOS X  или версия MacOS для не Mac
  // 2. Установить XCode (компилятор Objective-C)
  // 3. Программировать прямо в XCode
  //     или AppCode: https://www.jetbrains.com/objc/

  int array[100]; // Массив из 100 элементов типа int
  array[0] = 10;
  // Весь массив заполняю числами 5
  for (int j = 0; j < 100; ++j)
    array[j] = 5;
  double da[1000]; // Массив из 1000 элементов типа double

  return 0;
}