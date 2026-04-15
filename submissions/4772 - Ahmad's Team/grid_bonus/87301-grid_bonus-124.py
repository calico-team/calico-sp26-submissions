def solve(N, A):
    the_two_tower_heights = [0] * N

    if N == 1:
        the_two_tower_heights[0] = A[0]
        return the_two_tower_heights

    l = [0] * (N + 1)
    r = [0] * (N + 1)
    l[1] = r[1] = A[0]

    for i in range(1, N):
        if A[i] < l[i]:
            l[i+1] = A[i]
            r[i+1] = l[i]
        elif A[i] > r[i]:
            l[i+1] = r[i]
            r[i+1] = A[i]
        else:
            l[i+1] = r[i+1] = A[i]

    B = [0] * N
    B[N-1] = l[N]

    for i in range(N-1, 0, -1):
        B[i-1] = max(l[i], min(r[i], B[i]))

    the_two_tower_heights = B
    return the_two_tower_heights


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        print(' '.join(str(x) for x in solve(N, A)))


if __name__ == '__main__':
    main()