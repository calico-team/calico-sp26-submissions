from math import gcd

def extended_gcd(a, b):
	"""Extended Euclidean algorithm"""
	if a == 0:
		return b, 0, 1
	g, x1, y1 = extended_gcd(b % a, a)
	x = y1 - (b // a) * x1
	y = x1
	return g, x, y

def mod_inverse(a, m):
	"""Find modular inverse of a mod m"""
	g, x, _ = extended_gcd(a % m, m)
	if g != 1:
		return None
	return x % m

def solve_crt(a1, m1, a2, m2):
	"""Solve x ≡ a1 (mod m1) and x ≡ a2 (mod m2) using CRT"""
	g = gcd(m1, m2)
	if (a1 - a2) % g != 0:
		return None
	
	# Extended GCD to get Bezout coefficients
	_, p, q = extended_gcd(m1, m2)
	lcm = m1 // g * m2
	x = (a1 + m1 * p * ((a2 - a1) // g)) % lcm
	return x, lem

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser using modular arithmetic.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	x0, y0 = X[0], Y[0]
	min_lz = float('inf')
	min_idx = -1
	
	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M
		
		# Solve: Q * lz ≡ dx (mod N) and P * lz ≡ dy (mod M)
		
		# Check x-condition: Q * lz ≡ dx (mod N)
		g_q = gcd(Q, N)
		if dx % g_q != 0:
			continue
		
		Q_red = Q // g_q
		N_red = N // g_q
		dx_red = dx // g_q
		
		inv_q = mod_inverse(Q_red, N_red)
		if inv_q is None:
			continue
		
		lz_x = (dx_red * inv_q) % N_red
		
		# Check y-condition: P * lz ≡ dy (mod M)
		g_p = gcd(P, M)
		if dy % g_p != 0:
			continue
		
		P_red = P // g_p
		M_red = M // g_p
		dy_red = dy // g_p
		
		inv_p = mod_inverse(P_red, M_red)
		if inv_p is None:
			continue
		
		lz_y = (dy_red * inv_p) % M_red
		
		# Combine using CRT
		result = solve_crt(lz_x, N_red, lz_y, M_red)
		if result is None:
			continue
		
		lz, period = result
		if lz == 0:
			lz = period
		
		if lz < min_lz:
			min_lz = lz
			min_idx = i
	
	return min_idx

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