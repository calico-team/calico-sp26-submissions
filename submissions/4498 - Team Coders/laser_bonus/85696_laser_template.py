from math import gcd

def solve(K, N, M, P, Q, X, Y):
	def modinv(a, m):
		def egcd(a, b):
			if a == 0:
				return b, 0, 1
			g, y, x = egcd(b % a, a)
			return g, x - (b // a) * y, y
		g, x, _ = egcd(a % m, m)
		if g != 1:
			return None
		return x % m
	
	sx, sy = X[0], Y[0]
	best = float('inf')
	result = 0
	
	for i in range(1, K):
		dx = (X[i] - sx) % N
		dy = (Y[i] - sy) % M
		
		if dx == 0 and dy == 0:
			continue
		
		g1 = gcd(Q, N)
		if dx % g1 != 0:
			continue
		
		inv_q = modinv(Q // g1, N // g1)
		if inv_q is None:
			continue
		t1 = (inv_q * (dx // g1)) % (N // g1)
		
		g2 = gcd(P, M)
		if dy % g2 != 0:
			continue
		
		inv_p = modinv(P // g2, M // g2)
		if inv_p is None:
			continue
		t2 = (inv_p * (dy // g2)) % (M // g2)
		
		n1 = N // g1
		n2 = M // g2
		
		found = False
		for k in range(min(n2, 10000)):
			t = t1 + k * n1
			if t % n2 == t2:
				if t > 0 and t < best:
					best = t
					result = i
					found = True
				break
		
		if not found:
			g = gcd(n1, n2)
			if (t2 - t1) % g == 0:
				inv = modinv(n1 // g, n2 // g)
				if inv is not None:
					k = (inv * ((t2 - t1) // g)) % (n2 // g)
					t = t1 + k * n1
					if t == 0:
						t = n1 * n2 // g
					if t < best:
						best = t
						result = i
	
	if best == float('inf'):
		return 0
	
	return result

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
			X.append(int(coords[0]))
			Y.append(int(coords[1]))
		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()