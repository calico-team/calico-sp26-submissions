def solve(L, W, E, R):
    
    """
    Return the number of laps needed to charge the car (rounded up)

    L: Length of car
    W: Width of car
    E: Amount of electricity to generate
    R: Electricity generated per unit distance
    """

    both_length = (L *2)* R  
    # print(both_length)
    both_width = (W *2)* R
    # print(both_width)

    ans = E/(both_length + both_width) 
    return int(ans)

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