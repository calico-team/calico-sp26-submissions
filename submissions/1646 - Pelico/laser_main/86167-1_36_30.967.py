def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	n = max(P*len(Y)+Y[0],Q*len(X)+X[0])
	p,q = Y[0],X[0]
	co = []
	for i in range(len(X)):
		x = (X[i],Y[i])
		co.append(x)

	for i in range(1,n):
		p+=P
		q+=Q
		p = p%M
		q = q%N
		if (q,p) in co:
			for i in range(len(co)):
				if co[i] == (q,p):
					return i

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