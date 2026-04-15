def solve(k, n, m, p, q, x, y):
	for i in range(k):
                if min(max(x[0], y[0]), max(x[1], y[1])) == max(x[0], y[0]):
                        return 0
                return 1
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
