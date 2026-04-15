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
	# YOUR CODE HERE
	x0, y0 = X[0], Y[0]
	best_t = -1
	lazarbeam = -1
	
	for i in range(K):
		xi, yi = X[i], Y[i]
		dx = (xi - x0) % N
		dy = (yi - y0) % M
		
		# Solve t*Q = dx (mod N)
		g1 = math.gcd(Q, N)
		if dx % g1 != 0:
			continue
		mod_n = N // g1
		tx = ((dx // g1) * pow(Q // g1, -1, mod_n)) % mod_n
		
		# Solve t*P = dy (mod M)
		g2 = math.gcd(P, M)
		if dy % g2 != 0:
			continue
		mod_m = M // g2
		ty = ((dy // g2) * pow(P // g2, -1, mod_m)) % mod_m
		
		# Solve t = tx (mod mod_n) and t = ty (mod mod_m)
		g3 = math.gcd(mod_n, mod_m)
		if (ty - tx) % g3 != 0:
			continue
		
		target_m = mod_m // g3
		try:
			inv_val = pow(mod_n // g3, -1, target_m)
			k = (((ty - tx) // g3) * inv_val) % target_m
			t = tx + k * mod_n
			
			if t == 0:
				t = (mod_n * mod_m) // g3
				
			if best_t == -1 or t < best_t:
				best_t = t
				lazarbeam = i
		except ValueError:
			continue
			
	return lazarbeam

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