n=int(input())
for i in range(n):
    first=input()
    second=input()
    file=[]
    start=0
    for j in first:
        if start<len(second) and j==second[start]:
            file.append(j)
            start+=1
        else:
            file.append("#")
    final=''
    for j in range(len(file)):
        final+=file[j]
    print(final)
            
