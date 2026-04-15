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
	starting_point_x , starting_point_y = X[0] , Y[0]
	position = {}
	for i in range(K):
		if (X[i] , Y[i]) not in position:
			position[(X[i] ,Y[i])] = i 
	curr_x , curr_y = starting_point_x , starting_point_y
	for travel in range(1 , N*M+1):
		curr_x = (curr_x+Q) %N
		curr_y = (curr_y+P) %M
		if (curr_x,curr_y) in position:
			return position[(curr_x,curr_y)]	
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