#include <iostream>
#include <stdlib.h>

class Shape {
  virtual void show() = 0;
};

class Rectangle : public Shape {
  void show() {

  }
};

class Circle : public Shape {
  void show() {

  }
};


int& calc() {
  static int calls = 0; // Количество вызовов функции
  calls++;
  cout << "calls = " << calls << endl;
  return calls;
}

class B;

class A {
  B b;
};

class B {
  A a;
};

int main() {
  freopen("log.txt", stdout);

  int x = calc();
  int y = calc();


  Shape* shapes[2] = {new Rectangle, new Circle};

  // Создаю вектор вообще без длины
  vector<int> v;
  // И постепенно добавляю значения
  v.push_back(1);
  v.push_back(2);

  int n = 10;
  int A[n];
  for (int i = 0; i < n; ++i)
    A[i] = i + 1;
  for (int i = 0; i < n; ++i)
    cout << "A[" << i << "] = " << A[i] << endl;

  /* Element *e1 = new Element;
   Element *e2 = new Element;
   e1->next = e2;
   F();

   int xxx = 23; */

  std::cout << "Hello, World!" << std::endl;
  return 0;
}