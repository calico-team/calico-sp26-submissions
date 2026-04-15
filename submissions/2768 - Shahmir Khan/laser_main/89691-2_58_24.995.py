def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	
	las_x = X[0]
	las_y = Y[0]
	
	# asterod position
	asteroids = list(zip(X, Y))
	
	
	max_stps = N * M * 1000 
	for step in range(1, max_stps):
		las_x = (las_x + Q) % N
		las_y = (las_y + P) % M
		
		for i in range(K):
			if las_x == X[i] and las_y == Y[i]:
				return i
	
	
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