from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_linear_congruence(a, b, m):
    g = gcd(a, m)
    if b % g != 0:
        return None
    a, b, m = a // g, b // g, m // g
    _, inv, _ = extended_gcd(a % m, m)
    return (b * inv) % m, m

def crt(r1, m1, r2, m2):
    g = gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    m2g = m2 // g
    lcm = m1 * m2g
    _, inv, _ = extended_gcd((m1 // g) % m2g, m2g)
    k = ((r2 - r1) // g * inv) % m2g
    return (r1 + m1 * k) % lcm, lcm

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
	best_t, best_idx = None, None

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M

		res_x = solve_linear_congruence(Q, dx, N)
		if res_x is None:
			continue
		tx, nx = res_x

		res_y = solve_linear_congruence(P, dy, M)
		if res_y is None:
			continue
		ty, my = res_y

		res = crt(tx, nx, ty, my)
		if res is None:
			continue
		t, period = res

		if t == 0 and i == 0:
			t = period

		if best_t is None or t < best_t:
			best_t, best_idx = t, i

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