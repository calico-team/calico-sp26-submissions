# def winlose(n,p,r,k,curses):
#     defeated=0
#     for i in curses:
#         p-=i
#         if p<0:
#             print("nah i'd lose")
#             return
#         defeated+=1
#         if defeated%k==0:
#             p+=r
#     print("nah i'd win")
#     # if p>sum(curses):
#     #     print("nah i'd win")
#     #     return
#     # else:
#     #     nk=k
#     #     for i in curses:
            

#     #         print(f"power: {p}, rct needed: {nk}, curse power: {i}")
#     #         if p-i<0:
#     #             if nk<=0:
#     #                 p+=r
#     #                 nk=k
#     #         else:
#     #             nk-=1
#     #         p-=i
#     #         # if p<0:
#     #         #     if nk<=0:
#     #         #         p+=r
#     #         #         nk=k
#     #         if p<0:
#     #             print("nah i'd lose")
            
#     #     if p>=0:
#     #         print("nah i'd win")
#     #     else:
#     #         print("nah i'd lose")
    
# tc=int(input())
# for i in range(tc):
#     n,p,r,k=list(map(int,input().split()))
#     curses=list(map(int,input().split()))
#     winlose(n,p,r,k,curses)

# # # def elec_laps(l,w,e,r):
# # #     p=2*(l+w)
# # #     spl=p*r
# # #     print(int(e/spl))
# # # tc=int(input())
# # # for i in range(tc):
# # #     l,w,e,r=list(map(int,input().split()))
# # #     elec_laps(l,w,e,r)




t = int(input())
for i in range(t):
    x=int(input())
    l=list(map(int,input().split()))
    print(str(round(sum(l)/len(l)))+' '*x)