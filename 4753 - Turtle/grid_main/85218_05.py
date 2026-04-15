def solve():
    t = int(input())

    for i in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = a
        print(*b)


def read_your_input():
    solve()


if __name__ == "__main__":
    solve()
