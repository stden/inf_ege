const ID = 'substr';
var s : string; 
  c, answer : char;
  count : array ['a'..'z'] of integer; 
  max : integer;
begin
  assign(input, ID + '.in'); reset(input);
  //assign(output, ID + '.out'); rewrite(output);
  // ���� �� ����� �����, ������ ����� ������ �����
  // � ������ ������ ��� �� ���������
  // �� ��� ����� �����������
  while not eof(input) do begin
    // ������ ������� ������
    readln(s);
    // ������� ���������� ����
    for c := 'a' to 'z' do count[c] := 0;
    foreach c in s do 
      inc(count[c]);
    max := 0; 
    for c := 'a' to 'z' do 
      if count[c] > max then begin
        max := count[c];
        answer := c;
      end;
    writeln(answer);
  end;
end.