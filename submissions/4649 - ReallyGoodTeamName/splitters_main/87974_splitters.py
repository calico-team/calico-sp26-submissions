def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    up =(-1,0)
    down = (1,0)
    left = (0,-1)
    right = (0,1)

    starts = []
    for j in range(M):
        if factory[0][j] != '.':
            starts.append((0,j))
    total = len(starts)
    if total == 0:
        return 0,1

    success = 0
    for (si,sj) in starts:
        x = si
        y = sj
        visited = []
        flag = False

        while True:
            if x < 0 or x >= N or y < 0 or y >= M:
                break
            exist = False
            for (px,py) in visited:
                if px == x and py == y:
                    exist = True
                    break
            if exist:
                break
            visited.append(x,y)
            c = factory[x][y]
            if c == 'X':
                break
            if c == 'S':
                flag = True
                break
            if c == 'R':
                nx = x-1
                ny = y
                if 0 <= nx < N and 0 <= ny < M:
                    x,y = nx,ny
                    continue
                nx = x+1
                ny = y
                if 0 <= nx < N and 0 <= ny < M:
                    x,y = nx,ny
                    continue
                nx = x
                ny = y-1
                if 0 <= nx < N and 0 <= ny < M:
                    x,y = nx,ny
                    continue
                nx = x
                ny = y+1
                if 0 <= nx < N and 0 <= ny < M:
                    x,y = nx,ny
                    continue
                break

            if c == '^':
                x += up[0]
                y += up[1]
            elif c == 'v':
                x += down[0]
                y += down[1]
            elif c == '<':
                x == left[0]
                y += left[1]
            elif c == '>':
                x += right[0]
                y += right[1]
            else:
                break
        if flag:
            success += 1
    a = success
    b = total
    x1 = a
    y1 = b
    while y1 != 0:
        temp = y1
        y1 = x1 % y1
        x1 = temp
    g = x1

    ans1 = a // g
    ans2 = b // g
    return ans1,ans2

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
