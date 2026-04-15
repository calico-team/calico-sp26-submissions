def solve(K, N, M, P, Q, X, Y):
    x = X[0]
    y = Y[0]
    for i in range(1000):
        if x + Q > N:
            x = Q - (N - x)
        else:
            x = x + Q
        if y + P > M:
            y = P - (M - y)
        else:
            y = y + P
        for j in range(len(X)):
            if x == X[j] and y == Y[j]:
                return j


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