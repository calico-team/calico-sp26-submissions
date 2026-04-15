def solve(A: str, B: str) -> str:
    res = ['#'] * len(A)
    idx = 0
    for i in range(len(A)):
        if idx < len(B) and A[i] == B[idx]:
            res[i] = A[i]
            idx += 1
    return ''.join(res)

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
