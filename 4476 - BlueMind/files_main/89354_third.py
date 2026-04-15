t = int(input().strip())

for i in range(t):
    x = input().strip()
    z = input().strip()
    
    res = ""
    j = 0  
    for char in x:
      
        if j == len(b):
            res += '#'
        elif char == b[j]:
            res += char
            j += 1
        else:
            res += '#'
            
    print(res)