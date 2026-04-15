def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""

	asteroids = [(X[i],Y[i]) for i in range(K)]
	grid = [[0 if (i,j) not in asteroids else 1 for i in range(N)] for j in range(M)]

	laser_pos = asteroids[0]
	beginning = True

	while beginning or grid[laser_pos[1]][laser_pos[0]] == 0:
		new_x = laser_pos[0] + Q
		new_y = laser_pos[1] + P

		if new_x >= N:
			new_x = new_x - N
		if new_y >= M:
			new_y = new_y - M

		laser_pos = (new_x, new_y)

		if beginning:
			beginning = False
	
	for i in range(K):
		if X[i] == laser_pos[0] and Y[i] == laser_pos[1]:
			return i

	# YOUR CODE HERE
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