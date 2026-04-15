def move_laser(Q,P,l,x_bound,y_bound):
    if l[0]+Q<x_bound:
        l[0]=l[0]+Q
    else:
        l[0]=l[0]+Q-x_bound
    if l[1]+P<=y_bound:
        l[1]=l[1]+P
    else:
        l[1]=l[1]+P-y_bound
    return l
def all_points(x,y,x_bound,y_bound):
    points=[]
    while x<x_bound and y<y_bound:
        points.append([x,y])
        x,y=x+1,y+1
    return points
def solve(K, N, M, P, Q, X, Y):
    grid=[]
    asteroids=[]
    for i in range(N):
        temp=[]
        for j in range(M):
            temp.append("")
        grid.append(temp)
    for k in range(K):
        grid[Y[k]][X[k]]="O"
        asteroids.append([Y[k],X[k]])
    l=[0,0]
    hit=False
    while not hit:
        l=move_laser(Q,P,l,M,N)
        points=all_points(l[0],l[1],M,N)
        for i in points:
            if grid[i[0]][i[1]]=="O":
                hit=True
                a=i
                break
    for i in range(len(asteroids)):
        if asteroids[i]==a:
            return str(i)
print(solve(3,6,8,2,1,[1,1,5],[1,5,1]))
"""def main():
	
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
	main()"""