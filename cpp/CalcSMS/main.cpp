#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Actor {
  string name; // Имя
  int votes; // Количество голосов
};

Actor a[100];
int cnt = 0; // Количество уникальных актёров

int main() {
  freopen("input.txt", "r", stdin);

  // Количество SMS
  int N;
  cin >> N;
  string temp;
  getline(cin, temp);
  // Считываем всех людей и добавляем их в список
  for(int i = 0; i < N; i++) {
    string name;
    getline(cin, name);
    // Ищем в списке уже имеющихся актёров
    bool found = false;
    for(int j = 0; j < cnt; j++) {
      if(a[j].name == name) {
        // Нашли актёра
        found = true;
        a[j].votes++; // Увеличиваем количество голосов
        break; // Прерываемся т.к. незачем больше искать
      }
    }
    // Если такого актёра у нас ещё нет в списке
    if(!found) {
      // Надо его добавить в список
      a[cnt].name = name;
      a[cnt].votes = 1; // Уже один голос за него есть
      // Увеличиваем количество в списке
      cnt++;
    }
  }

  // Сортируем список по невозрастанию голосов
  for(int i = 0; i < cnt; i++) { // i < j
    for(int j = i + 1; j < cnt; j++) {
      if(a[i].votes < a[j].votes) {
        Actor temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  // Выводим список
  for(int i = 0; i < cnt; i++)
    cout << a[i].name << " " << a[i].votes << endl;

  return 0;
}
