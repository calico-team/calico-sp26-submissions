#import numpy as np

def solve(K, N, M, P, Q, X, Y):
    
    curr_x = X[0]; curr_y = Y[0]
    hit_mark = False

    while not hit_mark:
        curr_x = (curr_x + Q) % N
        curr_y = (curr_y + P) % M

        for i in range(K):
            if curr_x == X[i] and curr_y == Y[i]:
                return i

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