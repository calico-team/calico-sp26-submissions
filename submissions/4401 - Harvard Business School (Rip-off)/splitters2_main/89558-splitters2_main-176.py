import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    p, a, b = map(int, input().split())

    threes = []
    remaining = p
    for i in range(b):
        threes.append(remaining % 3)
        remaining //= 3

    halvedigits = []
    for i in range(a):
        halvedigits.append(remaining % 2)
        remaining //= 2

    threes.reverse()
    halvedigits.reverse()

    row0 = ['v']
    row1 = ['>']
    row2 = ['.']

    for digit in threes:
        if digit == 0:
            top, bot = 'X', 'X'
        elif digit == 1:
            top, bot = '^', 'X'
        else:
            top, bot = '^', 'v'
        row0 += [top, '.']
        row1 += ['S', '>']
        row2 += [bot, '.']

    for digit in halvedigits:
        top = '^' if digit == 1 else 'X'
        row0 += [top, '.']
        row1 += ['S', '>']
        row2 += ['.', '.']

    row1[-1] = 'X'

    print(3, len(row0))
    print(''.join(row0))
    print(''.join(row1))
    print(''.join(row2))