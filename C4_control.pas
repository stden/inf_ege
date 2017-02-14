var 
  N : integer; { Количество чисел }
  i, x, control, myControl  : integer;
  maxOdd : integer = -1; { Максимальное нечётное }
  maxEven : integer = -1; { Максимальное чётное }
begin
  // Читаем из файла, а не с клавиатуры
  assign(input, 'C4_control.txt');
  reset(input);

  read(N);
  for i:=1 to N do begin
    read(x);
    case x mod 2 of 
      0: if x > maxEven then maxEven := x;
      1: if x > maxOdd then maxOdd := x;
    end;  
  end;
  read(control);
  myControl := -1;
  if (maxOdd <> -1) and (maxEven <> -1) then 
    myControl := maxOdd + maxEven;
  if control <> myControl then 
    writeln('Ошибка')
  else
    writeln('Всё верно: ', control);
end.