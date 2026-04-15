import time

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	
	currX = X[0]
	currY = Y[0]

	while True:
		if currX + Q > N-1:
			currX = currX + Q - N
		else:
			currX += Q

		if currY + P > M-1:
			currY = currY + P - M
		else:
			currY += P

		for i in range(K):
			if currX == X[i] and currY == Y[i]:
				return i

def main():
	
	T = int(input())
	# time.sleep(1)
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