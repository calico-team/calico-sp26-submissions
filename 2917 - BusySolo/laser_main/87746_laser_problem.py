def solve(K, N, M, P, Q, X, Y):
    
    asteroids = {}
    
    for i in range(K):
        asteroids[(X[i], Y[i])] = i    
    x = X[0]
    y = Y[0]
    
    # simulate movement
    while True:
        x = (x + Q) % N
        y = (y + P) % M
        
        if (x, y) in asteroids:
            return asteroids[(x, y)]
        
        if x == X[0] and y == Y[0]:
            return 0

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