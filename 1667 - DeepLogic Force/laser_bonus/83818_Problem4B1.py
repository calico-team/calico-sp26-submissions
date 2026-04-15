import sys
input = sys.stdin.readline

def extended_gcd(a, b):
	if a == 0:
		return b, 0, 1
	g, x, y = extended_gcd(b % a, a)
	return g, y - (b // a) * x, x

def crt(r1, m1, r2, m2):
	g, x, _ = extended_gcd(m1, m2)
	if (r2 - r1) % g != 0:
		return None  
	lcm = m1 * m2 // g
	t = (r1 + m1 * ((r2 - r1) // g) * x) % lcm
	return t

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.

	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""

	lazarbeam = (X[0], Y[0])
	sx, sy = lazarbeam

	g1, inv_Q, _ = extended_gcd(Q, N)
	g2, inv_P, _ = extended_gcd(P, M)

	best_t = None
	best_idx = -1

	for i in range(K):
		ax, ay = X[i], Y[i]

		dx = (ax - sx) % N
		dy = (ay - sy) % M

		# solve t*Q ≡ dx mod N
		if dx % g1 != 0:
			continue
		tx = (dx // g1 * inv_Q) % (N // g1)
		mod_x = N // g1

		# solve t*P ≡ dy mod M
		if dy % g2 != 0:
			continue
		ty = (dy // g2 * inv_P) % (M // g2)
		mod_y = M // g2

		# combine with CRT
		t = crt(tx, mod_x, ty, mod_y)
		if t is None:
			continue

		lcm = mod_x * mod_y // (extended_gcd(mod_x, mod_y)[0])

		# t=0 means starting pos, laser only hits after full cycle
		if t == 0:
			t = lcm

		if best_t is None or t < best_t:
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
			X.append(int(coords[0]))
			Y.append(int(coords[1]))

		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()


def read_your_input():
	main()