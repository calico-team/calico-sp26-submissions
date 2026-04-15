for _ in range(int(input())):
    l,w,e,r = map(int,input().split())
    p = (2*l+2*w)*r 
    if (e/(p) > e//(p)):
        print(e//(p) +1)
    else:
        print(e//(p))