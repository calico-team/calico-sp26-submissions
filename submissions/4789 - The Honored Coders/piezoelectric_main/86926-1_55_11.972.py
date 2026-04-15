
def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance
	"""

	# YOUR CODE HERE
	numLaps = 0
	perimeter = 2 * L + 2 * W
	total = perimeter * R
	#While loop
	while E > total:
		numLaps = numLaps + 1
		total = total + perimeter * R
	return numLaps

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
