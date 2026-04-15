def solve(K, N, M, P, Q, X, Y):
    """ 
    Find the index of the first asteroid hit by the laser.
    
    
    K: Number of asteroids N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """

    pos_map = {}
    for i in range(K):
        pos_map[(X[i], Y[i])] = i

     # Start from the first asteroid
    start = (X[0], Y[0])
    x, y = start

    while True:
        x = (x + Q) % N
        y = (y + P) % M

          # Check if laser hits an asteroid 
        if (x, y) in pos_map:
            return pos_map[(x, y)]
# If position repeats cycle detected, no new asteroid reachable
        if (x, y) == start:
            return 0


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