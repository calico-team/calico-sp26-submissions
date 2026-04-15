def solve(N, M):
    return [[(2*r + c) % 5 for c in range(M)] for r in range(N)]

def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))

if __name__ == '__main__':
    main()