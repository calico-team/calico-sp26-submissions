def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	def eg(a, b):
		if b == 0:
			return a, 1, 0
		g, x, y = eg(b, a % b)
		return g, y, x - (a // b) * y
 
	def lc(a, b, m):
		from math import gcd
		g = gcd(a, m)
		if b % g != 0:
			return None
		a_, b_, m_ = a // g, b // g, m // g
		_, inv, _ = eg(a_, m_)
		t0 = (b_ * inv) % m_
		return (t0, m_)
 
	def crt(r1, m1, r2, m2):
		from math import gcd
		g = gcd(m1, m2)
		if (r2 - r1) % g != 0:
			return None
		lcm = m1 * m2 // g
		_, inv, _ = eg(m1 // g, m2 // g)
		t0 = (r1 + m1 * ((r2 - r1) // g * inv % (m2 // g))) % lcm
		return (t0, lcm)
 
	lbeam = None
	x0, y0 = X[0], Y[0]
	bt = None
	bi = None
 
	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M
 
		sx = lc(Q, dx, N)
		sy = lc(P, dy, M)
 
		if sx is None or sy is None:
			continue
 
		tx, mx = sx
		ty, my = sy
 
		combined = crt(tx, mx, ty, my)
		if combined is None:
			continue
 
		t0, mod = combined
		if t0 == 0:
			t0 = mod  
 
		if bt is None or t0 < bt:
			bt = t0
			bi = i
 
	lbeam = bi
	return lbeam

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