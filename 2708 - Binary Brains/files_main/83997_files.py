def solve(A: str, B: str) -> str:
    j = 0
    result = []
    for c in A:
        if j < len(B) and c == B[j]:
            result.append(c)
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
