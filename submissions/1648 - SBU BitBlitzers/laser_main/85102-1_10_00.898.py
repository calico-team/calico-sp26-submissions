# Source: https://usaco.guide/general/io
import math
def extend_euclid(a: int, b: int) -> list[int]:
    assert (
        int(a) > 0 and int(b) > 0
    ), "Arguments must be positive, non-zero numeric values."

    # we know that 1 * a + 0 * b = a and 0 * a + 1 * b = b.
    x_arr = [1, 0, int(a)]
    y_arr = [0, 1, int(b)]
    q = -1

    while y_arr[2] > 0:  # run extended Euclidean algo.
        q = x_arr[2] // y_arr[2]
        for i in range(3):
            # keep subtracting multiple of one equation from the other.
            x_arr[i] -= y_arr[i] * q
        x_arr, y_arr = y_arr, x_arr

    return x_arr  # (x[0] * a) + (x[1] * b) = x[2], x[2] = gcd(a, b)
t= int(input())
for _ in range(t):
    k,n,m,p,q = list(map(int,input().split()))
    x0,y0 = map(int,input().split())
    ansi = 0
    ansn = float("inf")
    for i in range(1,k):
        xi,yi = map(int,input().split())
        x = xi-x0
        y = yi-y0
        if x%math.gcd(n,q) or y%math.gcd(m,p):
            continue
        x//=math.gcd(n,q)
        y //= math.gcd(m,p)
        q1 = q//math.gcd(n,q)
        p1 = p//math.gcd(m,p)
        n1 = n//math.gcd(n,q)
        m1 = m//math.gcd(m,p)
        g = math.gcd(n1,m1)
        X = x*pow(q1,-1,n1)
        Y = y*pow(p1,-1,m1)
        #print(i,X,Y,g,n1,m1)
        if (X-Y)%g:
            #print("hi")
            continue
        euclid = extend_euclid(n1,m1)
        N = (X*m1*euclid[1] + Y*n1*euclid[0])//g
        N%= ((n1*m1)//g)
        #print(i,N)
        if N<ansn:
            ansn = N
            ansi = i
    print(ansi,ansn)

        

