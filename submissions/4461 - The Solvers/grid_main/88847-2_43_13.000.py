def solve(n, rr):
    #sort the array to locate median
    rr_sorted = sorted(rr)
    median = rr_sorted[n // 2]

    return [median] * n


def main():
    # read number of test case
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        rr = list(map(int, input().split()))
        result = solve(n, rr)
        print(' '.join(map(str, result)))

#program entry point
if __name__ == '__main__':
    main()