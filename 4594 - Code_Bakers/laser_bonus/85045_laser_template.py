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

	lazarbeam = 1

	asteroids = {}
	for i in range(K):
		asteroids[(X[i], Y[i])] = i

	start_x, start_y = X[0], Y[0]
	x, y = start_x, start_y

	
	while True:
		x = (x + Q) % N
		y = (y + P) % M

		if (x, y) in asteroids:
			return asteroids[(x, y)]

		if x == start_x and y == start_y:
			break

	return asteroids[(start_x, start_y)]

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