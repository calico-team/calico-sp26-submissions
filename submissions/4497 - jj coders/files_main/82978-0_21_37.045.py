def solve(A: str, B: str) -> str:
    result = []
    j = 0  # pointer for B
    for ch in A:
        if j < len(B) and ch == B[j]:
            result.append(ch)
            j += 1
        else:
            result.append('#')
    return ''.join(result)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()