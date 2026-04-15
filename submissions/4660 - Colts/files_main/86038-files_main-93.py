# def files(a,b):
    # a=list(a)
    # # for i in range(len(a)):
    # #     if a[i] not in b:
    # #         a[i]='#'
    # b=list(b)
    # for i in range(len(b)):
    #     for j in range(a.index(b[i]),len(a)):
    #         # print(b[i],a[j])
    #         if b[i]==a[j]:
    #             # print(b[i],a[j])
    #             break
    #         else:
    #             # print(a[j])
    #             a[j]='#'
    #         # print(a)
    # return ''.join(a)


def files(a,b):
    b=list(b)
    n=[]
    for i in a:
        if i==b[0]:
            n.append(i)
            b.pop(0)
        else:
            n.append('#')
        if not b:
            b=['']
    return ''.join(n)


tc=int(input())
for i in range(tc):
    a=input()
    b=input()
    print(files(a,b))