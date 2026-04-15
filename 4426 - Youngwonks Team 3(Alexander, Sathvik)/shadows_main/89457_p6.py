#p6
def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    maxObj=[]
    minObj=[]
    shadowObj=[]
    maxVolume=0
    for layer in range(N):
        sliceS1=[]
        sliceS2=[]
        for column in range(N):
            if S1[layer][column]=="#":
                sliceS1.append(1)
            else:
                sliceS1.append(0)
            if S2[layer][column]=="#":
                sliceS2.append(1)
            else:
                sliceS2.append(0)
        slice=[]
        shadowSlice=[]
        for columnS1 in range(N):
            temp=[]
            shadowTemp=[]
            for columnS2 in range(N):
                maxVolume+=sliceS1[columnS1]*sliceS2[columnS2]
                temp.append(sliceS1[columnS1]*sliceS2[columnS2])
                shadowTemp.append(0)
            slice.append(temp)
            shadowSlice.append(shadowTemp)
        maxObj.append(slice)
        minObj.append(slice)
        shadowObj.append(shadowSlice)
    for layer in range(N):
        #first pass
        for row in range(N):
            shadowed=False
            for column in range(N):
                if maxObj[layer][row][column]==1:
                    if shadowed:
                        shadowObj[layer][row][column]+=1
                    else:
                        shadowed=True
        for column in range(N):
            shadowed=False
            for row in range(N):
                if maxObj[layer][row][column]==1:
                    if shadowed:
                        if shadowObj[layer][row][column]==1:
                            minObj[layer][row][column]=0
                    else:
                        shadowed=True
        #second pass
        for r in range(N):
            row=N-1-r
            shadowed=False
            for c in range(N):
                column=N-1-c
                if maxObj[layer][row][column]==1:
                    if shadowed:
                        shadowObj[layer][row][column]+=1
                    else:
                        shadowed=True
        for c in range(N):
            column=N-1-c
            shadowed=False
            for r in range(N):
                row=N-1-r
                if maxObj[layer][row][column]==1:
                    if shadowed:
                        if shadowObj[layer][row][column]==1:
                            minObj[layer][row][column]=0
                    else:
                        shadowed=True
    minVolume=0
    for layer in range(N):
        for row in range(N):
            for column in range(N):
                minVolume+=minObj[layer][row][column]
    print(maxVolume,minVolume)
    print(minObj)


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for p in range(N)]
        S2 = [input() for p in range(N)]
        solve(N, S1, S2)


main()