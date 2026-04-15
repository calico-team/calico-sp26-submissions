from collections import deque
from fractions import Fraction

def solve():
    N, M = map(int, input().split())

    grid = [[i for i in input()] for _ in range(N)]
    percentages = [[Fraction(0, 1)]*M for _ in range(N)]

    percentages[0][0] = Fraction(1, 1)

    inEdges = [[0]*M for _ in range(N)]

    for y in range(N):
        for x in range(M):
            if grid[y][x] in "<>^v":
                dy, dx = conveyors[grid[y][x]]
                newY, newX = y+dy, x+dx
                if 0 <= newY < N and 0 <= newX < M:
                    inEdges[newY][newX] += 1
            elif grid[y][x] == "S":
                for direction in conveyors:
                    dy, dx = conveyors[direction]
                    newY, newX = y+dy, x+dx
                    if not (0 <= newY < N and 0 <= newX < M):
                        continue

                    try:
                        if not (conveyors[grid[newY][newX]] == [-dy, -dx]):
                            inEdges[newY][newX] += 1
                    except KeyError:
                        if grid[newY][newX] == 'X':
                            inEdges[newY][newX] += 1
    
    queue = deque()
    queue.append([0, 0])
    
    while queue:
        y, x = queue.popleft()
        if grid[y][x] in  "<>^v":
            dy, dx = conveyors[grid[y][x]]
            newY, newX = y+dy, x+dx
            if 0 <= newY < N and 0 <= newX < M:
                percentages[newY][newX] += percentages[y][x]
                inEdges[newY][newX] -= 1
                if inEdges[newY][newX] == 0:
                    queue.append([newY, newX])
            else:
                print(f"{percentages[y][x].numerator} {percentages[y][x].denominator}")
                return

        elif grid[y][x] == 'S':
            valids = 0
            for direction in conveyors:
                dy, dx = conveyors[direction]
                newY, newX = y+dy, x+dx
                try:
                    if not (conveyors[grid[newY][newX]] == [-dy, -dx]):
                        valids += 1
                except KeyError:
                    if grid[newY][newX] == 'X':
                        valids += 1

            for direction in conveyors:
                dy, dx = conveyors[direction]
                newY, newX = y+dy, x+dx
                try:
                    if not (conveyors[grid[newY][newX]] == [-dy, -dx]):
                        percentages[newY][newX] += percentages[y][x]/valids
                        inEdges[dy+y][dx+x] -= 1
                        if inEdges[dy+y][dx+x] == 0:
                            queue.append([dy+y, dx+x])
                except KeyError:
                    if grid[newY][newX] == 'X':
                        percentages[newY][newX] += percentages[y][x]/valids
                        inEdges[dy+y][dx+x] -= 1
                        if inEdges[dy+y][dx+x] == 0:
                            queue.append([dy+y, dx+x])

    print("0 1")


conveyors = {">":[0, 1], "<":[0, -1], "^":[-1, 0], "v":[1, 0]}

for _ in range(int(input())):
    solve()