def solve(N, A):
    def cost(bot):
        total = 0
        for i in range(N - 1):
            total += abs(A[i] - A[i+1])
            total += abs(bot[i] - bot[i+1])
        for i in range(N):
            total += abs(A[i] - bot[i])
        return total

    med = sorted(A)[len(A) // 2]
    med_b = [med] * N
    copy_b = A[:]

    if cost(med_b) <= cost(copy_b):
        return med_b
    return copy_b


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()