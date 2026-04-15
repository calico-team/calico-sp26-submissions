import sys
# sys.stdin = open("9.in")
input = sys.stdin.readline
import math

def solve():
    n, m = map(int, input().split())
    board = [input().strip() for _ in range(n)]
    # print(*board, sep='\n')

    directionsMap = {">": (0, 1), "<": (0, -1), "^": (-1, 0), "v": (1, 0), "X": (0, 0), ".": (0, 0)}
    directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    def out(a, b):
        if a < 0 or a >= n or b < 0 or b >= m:
            return True
        return False

    # x, y, quantityDenominator ex. 6 -> 1/6
    stack = [(0, 0, 1)]
    collected = []
    while stack:
        uX, uY, d = stack.pop()
        c = board[uX][uY]
        if c == "X" or c == ".":
            continue
        if out(uX, uY):
            collected.append(d)
            continue
        if c == ">" or c == "<" or c == "^" or c == "v":
            newX, newY = uX + directionsMap[c][0], uY + directionsMap[c][1]
            if out(newX, newY):
                collected.append(d)
                continue
            stack.append((newX, newY, d))
        elif c == "S":
            totalValid = 0
            for dx, dy in directions:
                newX, newY = uX + dx, uY + dy
                if newX + directionsMap[board[newX][newY]][0] != uX or newY + directionsMap[board[newX][newY]][1] != uY:
                    if board[newX][newY] != ".":
                        totalValid += 1
            for dx, dy in directions:
                newX, newY = uX + dx, uY + dy
                if (newX + directionsMap[board[newX][newY]][0]) != uX or (newY + directionsMap[board[newX][newY]][1]) != uY:
                    stack.append((newX, newY, d * totalValid))
        else:
            assert False
    
    if not collected:
        print(0, 1)
    else:
        # sum up via lcm, then gcd to print final answer
        # should print [3, 12] for the sample -> 1/3 + 1/12 = 1/4
        # print(collected)
        denom = 1
        for i in range(len(collected)):
            denom = (denom * collected[i]) // math.gcd(denom, collected[i])
        num = 0
        for i in range(len(collected)):
            num += (denom // collected[i])
        rd = math.gcd(num, denom)
        num //= rd
        denom //= rd
        print(num, denom)


tcs = int(input())

for tc in range(tcs):
    solve()

'''
direct simulation, dfs
'''
