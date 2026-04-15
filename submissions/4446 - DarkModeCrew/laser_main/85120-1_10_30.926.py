def solve(K, N, M, P, Q, x, y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	astroids={}
	for item in range(K):
		if (x[item], y[item]) not in astroids:
			astroids[(x[item], y[item])]=item
	
	initial_x=x[0]
	initial_y=y[0]

	final_x=(initial_x+Q)%N
	final_y=(initial_y+P)%M

	while True:
		if (final_x,final_y) in astroids:
			return astroids[(final_x,final_y)]
		final_x = (final_x+Q)%N
		final_y = (final_y+P)%M
		if final_x == initial_x and final_y == initial_y:
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