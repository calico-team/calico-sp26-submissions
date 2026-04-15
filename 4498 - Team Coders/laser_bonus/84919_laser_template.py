def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	
	asteroid_positions = {}
	for i in range(K):
		pos = (X[i], Y[i])
		if pos not in asteroid_positions:
			asteroid_positions[pos] = []
		asteroid_positions[pos].append(i)
	
	# Start at the first asteroid's position
	curr_x = X[0]
	curr_y = Y[0]
	
	# Track visited positions to detect cycles
	visited = set()
	visited.add((curr_x, curr_y))
	
	# Simulate laser movement
	while True:
		
		curr_x = (curr_x + Q) % N
		curr_y = (curr_y + P) % M
		
		# Check if we hit an asteroid
		if (curr_x, curr_y) in asteroid_positions:
			# Return the first asteroid at this position
			return min(asteroid_positions[(curr_x, curr_y)])
		
		# Check if we've completed a cycle without hitting anything
	
		if (curr_x, curr_y) in visited:
			# If we're back at start, return the starting asteroid
			if curr_x == X[0] and curr_y == Y[0]:
				return 0
			break
		
		visited.add((curr_x, curr_y))
	
	
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