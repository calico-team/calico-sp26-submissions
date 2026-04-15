import math
def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	mintime = float('inf')
	minidx = -1

	for i in range(K):
		dx = (X[i] - X[0]) % N
		dy = (Y[i] - Y[0]) % M

		g1 = math.gcd(Q, N)
		if dx % g1 != 0:
			continue
		n1 = N // g1
		q1 = Q // g1
		dx1 = dx // g1
		t1 = (pow(q1, -1, n1) * dx1) % n1

		g2 = math.gcd(P, M)
		if dy % g2 != 0:
			continue
		m1 = M // g2
		p1 = P // g2
		dy1 = dy // g2
		t2 = (pow(p1, -1, m1) * dy1) % m1

		g = math.gcd(n1, m1)
		if t1 % g != t2 % g:
			continue

		np = n1 // g
		mp = m1 // g
		diff = (t2 - t1) // g
		k = (diff * pow(np, -1, mp)) % mp
		t = t1 + k * n1

		l = np * m1

		if t == 0:
			t = l

		if t < mintime:
			mintime = t
			minidx = i

	return minidx


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