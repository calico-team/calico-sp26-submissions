import sys
input = sys.stdin.readline

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""

	# put all asteroids in a dict for O(1) lookup
	asteroid_map = {}
	for i in range(K):
		pos = (X[i], Y[i])
		if pos not in asteroid_map:
			asteroid_map[pos] = i

	# laser starts at first asteroid, move one step first
	lazarbeam = (X[0], Y[0])
	cx = (lazarbeam[0] + Q) % N
	cy = (lazarbeam[1] + P) % M

	# keep going until we loop back to start
	while (cx, cy) != lazarbeam:
		if (cx, cy) in asteroid_map:
			return asteroid_map[(cx, cy)]
		cx = (cx + Q) % N
		cy = (cy + P) % M

	# check if we wrapped back to starting asteroid
	if lazarbeam in asteroid_map:
		return asteroid_map[lazarbeam]

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