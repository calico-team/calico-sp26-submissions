import numpy as np

def solve(K, N, M, P, Q, X, Y):

    asteroids = np.array([X,Y]).T
    curr_pos = asteroids[0]
    hit_mark = False

    while not hit_mark:
        curr_pos = (curr_pos + np.array([Q,P])) % np.array([N, M])

        if np.any(np.all(asteroids == curr_pos, axis = 1)):
            hit_mark = True
            return np.where(asteroids == curr_pos)[0][-1]

    return None

with open("../data/sample/00_main.in", "r") as f:
    lines = [line.strip() for line in f]
    T = int(lines[0])

    i = 1
    for j in range(T):
        line = lines[i + 4*j].split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])

        X = []
        Y = []
        for _ in range(K):
            coords = lines[i + 4*j + _ + 1].split()
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)

        print(solve(K, N, M, P, Q, X, Y))