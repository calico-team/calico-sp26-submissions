def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	
	starting_point = [X[0],Y[0]]
	laser_pos = starting_point
	has_hit = False
	asteriod_index = 0

	while has_hit == False:
		laser_pos[0] += P
		laser_pos[1] += Q

		if laser_pos[0] > N-1:
			laser_pos[0] -= N - 1

		if laser_pos[1] > M-1:
			laser_pos[1] -= M - 1

		for i in range(len(X)):
			if laser_pos[0]==X[i] and laser_pos[1] == Y[i]:
				has_hit = True
				asteriod_index = i
			else:
				continue

	return asteriod_index

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