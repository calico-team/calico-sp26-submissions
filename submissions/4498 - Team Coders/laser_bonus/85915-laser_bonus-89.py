from math import gcd

def solve(K, N, M, P, Q, X, Y):
	def egcd(a, b):
		if b == 0:
			return a, 1, 0
		g, x1, y1 = egcd(b, a % b)
		return g, y1, x1 - (a // b) * y1
	
	def modinv(a, m):
		g, x, _ = egcd(a, m)
		return x % m if g == 1 else None
	
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
		
		n1 = N // g1
		inv_q = modinv(Q // g1, n1)
		if inv_q is None:
			continue
		t1 = (inv_q * (dx // g1)) % n1
		
		g2 = gcd(P, M)
		if dy % g2 != 0:
			continue
		
		n2 = M // g2
		inv_p = modinv(P // g2, n2)
		if inv_p is None:
			continue
		t2 = (inv_p * (dy // g2)) % n2
		
		g = gcd(n1, n2)
		if (t2 - t1) % g != 0:
			continue
		
		inv = modinv(n1 // g, n2 // g)
		if inv is None:
			continue
		
		k = (inv * ((t2 - t1) // g)) % (n2 // g)
		t = t1 + k * n1
		
		if t == 0:
			t = n1 * (n2 // g)
		
		if t < best:
			best = t
			result = i
	
	return result if best != float('inf') else 0

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