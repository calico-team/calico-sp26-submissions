
def inter(X,Y,P):
	for i in range(len(X)):
		if X[i] == P[0] and Y[i] == P[1]:
			return i
	return -1
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
	
	location = [X[0],Y[0]]
	while True:
		location[0]+=Q
		location[1]+=P
		if location[0]>N-1 or location[0]<0:
			location[0]=X[0]
		if location[1]>M-1 or location[1]<0:
			location[1]=Y[0]	
		r = inter(X,Y,location)		
		if r!=-1:
			return r

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