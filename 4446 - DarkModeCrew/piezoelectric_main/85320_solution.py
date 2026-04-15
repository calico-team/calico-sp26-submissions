def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)
	"""

	PERIMETERRR = 2 * (L + W)
	ENERGY_ONE_LAP = PERIMETERRR * R
	LAPSS = E // ENERGY_ONE_LAP

	return LAPSS


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