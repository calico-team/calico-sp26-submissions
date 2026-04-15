def solve(L, W, E, R):
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance

	# 1. find_perimerter  = 2(l+w)
	  2. in each lap my step=perimeter* R
	  3. electirry_required/lap
	  return that 
	"""
	perimeter =2*(L+W)
	each_lap=perimeter*R
	required=E/each_lap
	

	return int(required)	

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