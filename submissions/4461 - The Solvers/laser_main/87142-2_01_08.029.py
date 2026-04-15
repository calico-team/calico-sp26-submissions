def solve(K, N, M, P, Q, X, Y):
    start_x, start_y =X[0],Y[0]

    min_steps = float('inf')
    ans =0

    for i in range(K):
        dx = (X[i] -start_x) % N
        dy = (Y[i] -start_y) % M

        t =dx
        if Q !=0:
            if dx % Q != 0:
                continue
            t = dx // Q
        else:
            if dx != 0:
                continue

        if (t * P) % M != dy:
            continue
		
        if t == 0:
            continue

        if t < min_steps:
            min_steps = t
            ans = i

    return ans


def main():
    T = int(input())

    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])

        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)

        print(solve(K, N, M, P, Q, X, Y))


if __name__ == '__main__':
    main()