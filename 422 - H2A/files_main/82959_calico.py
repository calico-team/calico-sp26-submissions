for _ in range(int(input())):
    a=list(input())
    b=input()
    j=0
    for i in range(len(a)):
        if j<len(b) and a[i]==b[j]:
            j+=1
        else:
            a[i]="#"
    c="".join(a)
    print(c)
    
