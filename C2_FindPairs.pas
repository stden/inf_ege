const 
  N = 5;
var 
  a: array [1..N] of integer = (2,2,2,2,2); //(16, 3, 142, 55, 22);
  i, j, k : integer;
begin
  k := 0; 
  for i:=1 to N-1 do begin
    writeln('i = ', i,' Pair: ', a[i], ' ', a[i+1]);
    if (a[i] mod 10 = 2) or 
       (a[i+1] mod 10 = 2) then begin
        k := k + 1;
        writeln('  k = ', k);
      end;
  end;
  writeln(k);
end.