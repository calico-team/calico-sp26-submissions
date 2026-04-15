def solve():
    import sys
    lines = [line.rstrip('\n') for line in sys.stdin]
    ptr = 0
    T = int(lines[ptr])
    ptr += 1
    for _ in range(T):
        A = lines[ptr]
        ptr += 1
        B = lines[ptr]
        ptr += 1
        
        result = []
        j = 0
        for char in A:
            if j < len(B) and char == B[j]:
                result.append(char)
                j += 1
            else:
                result.append('#')
        print(''.join(result))

if __name__ == "__main__":
    solve()
