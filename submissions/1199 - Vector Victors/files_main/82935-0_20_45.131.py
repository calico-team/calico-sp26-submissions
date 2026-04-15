def solve(A: str, B: str) -> str:
	idxA = 0
	idxB = 0
	while idxB < len(B):
		while A[idxA] != B[idxB]:
			print(A[idxA], B[idxB])
			A = A[:idxA] + '#' + A[idxA+1:]
			idxA+=1
		idxA+=1
		idxB+=1
	A =  A[:idxA] + (len(A) - idxA) * '#'
	print(A)
	

	# YOUR CODE HERE
	return ""

def main():
	T = int(input())
	for _ in range(T):
		A = input()
		B = input()
		print(solve(A, B))

if __name__ == '__main__':
	main()
