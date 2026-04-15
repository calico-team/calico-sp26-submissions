from math import gcd

def eg(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = eg(b, a % b)
    return g, y, x - (a // b) * y

def cm(r1, m1, r2, m2):
    g, p, _ = eg(m1, m2)
    if (r2 - r1) % g != 0:
        return None, None
    lm = m1 // g * m2
    return (r1 + m1 * ((r2 - r1) // g * p % (m2 // g))) % lm, lm

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	et, ai = None, -1
	for i in range(K):
		ga, pa, _ = eg(Q, N)
		gb, pb, _ = eg(P, M)
		dx, dy = (X[i] - X[0]) % N, (Y[i] - Y[0]) % M
		if dx % ga or dy % gb:
			continue
		st, pd = cm((dx // ga * pa) % (N // ga), N // ga, (dy // gb * pb) % (M // gb), M // gb)
		if st is None:
			continue
		if st == 0:
			st = pd
		if et is None or st < et:
			et, ai = st, i
	return ai

def main():
	T = int(input())
	for _ in range(T):
		ln = input().split()
		K, N, M, P, Q = int(ln[0]), int(ln[1]), int(ln[2]), int(ln[3]), int(ln[4])
		X, Y = [], []
		for _ in range(K):
			d = input().split()
			X.append(int(d[0]))
			Y.append(int(d[1]))
		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()