#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // Вывод таблицы умножения
  int size = 10;
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++)
      cout << setw(4) << (i * j) << " ";
    cout << endl;
  }
  for (long long i = 1; i <= 50; i++)
    cout << i << "^2 = " << i* i << endl;

  return 0;
}