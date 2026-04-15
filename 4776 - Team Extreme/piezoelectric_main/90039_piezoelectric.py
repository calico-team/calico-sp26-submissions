def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance
	"""

	perimeter = 2 * (L + W)
	count = E // (perimeter * R)
	return count

def main():
	T = int(input())
	for _ in range(T):
		line = input().split()
		L = int(line[0])
		W = int(line[1])
		E = int(line[2])
		R = int(line[3])

		print(solve(L, W, E, R))

if __name__ == "__main__":
	main()