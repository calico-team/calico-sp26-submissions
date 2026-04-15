def extended_gcd(a, b):
	if b == 0:
		return a, 1, 0
	g, x, y = extended_gcd(b, a % b)
	return g, y, x - (a // b) * y

def combine(r1, mod1, r2, mod2):
	g, x, _ = extended_gcd(mod1, mod2)
	if (r2 - r1) % g != 0:
		return None, None
	lcm = mod1 * mod2 // g
	t = (r1 + mod1 * ((r2 - r1) // g * x % (mod2 // g))) % lcm
	return t, lcm
def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	start_x, start_y = X[0], Y[0]
	earlist_step = None
	answer = None

	for i in range(K):
		target_x, target_y = X[i], Y[i]

		steps_x = (target_x - start_x) % N
		steps_y = (target_y - start_y) % M

		gx, ix, _ = extended_gcd(Q, N)
		if steps_x % gx != 0:
			continue
		mx = N // gx
		tx = (steps_x // gx * ix) % mx

		gy, iy, _ = extended_gcd(P, M)
		if steps_y % gy != 0:
			continue
		my = M // gy
		ty = (steps_y // gy * iy) % my

		step, total = combine(tx, mx, ty, my)
		if step is None:
			continue

		step = step % total
		if step == 0:
			step = total

		if earlist_step is None or step < earlist_step:
			earlist_step = step
			answer = i

	return answer

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