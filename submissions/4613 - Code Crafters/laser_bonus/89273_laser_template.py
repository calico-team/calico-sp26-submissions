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
	best = -1
	ans = -1
	
	# p, m and q, n are coprime; use modular inverse for crt
	inv_q = pow(Q, -1, N)
	inv_p = pow(P, -1, M)
	inv_n = pow(N, -1, M)
	
	for i in range(K):
		dx = (X[i] - x0) % N
		dy = (Y[i] - y0) % M
		
		sx = (dx * inv_q) % N
		sy = (dy * inv_p) % M
		
		# solve s = sx mod N and s = sy mod M
		k = ((sy - sx) * inv_n) % M
		val = sx + k * N
		
		if val == 0:
			val = N * M # wrap around
			
		if best == -1 or val < best:
			best = val
			ans = i
			
	return ans

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
