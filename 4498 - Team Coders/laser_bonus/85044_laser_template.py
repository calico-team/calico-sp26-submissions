def solve(K, N, M, P, Q, X, Y):
	asteroids = set()
	for i in range(K):
		asteroids.add((X[i], Y[i], i))
	
	x, y = X[0], Y[0]
	visited = set()
	visited.add((x, y))
	
	max_steps = N * M
	step = 0
	
	while step < max_steps:
		x = (x + Q) % N
		y = (y + P) % M
		step += 1
		
		for ax, ay, idx in asteroids:
			if x == ax and y == ay:
				return idx
		
		if (x, y) in visited and x == X[0] and y == Y[0]:
			return 0
		
		visited.add((x, y))
	
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