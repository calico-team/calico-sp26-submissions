def solve(K, N, M, P, Q, X, Y):
    x = X[0]
    y = Y[0]
    while True:
        if x + Q > N:
            x = Q - (N - x)
        else:
            x = x + Q
        if y + P > M:
            y = P - (M - y)
        else:
            y = y + P
        if x in X and y in Y:
            if y == Y[X.index(x)]:
                return X.index(x)
            elif x == X[Y.index(y)]:
                return Y.index(y)


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