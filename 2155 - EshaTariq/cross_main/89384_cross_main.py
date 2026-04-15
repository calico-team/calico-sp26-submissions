def solve(N, M):
	"""
	Construct an N x M grid with numbers 0-4 such that any cross 
	fitting completely inside contains each number 0-4 exactly once.
	
	N: Number of rows
	M: Number of columns
	"""
	
	# Initialize grid with 0s
	grid = [[0] * M for _ in range(N)]
	
	for r in range(N):
		for c in range(M):
			
			grid[r][c] = (r + c) % 5
	
	return grid

def main():
	T = int(input())
	for _ in range(T):
		temp = input().split()
		N = int(temp[0])
		M = int(temp[1])
		
		grid = solve(N, M)
		
		# Output the grid
		for row in grid:
			print(' '.join(map(str, row)))

if __name__ == "__main__":
	main()