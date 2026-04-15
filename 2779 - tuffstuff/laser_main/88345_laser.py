def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.
    
    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    hit = False
    xPos = X[0] + Q
    yPos = Y[0] + P
    ans = 0
    while not hit:
        for i in range(1, len(X)):
            if xPos == X[i] and yPos == Y[i]:
                #print(xPos, X[i], yPos, Y[i])
                ans = i
                hit = True
        if hit:
            break
        if xPos >= N - 1:
            xPos = 0 + xPos - (N )
        if yPos >= M - 1:
            yPos = 0 + yPos - (M )
        xPos += Q
        yPos += P
        #print(xPos, yPos)
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