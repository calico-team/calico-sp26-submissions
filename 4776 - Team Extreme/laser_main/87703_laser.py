def solve(K, N, M, P, Q, X, Y):
	positions = {}
	for i in range(K):
		pt = (X[i], Y[i])
		if pt not in positions:
			positions[pt] = i

	x, y = X[0], Y[0]
	steps = 0
	visited = set()
	visited.add((x, y))

	while True:
		x = (x + Q) % N
		y = (y + P) % M
		steps += 1

		if (x, y) in positions:
			return positions[(x, y)]

		if (x, y) in visited:
			return -1
		visited.add((x, y))

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
			data = input().split()
			X.append(int(data[0]))
			Y.append(int(data[1]))
		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()