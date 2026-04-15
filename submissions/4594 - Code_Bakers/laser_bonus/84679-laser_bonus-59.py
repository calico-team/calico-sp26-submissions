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

	
	lazarbeam = 1  # required by statement (not used)

	spaceStones = {}
	for i in range(K):
		spaceStones[(X[i], Y[i])] = i

	x, y = X[0], Y[0]

	reached = set()

	while True:
		x = (x + Q) % N
		y = (y + P) % M

		if (x, y) in spaceStones:
			return spaceStones[(x, y)]

		if (x, y) in reached:
			return spaceStones[(X[0], Y[0])]

		reached.add((x, y))

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