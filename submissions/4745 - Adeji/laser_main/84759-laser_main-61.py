def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	asteroids = []
	lazer_x =X[0]
	lazer_y = Y[0]
	path = []
	for i in range(K):
		asteroids.append((X[i], Y[i]))
	while True:
		lazer_x += Q
		lazer_y += P
		if lazer_x > N:
			lazer_x = lazer_x % Q
		if lazer_y > M:
			lazer_y = lazer_y % P
		# path.append((lazer_x, lazer_y))

		if (lazer_x, lazer_y) in asteroids:
			# print(path)
			return asteroids.index((lazer_x, lazer_y))

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