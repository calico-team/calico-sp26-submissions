s = 'Hello World'
s.split() # ['Hello', 'World']
s.split(',') # split by comma
' '.join(['a','b','c']) # 'a b c'
s.strip() # remove spaces both ends
s.replace('l', 'r') # 'Herro Worrd'
s.startswith('He') # True
s.endswith('ld') # True
'5'.isdigit() # True
'abc'.isalpha() # True
# Loop through characters
for ch in s:
 print(ch)