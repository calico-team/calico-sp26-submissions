
def solve(L, W, E, R):
	

    lap = 2*L + 2*W
    return E/(R * lap)

def main():
	T = int(input("enter your input "))
	for _ in range(T):
		temp = input().split( )
		L = int(temp[0])
		W = int(temp[1])
		E = int(temp[2])
		R = int(temp[3])

		print(solve(L, W, E, R))

if __name__ == "__main__":
    main()
