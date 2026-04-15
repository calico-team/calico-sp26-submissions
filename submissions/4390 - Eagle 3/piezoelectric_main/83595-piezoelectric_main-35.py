def solve(L, W, E, R):

	perimeter = L + W + L + W
	ele_per_lap = perimeter * R
	laps_needed = E // ele_per_lap

	return laps_needed

def main():
	T = int(input())
	for _ in range(T):
		temp = input().split()
		L = int(temp[0])
		W = int(temp[1])
		E = int(temp[2])
		R = int(temp[3])

		print(solve(L, W, E, R))

if __name__ == "__main__":
	main()