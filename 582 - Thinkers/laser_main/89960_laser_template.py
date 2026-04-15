def solve(K, N, M, P, Q, X, Y):
	"""
	Find the index of the first asteroid hit by the laser.
	
	K: Number of asteroids
	N, M: Bounds for x- and y-coordinates
	P, Q: Laser movement (P along y-axis, Q along x-axis)
	X: List of x-coordinates of asteroids
	Y: List of y-coordinates of asteroids
	"""
	# YOUR CODE HERE

	first_hit_idx = 0
	min_dist_sq = float('inf')

	for i in range(K):
		x,y = X[i], Y[i]

		found_hit_for_i = False
		dist_q_for_i = float('inf')

		for a in range(100):
			for b in range(100):
				virtual_points = [
					(a*2*N+x, b*2*M+y),
					(a*2*N+x, (b*2+1)*M+(M-y)),
					((a*2+1)*N+(N-x), (b*2*M+y)),
					((a*2+1)*N+(N-x), (b*2+1)*M+(M-y))
				]

				for vx, vy in virtual_points:
					if P*vx == Q*vy:
						d_sq = vx*vx + vy*vy
						if d_sq < dist_q_for_i:
							dist_q_for_i = d_sq
							found_hit_for_i = True
	
	if found_hit_for_i and dist_q_for_i < min_dist_sq:
		min_dist_sq = dist_q_for_i
		first_hit_idx = i + 1

	return first_hit_idx

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