for _ in range(int(input())):
    l,w,e,r = map(int,input().split())
    a = e//((2*(l+w))*r)
    print(a)