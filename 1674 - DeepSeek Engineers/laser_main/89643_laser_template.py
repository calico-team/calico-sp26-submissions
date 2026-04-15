def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	pos = (X[0], Y[0])  # Starting position of the laser
	for i in range(K):
		if (X[i]-pos[0])/Q == (Y[i]-pos[1])/P and (X[i]-pos[0])/Q > 0:
			min = (X[i]-pos[0])/Q
			for j in range(i+1, K):
				if (X[j]-pos[0])/Q == (Y[j]-pos[1])/P and (X[j]-pos[0])/Q < min:
					min = (X[j]-pos[0])/Q
					i = j
			return i


	while(True):
		if(N-pos[0])/Q < (M-pos[1])/P:
			pos = (0, pos[1] + P*(N-pos[0])/Q)
		elif (N-pos[0])/Q > (M-pos[1])/P:
			pos = (pos[0] + Q*(M-pos[1])/P, 0)
		else:
			pos = (0, 0)

		for i in range(K):
			if (X[i]-pos[0])/Q - (Y[i]-pos[1])/P < 0.001:
				min = (X[i]-pos[0])/Q
				for j in range(i+1, K):
					if (X[j]-pos[0])/Q == (Y[j]-pos[1])/P and (X[j]-pos[0])/Q < min:
						min = (X[j]-pos[0])/Q
						i = j
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