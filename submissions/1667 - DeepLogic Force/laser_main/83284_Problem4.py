def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	
	# store all asteroid positions in a dict for quick lookup
	asteroid_map = {}
	for i in range(K):
		pos = (X[i], Y[i])
		if pos not in asteroid_map:
			asteroid_map[pos] = i

	# laser starts at first asteroid's position
	lazarbeam = (X[0], Y[0])
	cx, cy = lazarbeam

	# simulate laser steps, skip first position (laser doesn't hit start until wrapped)
	visited = set()
	cx = (cx + Q) % N
	cy = (cy + P) % M

	while (cx, cy) not in visited:
		if (cx, cy) in asteroid_map:
			return asteroid_map[(cx, cy)]
		visited.add((cx, cy))
		cx = (cx + Q) % N
		cy = (cy + P) % M

	# check the wrap-around position (back to start)
	if (cx, cy) in asteroid_map:
		return asteroid_map[(cx, cy)]

	return -1

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


def read_your_input():
	main()