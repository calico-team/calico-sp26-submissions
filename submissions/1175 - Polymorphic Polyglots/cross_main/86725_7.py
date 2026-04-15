import sys
# sys.stdin = open("7.in")
input = sys.stdin.readline

def solve():
    m, n = map(int, input().split())
    board = [["" for _ in range(n)] for _ in range(m)]
    shifts = [[3, 0, 2, 1, 4], 
              [1, 4, 3, 0, 2], 
              [0, 2, 1, 4, 3], 
              [4, 3, 0, 2, 1], 
              [2, 1, 4, 3, 0]
              ]
    for i in range(m):
        for j in range(n):
            board[i][j] = shifts[i % 5][j % 5]
    for i in range(m):
        print(*board[i])

tcs = int(input())

for tc in range(tcs):
    solve()

'''
oh, there's a pattern
3 0 2 1 4 3 0
1 4 3 0 2 1 4
0 2 1 4 3 0 2
4 3 0 2 1 4 3
2 1 4 3 0 2 1
3 0 2 1 4 3 0
... and so on
in other words, cyclic shifts of 3 0 2 1 4
'''
