def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	asteroids = {}
	for i in range(1, K):
		asteroids[X[i] * M + Y[i]] = i

	cur_x = X[0]
	cur_y = Y[0]
	start_key = cur_x * M + cur_y
	max_steps = N * M

	for steps in range(max_steps):
		cur_x = (cur_x + Q) % N
		cur_y = (cur_y + P) % M

		key = cur_x * M + cur_y

		if key in asteroids:
			return asteroids[key]

		if key == start_key:
			return 0

	return -1

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