def solve():
    _, gojoPower, rct, numBeforeRct = map(int, input().split())
    curses = list(map(int, input().split()))

    for i, curse in enumerate(curses):
        if i != 0 and i % numBeforeRct == 0:
            gojoPower+=rct
        gojoPower-=curse

        if gojoPower < 0:
            return False
    return True

for _ in range(int(input())):
    print("nah i'd win" if solve() else "nah i'd lose")
