def solve(K, N, M, P, Q, X, Y):
	pos_map = {}
	for i in range(K):
		pos_map[(X[i], Y[i])] = i
	
	x, y = X[0], Y[0]
	
	for _ in range(N * M):
		x = (x + Q) % N
		y = (y + P) % M
		
		if (x, y) in pos_map:
			return pos_map[(x, y)]
	
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
			X.append(int(coords[0]))
			Y.append(int(coords[1]))
		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()