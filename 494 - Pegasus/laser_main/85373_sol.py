def solve(total_asteroids, w, h, moveY, moveX, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	total_asteroids: Number of asteroids
	w, h: Bounds for x- and y-coordinates
	moveY, moveX: Laser movement (moveY along y-axis, moveX along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	all_asteroids = {(x, y): i for i, (x, y) in enumerate(zip(X, Y))}
	start = (X[0], Y[0])
	itsStart = True
	while True:
		if not itsStart and start in all_asteroids:
			return all_asteroids[start]
		itsStart = False
		start = ((start[0] + moveX) % w, (start[1] + moveY) % h)

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