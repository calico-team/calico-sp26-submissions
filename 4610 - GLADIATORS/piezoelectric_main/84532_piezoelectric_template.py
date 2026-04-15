# import sys
import sys


def solve(L, W, E, R):
	triangleArea=2*(L+W)

	electricityPerLap = triangleArea * R
	
	return E//electricityPerLap
	"""
	Return the number of laps needed to charge the car (rounded up)

	L: Length of car
	W: Width of car
	E: Amount of electricity to generate
	R: Electricity generated per unit distance
	"""

# 	# YOUR CODE HERE
# 	triangle_area=2*(L+W)
    


def main():
	input_data=sys.stdin.read().split()
	if not input_data:
		return
	T= int(input_data[0])
	pointer=1
# 	input_data = sys.stdin.read().split()
   

# 	# T_str= input().strip()
# 	# if not T_str:
# 	# 	return
# 	# T = int(T_str)
	for _ in range(T):
		# temp = input().split()
		# if len(temp)<4:
		# 	continue
		# L = int(temp[0])
		# W = int(temp[1])
		# E = int(temp[2])
		# R = int(temp[3])
		L = int(input_data[pointer])
		W = int(input_data[pointer+1])
		E = int(input_data[pointer+2])
		R = int(input_data[pointer+3])
		pointer+=4




		print(solve(L, W, E, R))
def readYourInpur():
	pass

if __name__ == "__main__":
	main()



