const ID = 'strings';
var s, t : string; 
  p : integer;
  found : boolean;
begin
  assign(input, ID + '.in'); reset(input);
  //assign(output, ID + '.out'); rewrite(output);
  // ���� �� ����� �����, ������ ����� ������ �����
  // � ������ ������ ��� �� ���������
  // �� ��� ����� �����������
  while not eof(input) do begin
    // ������ ������� ������
    readln(s); readln(t);
    // ���� ���������
    p := 0;
    found := false;
    while true do begin
      p := pos(t, s, p + 1);
      if p <> 0 then begin
        write(p,' ');
        found := true;
      end else 
        break;
    end;
    if not found then write('none');
    writeln;
  end;
end.