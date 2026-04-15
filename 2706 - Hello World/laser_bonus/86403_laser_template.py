def solve(K, N, M, P, Q, X, Y):
        lx, ly = X[0], Y[0]
        asteroids = {}
        for i in range(K):
                pos = (X[i], Y[i])
                if pos not in asteroids:
                        asteroids[pos] = i
        for _ in range(N * M+1):
               lx = (lx + Q) % N
               ly = (ly + P) % M
               if (lx, ly) in asteroids:
                       return asteroids[(lx,ly)]

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
