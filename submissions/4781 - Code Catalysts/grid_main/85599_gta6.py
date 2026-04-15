def solve(N, A):
	b=[0]*N
	b[0]=A[0]
	for i in range(1,N):
		choice1=A[i]
		choice2=b[i-1]
		if abs(choice1-A[i])+abs(choice1-b[i-1])<=abs(choice2-A[i])+abs(choice2-b[i-1]):
			b[i]=choice1
		else:
			b[i]=choice2
	return b


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        A = list(map(int, input().split()))
        result = solve(N, A)
        print(' '.join(str(x) for x in result))


if __name__ == '__main__':
    main()
