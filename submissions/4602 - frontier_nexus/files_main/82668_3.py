t = int(input())
for _ in range(t):
    a = input()
    b = input()
    
    result = list(a)
    j = 0  # pointer for b
    
    for i in range(len(a)):
        if j < len(b) and a[i] == b[j]:
            j += 1  # keep this character, it matches next needed in b
        else:
            result[i] = '#'
    
    print(''.join(result))