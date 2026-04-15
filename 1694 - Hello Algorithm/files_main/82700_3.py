numCases = int(input())

for _ in range(numCases):
    strA = input()
    strB = input()
    
    idxB = 0
    ansStr = ""
    
    for charA in strA:
        if idxB < len(strB) and charA == strB[idxB]:
            ansStr += charA
            idxB += 1
        else:
            ansStr += '#'
            
    print(ansStr)