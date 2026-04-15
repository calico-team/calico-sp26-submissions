def solve(K, N, M, P, Q, X, Y):
	hit = False
	xCord = X[0]
	yCord = Y[0]
	answer = 0
	while not hit:
		if xCord + Q <= N:
			xCord += Q
		else:
			xCord = (xCord+Q)-N
		if yCord + P <= M:
			yCord += P
		else:
			yCord = (yCord+P)-M
		for i in range(K):
			if X[i] == xCord and Y[i] == yCord:
				answer = i
				hit = True
				return answer
	return answer

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