def solve(K, N, M, P, Q, X, Y):
		asteriods = {}
		for i in range(K):
			asteriods[(X[i] , Y[i])] = 1
			
		x, y = X[0], Y[0]
		start = (x, y)
		lazarbeam = start
		
		while True:
			x = (x + Q) % N
			y = (y + P) % M
			
			if (x, y) in asteriods:
				return asteriods[(x, y)]

			if (x, y) == start:
				return 0

		def read_your_input():
			import sys
			return sys.stdin.read()