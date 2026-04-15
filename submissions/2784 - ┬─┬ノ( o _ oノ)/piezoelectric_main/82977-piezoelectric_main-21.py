T = int(input())
for _ in range(T):
	temp = input().split()
	L = int(temp[0])
	W = int(temp[1])
	E = int(temp[2])
	R = int(temp[3])
	p=(L*2)+(W*2)
	perlap = p*R
	numm = E//perlap
	if numm < E/perlap:
		numm = numm+1
	print(numm)

