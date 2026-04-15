def solve():
    t = int(input().strip())

    for _ in range(t):
        A = input().strip()
        B = input().strip()        
        result = []
        j = 0  #poitner --> B      
        for ch in A:
            if j < len(B) and ch == B[j]:
                result.append(ch)
                j += 1
            else:
                result.append('#')  
        print("".join(result))

solve()