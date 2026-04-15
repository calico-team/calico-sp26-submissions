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
	

	import math

	def egcd(a, b):
		if b == 0:
			return a, 1, 0
		g, x1, y1 = egcd(b, a % b)
		return g, y1, x1 - (a // b) * y1

	def modinv(a, m):
		g, x, _ = egcd(a, m)
		if g != 1:
			return None
		return x % m

	x0, y0 = X[0], Y[0]

	best_t = 10**30
	best_idx = 0

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M


		g1 = math.gcd(Q, N)
		if dx % g1 != 0:
			continue

		n1 = N // g1
		q1 = Q // g1
		dx1 = dx // g1

		inv_q = modinv(q1 % n1, n1)
		if inv_q is None:
			continue

		r1 = (dx1 * inv_q) % n1

		
		g2 = math.gcd(P, M)
		if dy % g2 != 0:
			continue

		m1 = M // g2
		p1 = P // g2
		dy1 = dy // g2

		inv_p = modinv(p1 % m1, m1)
		if inv_p is None:
			continue

		r2 = (dy1 * inv_p) % m1

		# CRT merge
		g, s, _ = egcd(n1, m1)
		if (r2 - r1) % g != 0:
			continue

		lcm = (n1 // g) * m1
		t = (r1 + n1 * ((r2 - r1) // g * s % (m1 // g))) % lcm

		if t < best_t:
			best_t = t
			best_idx = i

	return best_idx

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