t = int(input())

for i in range(t):
    a = str(input())
    b = str(input())
        
    result = ""
    b_idx = 0
        
    for char in a:
        if b_idx < len(b) and char == b[b_idx]:
            result += char
            b_idx += 1
        else:
            result += "#"
        
    print(result)