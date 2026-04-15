def solve(K, N, M, P, Q, X, Y):

	x0 = X[0]
	y0 = Y[0]

	map = {}

	for i in range(1 , K):

		map[(X[i], Y[i])] = i

	a , c = x0, y0

	while True:

		a = (a + Q) % N
		c = (c + P) % M

		if (a, c) in map:

			return map[(a, c)]
		
		if (a, c) == (x0, y0):

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