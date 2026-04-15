import math
import sys

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = egcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def inv_mod(a, m):
    a %= m
    if m == 1:
        return 0
    g, x, _ = egcd(a, m)
    if g != 1:
        return None
    return x % m

def solve_linear_congruence(coeff, rhs, mod):
    """
    Solve_Coeff * t ≡ rhs (mod mod)
    Returns (residue, reduced_modulus) meaning t ≡ residue (mod reduced_modulus)
    or otherwise (None, None) .
    """
    g = math.gcd(coeff, mod)
    if rhs % g != 0:
        return None, None

    coeff //= g
    rhs //= g
    mod //= g

    if mod == 1:
        return 0, 1

    inv = inv_mod(coeff, mod)
    if inv is None:
        return None, None

    return (rhs * inv) % mod, mod

def crt(a, n, b, m):
    """     Solve:
        t ≡ a (mod n)
        t ≡ b (mod m)
    Returns smallest_positive_solution_t and modulus lcm(n, m), or (None, None).
    """
    if n == 1 and m == 1:
        return 1, 1

    g = math.gcd(n, m)
    if (b - a) % g != 0:
        return None, None

    lcm = n // g * m
    n1 = n // g
    m1 = m // g

    if m1 == 1:
        x = a % lcm
    else:
        inv = inv_mod(n1 % m1, m1)
        if inv is None:
            return None, None
        k = (((b - a) // g) * inv) % m1
        x = (a + n * k) % lcm

    if x == 0:
        x = lcm
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
	best_idx = 0

	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M

		rx, nx = solve_linear_congruence(Q, dx, N)
		if rx is None:
			continue

		ry, ny = solve_linear_congruence(P, dy, M)
		if ry is None:
			continue

		t, _ = crt(rx, nx, ry, ny)
		if t is None:
			continue

		if best_t is None or t < best_t or (t == best_t and i < best_idx):
			best_t = t
			best_idx = i

	return best_idx	

	
	return 0

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