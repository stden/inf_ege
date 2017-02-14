function word(var s : string):string;
var p : integer;
begin
  p := pos(' ', s); // Ищем пробелы
  // Если пробел найден
  if p <> 0 then begin
    // То берём слово до пробела
    word := copy(s, 1, p - 1);
    // Вырезаем его из строки
    delete(s, 1, p);
    // И опять обрезаем начальные пробелы
    // на случай если кто-то поставил поставил между оценками больше 1 пробела
    s := trim(s);
  end else 
    word := s;
end;

type
  Pupil = record
    surname : string;
    name : string;
    m : array [1..3] of integer;
    twos : integer;  
  end;
  
var
  N : integer; // Количество учеников
  A : array [1..100] of Pupil; // Ученики
  i, j, p, et : integer;
  s : string; // Строка входного файла
begin
  // Читаем из файла, а не с клавиатуры
  assign(input, 'pupils.txt');
  reset(input);
  // Читаем количество учеников
  readln(N);
  // Читаем учеников в цикле
  for i := 1 to N do begin
    // Читаем очередную строчку
    readln(s);
    // Убираем начальные и концевые пробелы если они есть
    s := trim(s);
    // Читаем отдельного ученика
    with A[i] do begin
      surname := word(s); // Фамилия
      name := word(s); // Имя
      twos := 0; // Считаем количество его 2-ек
      for j := 1 to 3 do begin
        m[j] := StrToInt(word(s)); // Читаем оценки
        // Считаем его 2-ки  
        if m[j] = 2 then
          inc(twos);
      end;
    end;
  end;
  // Пробегаем и выводим по убыванию количества 2-ек
  for et := 3 downto 1 do begin // Ожидаемое количество двоек 
    writeln('Количество двоек: ', et);
    for i := 1 to N do 
      with A[i] do
        if twos = et then // Если у ученика нужное количество двоек
          writeln(surname,' ', name);
  end;
end.