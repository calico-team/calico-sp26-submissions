def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.

    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    index=0
    if(N>M):
        l=N
    elif(N<M):
        l=M
    else:
        l=N
    pos=[[] for _ in range(l)]
    ast=[[X[i],Y[i]] for i in range(K)]
    for j in range(N):
        if(ast[0][0]+(Q*j)<=N):
            pos[j].append(ast[0][0]+(Q*j))
        else:
            pos[j].append((ast[0][0]+(Q*j))-N)
    for j in range(M):      
        if(ast[0][1]+(P*j)<=M):
            pos[j].append(ast[0][1]+(P*j))
        else:
            pos[j].append((ast[0][1]+(P*j))-M)
    for i in range(len(pos)):
        for k in range(K):
            print(pos[i],ast[k])
            if(pos[i]==ast[k]):
                index=k
                break
        if(index!=0):
            break
    return index

def main():
	
	T = int(input())

	for _ in range(T):
		line = input().split()
		K = int(line[0])
		N = int(line[1])
		M = int(line[2])
		P = int(line[3])
		Q = int(line[4])
		
		X = []
		Y = []
		for _ in range(K):
			coords = input().split()
			a_i = int(coords[0])
			b_i = int(coords[1])
			X.append(a_i)
			Y.append(b_i)

		print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
	main()