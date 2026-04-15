number_of_test=int(input())
answer=[]
for i in range(number_of_test):
    A=input()
    B=input()
    n=0
    c=[]
    count=0
    for i in B:
        for j in range(n,len(A)):
            if i==A[j]:
                c.append(i)
                count+=1
                n=count
                break
            else:
                c.append("#")
                count+=1
    if len(c)!=len(A):
        for i in range(len(A)-len(c)):
            c.append("#")            
    d="".join(c)
    answer.append(d)

for m in range(len(answer)):
    print(answer[m])
