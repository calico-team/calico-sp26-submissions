import math

def solve(K, N, M, P, Q, X, Y):
    def sgcd(a, b):
        if b == 0:
            return (a, 1, 0)
        g, x1, y1 = sgcd(b, a % b)
        return (g, y1, x1 - (a // b) * y1)

    def mod_inv(a, mod):
        g, x, _ = sgcd(a, mod)
        if g != 1:
            return None
        return x % mod

    def noncoprime(a1, m1, a2, m2):
        g = math.gcd(m1, m2)
        if (a2 - a1) % g != 0:
            return None
        lcm = (m1 * m2) // g
        m1g = m1 // g
        m2g = m2 // g
        inv = mod_inv(m1g % m2g, m2g)
        if inv is None: return None
        k = ((a2 - a1) // g * inv) % m2g
        return (a1 + m1 * k) % lcm

    x0, y0 = X[0], Y[0]
    gx, gy = math.gcd(Q, N), math.gcd(P, M)
    n1, m1 = N // gx, M // gy
    
    inv_q = mod_inv(Q // gx, n1)
    inv_p = mod_inv(P // gy, m1)
    
    
    cycle = (n1 * m1) // math.gcd(n1, m1)
    
    best_time = float('inf')
    best_idx = -1

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M
        
        if dx % gx != 0 or dy % gy != 0:
            continue
            
        t_x = (dx // gx * inv_q) % n1
        t_y = (dy // gy * inv_p) % m1
        
        t = noncoprime(t_x, n1, t_y, m1)
        
        if t is not None:
            
            if t == 0:
                t = cycle
            
            if t < best_time:
                best_time = t
                best_idx = i
            elif t == best_time:
                
                if best_idx == -1 or i < best_idx:
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