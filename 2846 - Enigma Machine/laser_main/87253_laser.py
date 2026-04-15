def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.

    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    # YOUR CODE HERE
    starting_pos = (X[0], Y[0])
    X.pop(0)
    Y.pop(0)
    coords = starting_pos[0]+Q, starting_pos[1]+P
    while True:
        x = coords[0]
        y = coords[1]
        if x > N:
            x -= N
        if y > M:
            y-=M
        coords = (x,y)
        for i in range(len(X)):
            if coords == (X[i], Y[i]):
                return i+1
        if coords == starting_pos:
            return 0
        x+=Q
        y+=P
        coords = (x,y)


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