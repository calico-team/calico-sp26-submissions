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
    coordinates = list(zip(X,Y))
    top_left = coordinates[0]
    spaceship = list(top_left)
    while True:
        #print( (spaceship[0],spaceship[1]))
        spaceship[0] += Q
        spaceship[1] += P
        spaceship[0] = spaceship[0]%N
        spaceship[1] = spaceship[1]%M
        if (spaceship[0],spaceship[1]) in coordinates:
            return coordinates.index((spaceship[0],spaceship[1]))
        
    

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