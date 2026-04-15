def solve(k, n,m,p,q,point):
    strt_x, strt_y=point[0]
    pos={}

    for i in range(k):
        pos[point[i]]=i
    x,y =strt_x,strt_y
    visitd=set()

    while True:
        x= (x+q)%n
        y=(y+p)%m

        if (x,y) ==(strt_x,strt_y):
            return 0
        if (x,y) in pos:
            return pos[(x,y)]
        if (x,y) in visitd:
            return 0
        visitd.add((x, y))

def main():
    T = int(input())
    for _ in range(T):
        K,N,M,P,Q=map(int,input().split())
        point=[]
        for _ in range(K):
            x, y= map(int, input().split())
            point.append((x, y))
        print(solve(K,N,M,P,Q, point))

if __name__ =="__main__":
    main()