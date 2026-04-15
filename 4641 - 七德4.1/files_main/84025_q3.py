number_of_test=int(input())
answer=[]
for i in range(number_of_test):
    A=input()
    B=input()
    n=0
    c=[]
    count=0
    for i in B:
        for j in range(n,len(A)-1):
            if i==A[j]:
                c.append(i)
                count+=1
                n=count
                break
            else:
                c.append("#")
                count+=1
    d="".join(c)
    answer.append(d)

for m in range(len(answer)):
    print(answer[m])