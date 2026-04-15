from math import gcd

def crt(a, n, b, m):
	g = gcd(n, m)
	if (b - a) % g != 0:
		return None

	n1 = n // g
	m1 = m // g
	inv = pow(n1, -1, m1)
	k = ((b - a) // g * inv) % m1
	t = (a + n * k) % (n * m1)
	return t

def solve(K, N, M, P, Q, X, Y):
	x0, y0 = X[0], Y[0]

	gx = gcd(Q, N)
	gy = gcd(P, M)

	nx = N // gx
	my = M // gy

	inv_q = pow(Q // gx, -1, nx)
	inv_p = pow(P // gy, -1, my)

	best_t = None
	best_idx = 0

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M

		if dx % gx != 0 or dy % gy != 0:
			continue

		ax = ((dx // gx) * inv_q) % nx
		ay = ((dy // gy) * inv_p) % my

		t = crt(ax, nx, ay, my)
		if t is None:
			continue

		period = nx * my // gcd(nx, my)
		if t == 0:
			t = period

		if best_t is None or t < best_t or (t == best_t and i < best_idx):
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