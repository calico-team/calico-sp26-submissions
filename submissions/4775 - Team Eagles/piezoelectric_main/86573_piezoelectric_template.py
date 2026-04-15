def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance
	"""

	# YOUR CODE HERE
	total_perimter = 2*(L+W)
	total_steps_required = E/R
	lap = total_steps_required/total_perimter
	rounded_lap = int(lap) + (1 if lap != int(lap) else 0)
	return rounded_lap

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