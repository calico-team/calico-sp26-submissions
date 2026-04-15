def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance
	"""

	# YOUR CODE HERE
	parameter=2*L+2*W
	per_lap_energy=parameter*R
	# As E already present so we don't need to take it
	# we first take the present energy by starting with zero
	present_energy=0
	# we take number of laps at initial is also 0
	number_of_laps=0
	while present_energy<E:
		energy=present_energy+per_lap_energy
		new_laps=number_of_laps+1
		present_energy=energy
		number_of_laps=new_laps
	return number_of_laps

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