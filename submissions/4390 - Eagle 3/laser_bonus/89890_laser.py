def common_divisor(a, b):
	
	if b == 0:
		return a , 1, 0
	
	d, x, y = common_divisor(b, a % b)
	
	return d, y, x - (a // b) * y

def mod_inverse(n, m):
	
	while m != 0:
		
		n , m = m, n % m
		
	return n

def congurence(c , d , f):
	
	e = mod_inverse(c, f)
	
	if d % e != 0:
		return None
	
	g , h , i = c // e , d // e , f // e
	
	l , x , y = common_divisor(g, i)
	
	return (h * x) % i , i

def combine(j , k , l , m):
	
	o , p , q = common_divisor(k , m)
	
	if (l - j) % o != 0:
		return None
	
	n = k * m // o
	
	r = (j + k * ((l - j) // o * p % (m // o))) % n
	
	return r , n


def solve(K, N, M, P, Q, X, Y):

	x0 = X[0]
	y0 = Y[0]

	time = float('inf')
	index = -1

	for i in range(K):
		
		d_x = (X[i] - x0) % N
		d_y = (Y[i] - y0) % M

		s = congurence(Q, d_x, N)
		t = congurence(P, d_y, M)

		if s is None or t is None:
			continue

		p , q = s
		r , y = t

		com = combine(p, q, r, y)

		if com is None:
			continue
 
		z , l = com

		if z == 0:
			
			z = l

		if z < time:

			time = z
			index = i
			
			
	return index

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