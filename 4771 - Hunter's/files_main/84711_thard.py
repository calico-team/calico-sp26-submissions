def solve():
    T = int(input())
    for _ in range(T):
        A = input().strip()
        B = input().strip()
        
        result = []
        b_idx = 0
        
        for ch in A:
            if b_idx < len(B) and ch == B[b_idx]:
                result.append(ch)
                b_idx += 1
            else:
                result.append('#')
        
        print(''.join(result))

if __name__ == "__main__":
    solve()