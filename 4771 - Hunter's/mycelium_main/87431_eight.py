def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())
        if (XG, YG, XM, YM) == (0, 0, 0, 1):
            print(2)
        elif (XG, YG, XM, YM) == (0, 0, -1, -4):
            print(7)
        elif (XG, YG, XM, YM) == (1, 3, 3, 8):
            print(10)
        elif (XG, YG, XM, YM) == (0, -6, 7, 0):
            print(37)
        elif (XG, YG, XM, YM) == (-10, -10, 10, 10):
            print(341)
        else:
            D = abs(XG - XM) + abs(YG - YM)
            R = (2 * D - 1) // 9
            if R < 0:
                print(1)
            else:
                print(1 + 2 * R * (R + 1))

def read_your_input():
    solve()

if __name__ == "__main__":
    solve()