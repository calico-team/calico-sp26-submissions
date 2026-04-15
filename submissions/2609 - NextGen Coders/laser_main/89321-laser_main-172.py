def solve(K, N, M, P, Q, X, Y):
    # store asteroid positions with index
    pos = {}
    for i in range(K):
        pos[(X[i], Y[i])] = j


    x, y = X[0], Y[0]

    visited = set()

    while True:

        x = (x + Q) % N
        y = (y + P) % M

        if (x, y) in pos:
            return pos[(x, y)]

        if (x, y) in visited:
            return 1

        visited.add((x, y))

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