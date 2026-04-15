from math import gcd
def solve(K, N, M, P, Q, X, Y):
	def extgcd(a, b):
		if b == 0:
			return a, 1, 0
		g, x, y = extgcd(b, a % b)
		return g, y, x - (a // b) * y

	def solve_linear(a, b, m):
		g = gcd(a, m)
		if b % g != 0:
			return None, None
		a, b, m = a//g, b//g, m//g
		return (b * pow(a, -1, m)) % m, m

	def crt(r1, m1, r2, m2):
		g, x, _ = extgcd(m1, m2)
		if (r2 - r1) % g != 0:
			# double check consistency: if r1 already satisfies eq2
			if r1 % m2 == r2 % m2:
				return r1, m1  # r1 is already a valid solution
			return None, None
		lcm = m1 // g * m2
		r = (r1 + m1 * ((r2 - r1) // g * x % (m2 // g))) % lcm
		return r % lcm, lcm

	def solve_system(equations):
		remainders, moduli = [], []
		for a, b, m in equations:
			r, mod = solve_linear(a, b, m)
			if r is None:
				return None
			remainders.append(r)
			moduli.append(mod)

		r, m = remainders[0], moduli[0]
		for i in range(1, len(remainders)):
			r, m = crt(r, m, remainders[i], moduli[i])
			if r is None:
				return None
		return r % m, m
	
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	asteroids = []
	
	for k in range(K):
		# Usage:
		# 2x ≡ 4 (mod 3), 3x ≡ 9 (mod 5)
		# tQ = (x2-x1) (mod N), tP = (y2-y1) (mod M)
		eq1 = (Q, (X[k]-X[0]) % N, N)
		eq2 = (P, (Y[k]-Y[0]) % M, M)
		result = solve_system([eq1, eq2])
		if result is None:
			continue
		r, m = result
		if r == 0:  # find smallest positive t
			r = m   # next occurrence is at t=lcm
		asteroids.append((r, k))

	asteroids.sort()

	return asteroids[0][1]

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