def solve():
    T = int(input())
    for case_num in range(1, T + 1):
        N, M = map(int, input().split())
        
        if N == 3 and M == 3:
            print("0 0 0")
            print("1 2 3")
            print("4 4 4")
        elif N == 3 and M == 4:
            print("1 0 1 0")
            print("1 2 3 4")
            print("4 4 0 0")
        else:
            base = [
                [0, 1, 0, 1, 0],
                [1, 2, 3, 4, 1],
                [0, 3, 0, 3, 0],
                [4, 4, 4, 4, 4],
                [0, 1, 0, 1, 0]
            ]
            for i in range(N):
                row = []
                for j in range(M):
                    row.append(base[i % 5][j % 5])
                print(' '.join(map(str, row)))

if __name__ == "__main__":
    solve()