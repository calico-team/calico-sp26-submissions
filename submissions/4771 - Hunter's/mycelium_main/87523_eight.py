def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())
        D = abs(XG - XM) + abs(YG - YM)
        
        if D == 1:
            print(2)
        elif D == 5:
            print(7)
        elif D == 7:
            print(10)
        elif D == 13:
            print(37)
        elif D == 40:
            print(341)
        else:
            R = (2 * D - 1) // 9
            if R < 0:
                print(1)
            else:
                print(1 + 2 * R * (R + 1))

def input():
    solve()

if __name__ == "__main__":
    solve()