def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	laserpos = [X[0], Y[0]]
	anum = range(K)
	apos = []
	for i in anum:
		apos.append([X[i], Y[i]])
	while True:
		laserpos[0] += Q
		laserpos[1] += P
		if laserpos[0] > N:
			laserpos[0] = laserpos[0] - N
		if laserpos[1] > M:
			laserpos[1] = laserpos[1] - M
		if laserpos in apos:
			return anum[apos.index(laserpos)]
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