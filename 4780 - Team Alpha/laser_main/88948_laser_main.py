def solve(K, N, M, P, Q, X, Y):
    
    def egcd(a, b):
        if b == 0:
            return a, 1, 0
        g, x1, y1 = egcd(b, a % b)
        return g, y1, x1 - (a // b) * y1

    def modinv(a, mod):
        g, x, _ = egcd(a, mod)
        if g != 1:
            return None
        return x % mod

    
    def min_t_linear(b, a, m):
        if m == 1:
            return 0, 1
        a %= m
        b %= m
        if a == 0:
            return (0, 1) if b == 0 else None
        g = egcd(a, m)[0]
        if b % g != 0:
            return None
        a1, m1, b1 = a // g, m // g, b // g
        inv = modinv(a1 % m1, m1)
        return (b1 * inv) % m1, m1   

    def crt(a1, m1, a2, m2):
        g, x, y = egcd(m1, m2)
        if (a2 - a1) % g != 0:
            return None, None
        
        lcm = m1 // g * m2
        t = (a1 + ((a2 - a1) // g * x % (m2 // g)) * m1) % lcm
        return t, lcm

    x0, y0 = X[0], Y[0]

    best_t = None
    best_idx = 0

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        res1 = min_t_linear(dx, Q, N)
        res2 = min_t_linear(dy, P, M)

        if res1 is None or res2 is None:
            continue

        t1, mod1 = res1
        t2, mod2 = res2

        
        t, lcm = crt(t1, mod1, t2, mod2)

        if t is None:
            continue

        if t == 0:
            t = lcm  

        if best_t is None or t < best_t:
            best_t = t
            best_idx = i

    return best_idx

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



