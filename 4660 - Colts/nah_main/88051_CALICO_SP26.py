def winlose(n,p,r,k,curses):
    if p>sum(curses):
        print("nah i'd win")
        return
    else:
        nk=k
        for i in curses:
            p-=i
            if p<0:
                if nk<=0:
                    p+=r
                    nk=k
                    p-=i
                else:
                    print("nah i'd lose")
                    return
            # print(f"power: {p}, rct needed: {nk}, curse power: {i}")
            nk-=1
        print("nah i'd win")
tc=int(input())
for i in range(tc):
    n,p,r,k=list(map(int,input().split()))
    curses=list(map(int,input().split()))
    winlose(n,p,r,k,curses)

# # def elec_laps(l,w,e,r):
# #     p=2*(l+w)
# #     spl=p*r
# #     print(int(e/spl))
# # tc=int(input())
# # for i in range(tc):
# #     l,w,e,r=list(map(int,input().split()))
# #     elec_laps(l,w,e,r)