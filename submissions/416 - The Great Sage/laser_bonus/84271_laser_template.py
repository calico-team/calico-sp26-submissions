from math import gcd

def egcd(a, b):
	if b == 0:
		return (a, 1, 0)
	g, x1, y1 = egcd(b, a % b)
	return (g, y1, x1 - (a // b) * y1)

def modinv(a, m):
	g, x, _ = egcd(a, m)
	return x % m

def crt(a1, m1, a2, m2):
	g = gcd(m1, m2)
	if (a2 - a1) % g != 0:
		return None, None
	lcm = m1 // g * m2
	m1g = m1 // g
	m2g = m2 // g
	k = ((a2 - a1) // g * modinv(m1g % m2g, m2g)) % m2g
	x = (a1 + m1 * k) % lcm
	return x, lcm


def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	x0, y0 = X[0], Y[0]
	best_t = None
	best_i = 0

	gx = gcd(Q, N)
	gy = gcd(P, M)

	nx = N // gx
	ny = M // gy

	inv_q = modinv(Q // gx, nx)
	inv_p = modinv(P // gy, ny)

	lazarbeam = 0

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M

		if dx % gx != 0 or dy % gy != 0:
			continue

		tx = (dx // gx) * inv_q % nx
		ty = (dy // gy) * inv_p % ny

		t, period = crt(tx, nx, ty, ny)
		if t is None:
			continue
		if t == 0:
			t = period

		if best_t is None or t < best_t or (t == best_t and i < best_i):
			best_t = t
			best_i = i

	return best_i

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