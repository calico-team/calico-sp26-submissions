def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	start_x = X[0]
    start_y = Y[0]

    from math import gcd

    # LCM to find cycle length
    lcm = (N * M) // gcd(N, M)

    # map asteroid positions to index
    pos = {}
    for i in range(K):
        pos[(X[i], Y[i])] = i

    lazarbeam = 0

    curr_x, curr_y = start_x, start_y

    for step in range(1, lcm + 1):
        curr_x = (curr_x + Q) % N
        curr_y = (curr_y + P) % M

        lazarbeam += 1

        if (curr_x, curr_y) in pos:
            return pos[(curr_x, curr_y)]

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