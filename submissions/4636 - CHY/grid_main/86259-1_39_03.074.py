def solve(n, a):
    sorted_a = sorted(a)
    median = sorted_a[n // 2]
    h = []
    for i in range(n):
        h.append(median)
    return h
def main():
    t_str = input()
    t = int(t_str)
    for _ in range(t):
        n_str = input()
        n = int(n_str)
        a = list(map(int, input().split()))
        result = solve(n, a)
        print(' '.join(str(x) for x in result))
if __name__ == '__main__':
    main()
