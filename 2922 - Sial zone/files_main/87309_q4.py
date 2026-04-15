T = int(input())

for _ in range(T):
    A = input().strip()
    B = input().strip()
    
    j = 0
    res = []
    
    for c in A:
        if j < len(B) and c == B[j]:
            res.append(c)
            j += 1
        else:
            res.append('#')
    
    print(''.join(res))