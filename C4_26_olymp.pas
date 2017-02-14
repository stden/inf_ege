// Читаем очередное слово с консоли
function nextWord : string;
var 
  c : char;
begin
  result := '';
  while true do begin
    read(c); // Читаем символ
    if c > ' ' then  // Если это непробельный символ, 
      result := result + c // то добавляем к строке
    else 
      exit; // Иначе выходим 
  end;
end;

// Структура для хранение победителей (максимум) и субмаксимум
type 
  Student = record
    FIO   : string;  // ФИО первого человека
    balls : integer; // Количество баллов 
    count : integer; // Количество людей
  end;

var 
  N, classNo : integer;
  C, m, m2 : Student;
  i : integer;
  procent : double;
begin
  // Читаем из файла, а не с клавиатуры
  assign(input, 'C4_26_olymp.txt');
  reset(input);  
  
  m.balls := -1; 
  m2.balls := -1;
  m.count := 0; 
  m2.count := 0;
  
  readln(N);
  for i := 1 to N do begin
    // Читаем очередного человека
    C.FIO := nextWord + ' ' + nextWord;
    read(classNo);
    readln(C.balls);
    if C.balls > m.balls then begin // Мы нашли новый максимум
      m2 := m; // Старый максимум как субмаксимум
      m := C;  // Новый максимум
      m.count := 1; // Сколько таких, пока 1
    end else if C.balls = m.balls then
      inc(m.count) // Нашли ещё одного с максимальным кол-ом баллов
    else if C.balls > m2.balls then begin
      m2 := C; // Новый субмаксимум
      m2.count := 1; // И такой пока 1
    end else if C.balls = m2.balls then begin
      inc(m2.count); // Нашли ещё одного с субмаксимумом
    end;
  end;
  
  writeln('Максимум:    ' + m.FIO + ' ' + m.balls + '  кол-во: ' + m.count);
  writeln('Субмаксимум: ' + m2.FIO + ' ' + m2.balls + ' кол-во: ' + m2.count);
  procent := (m.count * 100.0) / N;
  writeln('Процент кандидатов в победители: ', procent);
  // Число кандидатов <= 25%
  if (procent <= 25.0) or (m.balls >= 300) then begin
    writeln('Кандитаты в победители стали победителями. Из остальных максимум:');
    if m2.count > 1 then writeln(m2.count) else writeln(m2.FIO);
  end else begin
    writeln('Победителей нет!');
    if m.count > 1 then writeln(m.count) else writeln(m.FIO);
  end;
end.