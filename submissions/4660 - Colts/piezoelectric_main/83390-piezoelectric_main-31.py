# def winlose(n,p,r,k,curses):
#     if p>sum(curses):
#         print("nah i'd win")
#         return
#     else:
#         nk=k
#         for i in curses:
#             if p-i>=0:
#                 p-=i
#             else:
#                 if nk<=0:
#                     p+=r
#                     nk=k
#                     p-=i
#                 else:
#                     print("nah i'd lose")
#                     return
#             # print(f"power: {p}, rct needed: {nk}, curse power: {i}")
#             nk-=1
#         if p>0:
#             print("nah i'd win")
#             return
#         else:
#             print("nah i'd lose")
#             return
# tc=int(input())
# for i in range(tc):
#     n,p,r,k=list(map(int,input().split()))
#     curses=list(map(int,input().split()))
#     winlose(n,p,r,k,curses)

def elec_laps(l,w,e,r):
    p=2*(l+w)
    spl=p*r
    print(int(e/spl))
tc=int(input())
for i in range(tc):
    l,w,e,r=list(map(int,input().split()))
    elec_laps(l,w,e,r)