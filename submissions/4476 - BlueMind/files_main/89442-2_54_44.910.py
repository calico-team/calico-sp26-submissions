t = int(input().strip())

for i in range(t):
    x = input().strip()
    z = input().strip()
    
    res = ""
    j = 0  
    for char in x:
        
        if j < len(z):
            if char == z[j]:
                res += char
                j += 1
            else:
                res += '#'
        else:
            res += '#'
            
    print(res)