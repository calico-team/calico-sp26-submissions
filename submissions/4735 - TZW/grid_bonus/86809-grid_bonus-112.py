T = int(input())

for i in range(T):
    N = int(input())
    
    A = input().split()
    aList = []
    for a in A:
        aList.append(a)
    
    bList = []
    for n in aList:
        bList.append(n)

    output = ""
    for x in bList:
        output += str(x) + " "
    
    print(output.strip())
