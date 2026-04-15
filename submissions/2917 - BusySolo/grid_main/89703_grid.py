def solve(N, A):
    temp = sorted(A)
    median = temp[N // 2]
    
    B = []
    for i in range(N):
        B.append(median)
    
    return B

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()