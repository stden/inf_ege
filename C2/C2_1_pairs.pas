﻿{ Дан целочисленный массив из 20 элементов. 
Элементы массива могут принимать целые значения от –10 000 до 10 000 включительно. 
Опишите на одном из языков программирования алгоритм, 
позволяющий найти и вывести количество пар элементов массива, 
в которых сумма элементов делится на 3, но не делится на 9. 
В данной задаче под парой подразумеваются два соседних элемента массива.
Исходные данные объявлены так, как показано ниже на примерах для некоторых языков программирования. 
Запрещается использовать переменные, не описанные ниже, 
но разрешается не использовать некоторые из описанных переменных }

const
  N = 20;
var
  a: array [1..N] of integer;
  i, j, k: integer;
begin
  // Читаем из файла, а не с клавиатуры
  assign(input, 'C2_1_pairs.txt');
  reset(input);
  // Чтение исходных данных
  for i := 1 to N do
    readln(a[i]);

  k := 0; { Количество пар элементов (счётчик) }
  for i := 1 to N - 1 do 
    if ((a[i] + a[i+1]) mod 3 = 0) and 
       ((a[i] + a[i+1]) mod 9 <> 0) then
      inc(k);

  writeln(k); { Выводим количество пар элементов }
end.