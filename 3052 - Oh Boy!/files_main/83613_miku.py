# def solve(L, W, E, R):
# 	"""
# 	Return the number of laps needed to charge the car (rounded up)

# 	L: Length of car
# 	W: Width of car
# 	E: Amount of electricity to generate
# 	R: Electricity generated per unit distance
# 	"""

# 	# YOUR CODE HERE
#     P = 2*L+2*W
#     count = 1
#     while P * R * count < E:
#         count += 1
# 	return count -1

# def main():
# 	T = int(input())
# 	for _ in range(T):
# 		temp = input().split()
# 		L = int(temp[0])
# 		W = int(temp[1])
# 		E = int(temp[2])
# 		R = int(temp[3])

# 		print(solve(L, W, E, R))

# if __name__ == "__main__":
# 	main()

def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    # YOUR CODE HERE
    new = ""
    done = False
    for i in range(len(B)):
        for j in range(len(A)):
            if A[j:j+1] == B[i:i+1] and done == False:
                done = True
                new += A[j:j+1]
            elif done == False:
                new += "#"
        done = False
        return new

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()