from math import gcd
def ext_gcd(a, b):
	if b == 0:
		return a, 1, 0
	g, x1, y1 = ext_gcd(b, a % b)
	return g, y1, x1 - (a // b) * y1


def mod_invers(a, m):
	g, x, _ = ext_gcd(a, m)
	return x % m

def solve_congr(a, b, m):

    g = gcd(a, m)
    if b % g != 0:
        return None
    a //= g
    b //= g
    m //= g



    inv = mod_invers(a % m, m)

    return (b * inv) % m, m

def crt(a1, m1, a2, m2):
    g = gcd(m1, m2)

    if (a2 - a1) % g != 0:
        return None

    m1_g = m1 // g
    m2_g = m2 // g

    _, x, _ = ext_gcd(m1_g, m2_g)
    x %= m2_g

    k = ((a2 - a1) // g * x) % m2_g
    t = (a1 + m1 * k) % (m1 * m2_g)
    return t, m1 * m2_g

def solve(K, N, M, P, Q, X, Y):

    x0, y0 = X[0], Y[0]
    best_t = None

    best_indx = None

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        x_res = solve_congr(Q, dx, N)
        y_res = solve_congr(P, dy, M)

        if x_res is None or y_res is None:
            continue

        tx, mx = x_res
        ty, my = y_res

        result = crt(tx, mx, ty, my)
        if result is None:
            continue

        t, _ = result

        if t == 0:
            continue

        if best_t is None or t < best_t or (t == best_t and i < best_indx):
            best_t = t
            best_indx = i

    return best_indx if best_indx is not None else 0


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