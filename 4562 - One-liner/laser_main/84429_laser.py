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
	hit = False
	#print(X, Y)
	Astroids = list([X[i], Y[i]] for i in range(K))

	LaserCords = [X[0], Y[0]]
	
	while not hit:
		LaserCords = [LaserCords[0] + P, LaserCords[1] + Q]

		if LaserCords[0] >= N:
			LaserCords[0] -= N-1

		if LaserCords[1] >= M:
			LaserCords[1] -= M-1

		if LaserCords in Astroids:
			hit = True
			K = Astroids.index(LaserCords)
			return K

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