from math import gcd

def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	

	def modInv(a, m):
		a %= m 
		if gcd(a, m) != 1:
			return None
		return pow(a, -1, m)

	x = X[0]
	y = Y[0]

	gx = gcd(Q, N)
	gy = gcd(P, M)

	nx = N // gx
	my = M // gy

	invX = modInv(Q // gx, nx)
	invY = modInv(P // gy, my)

	g = gcd(nx, my)
	n1 = nx // g
	m1 = my // g

	if m1 == 1:
		invN1 = 0
	else:
		invN1 = modInv(n1, m1)

	per = nx * m1
	bestT = per + 1
	bestI = 0

	for i in range(1, K):
		dx = (X[i] - x) % N
		dy = (Y[i] - y) % M

		if dx % gx != 0 or dy % gy != 0:
			continue

		valX = ((dx // gx) * invX) % nx
		valY = ((dy // gy) * invY) % my

		d = valY - valX
		if d % g != 0:
			continue

		if m1 == 1:
			k = 0
		else:
			k = ((d // g) * invN1) % m1

		t = valX + nx * k
		if t == 0:
			t = per

		if t < bestT or (t == bestT and i < bestI):
			bestT = t
			bestI = i

	return bestI

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