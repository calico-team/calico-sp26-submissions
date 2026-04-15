import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    for _ in range(t):
        n = int(data[idx])
        p = int(data[idx + 1])
        r = int(data[idx + 2])
        k = int(data[idx + 3])
        idx += 4
        curses = []
        for _ in range(n):
            curses.append(int(data[idx]))
            idx += 1
        power = p
        alive = True
        for i in range(n):
            power -= curses[i]
            if power < 0:
                alive = False
                break
            if (i + 1) % k == 0:
                power += r
        if alive:
            print("nah i'd win")
        else:
            print("nah i'd lose")

if __name__ == '__main__':
    solve()