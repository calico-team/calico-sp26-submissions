def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	min_time = float('inf')
	min_index = -1

	for i in range(K):
		delta_x = (X[i] - X[0]) % N
		delta_y = (Y[i] - Y[0]) % M
		
		max_iterations = N * M
		for step in range(1, max_iterations + 1):
			if (X[0] + step * Q) % N == X[i] and (Y[0] + step * P) % M == Y[i]:
				if step < min_time:
					min_time = step
					min_index = i
				break

	return min_index

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