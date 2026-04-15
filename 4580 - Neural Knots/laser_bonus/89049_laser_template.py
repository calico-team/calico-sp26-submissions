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

	minn = float('inf')
	hit = -1

	x0, y0 = X[0], Y[0]

	gQ = math.gcd(Q, N)
	gP = math.gcd(P, M)
	n_mod = N // gQ
	m_mod = M // gP

	inv_Q = pow(Q // gQ, -1, n_mod) if n_mod > 1 else 0
	inv_P = pow(P // gP, -1, m_mod) if m_mod > 1 else 0

	g_nm = math.gcd(n_mod, m_mod)
	constt_p = n_mod // g_nm
	q_const = m_mod // g_nm
	invp_const = pow(constt_p, -1, q_const) if q_const > 1 else 0
	lcm_val = constt_p * m_mod

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M

		if dx % gQ != 0 or dy % gP != 0:
			continue

		a1 = ((dx // gQ) * inv_Q) % n_mod if n_mod > 1 else 0
		a2 = ((dy // gP) * inv_P) % m_mod if m_mod > 1 else 0

		if (a2 - a1) % g_nm != 0:
			continue

		rhs = ((a2 - a1) // g_nm) % q_const
		k = (rhs * invp_const) % q_const

		t = a1 + n_mod * k
		t %= lcm_val
		if t == 0:
			t = lcm_val

		if t < minn:
			minn = t
			hit = i

	return hit

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
