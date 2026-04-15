def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = egcd(b, a % b)
    return g, y, x - (a // b) * y

def lin_cong(a, b, m):
    # solve a*t = b (mod m)
    g, x, _ = egcd(a % m, m)
    if b % g != 0:
        return None
    mod = m // g
    t0 = (x * (b // g)) % mod
    return (t0, mod)

def crt(r1, m1, r2, m2):
    # combine t = r1 (mod m1) and t = r2 (mod m2)
    g, p, _ = egcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 * m2 // g
    t = (r1 + m1 * ((p * ((r2 - r1) // g)) % (m2 // g))) % lcm
    return (t, lcm)

def solve(K, N, M, P, Q, X, Y):
    """
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
    sx, sy = X[0], Y[0]
    ans_t = None
    ans_i = None

    for i in range(K):
        dx = (X[i] - sx) % N
        dy = (Y[i] - sy) % M

        cx = lin_cong(Q, dx, N)
        cy = lin_cong(P, dy, M)

        if cx is None or cy is None:
            continue

        res = crt(cx[0], cx[1], cy[0], cy[1])
        if res is None:
            continue

        t, period = res
        if t == 0:
            t = period

        if ans_t is None or t < ans_t:
            ans_t = t
            ans_i = i

    return ans_i

# def solve(K, N, M, P, Q, X, Y):
# 	"""
# 	Find the index of the first asteroid hit by the laser.
	
# 	K: Number of asteroids
# 	N, M: Bounds for x- and y-coordinates
# 	P, Q: Laser movement (P along y-axis, Q along x-axis)
# 	X: List of x-coordinates of asteroids
# 	Y: List of y-coordinates of asteroids
# 	"""
# 	# YOUR CODE HERE
# 	return 0

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