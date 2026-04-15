def main():
    times = int(input())
    # times = 1
    finalarray = []
    for i in range(times):
        finalarray.append(program())
    for i in finalarray:
        print(i)
def program():

    # UNCOMMENT LATER
    linespershadow = int(input())
    shadow1 = []
    shadow2 = []
    for i in range(linespershadow):
        shadow1.append(list(input()))
        
    for i in range(linespershadow):
        shadow2.append(list(input()))

    # TEST
    # linespershadow = 3
    # shadow1 = [
    #     ["#", "*", "#"],
    #     ["#", "*", "#"],
    #     ["#", "#", "#"]
    # ]
    # shadow2 = [
    #     ["#", "#", "#"],
    #     ["#", "*", "#"],
    #     ["#", "*", "#"]
    # ]

    # TEST 2
    # linespershadow = 2
    # shadow1 = [
    #     ["#", "#"],
    #     ["#", "#"]
    # ]
    # shadow2 = [
    #     ["#", "#"],
    #     ["#", "#"]
    # ]

    # TEST 3
    # linespershadow = 2
    # shadow1 = [
    #     [".", "."],
    #     [".", "."]
    # ]
    # shadow2 = [
    #     [".", "."],
    #     [".", "."]
    # ]

    # TEST 4
    # linespershadow = 4
    # shadow1 = [
    #     ["#", ".", ".", "."],
    #     [".", ".", "#", "#"],
    #     ["#", "#", ".", "#"],
    #     ["#", "#", ".", "."]
    # ]
    # shadow2 = [
    #     [".", ".", "#", "#"],
    #     [".", ".", "#", "#"],
    #     ["#", "#", ".", "#"],
    #     ["#", ".", "#", "#"]
    # ]
    
    # max is 1 shadow length of cube, min is assuming 1 brick per shadow
    # print("shadow1:" +str(shadow1))
    # print("shadow2:" +str(shadow2))
    min = 0
    for y in range(len(shadow1)):
        for z in range(len(shadow1[y])):
            # print("comparing at "+str(y)+","+str(z))
            # print("shadow1: " + shadow1[y][z] + " opposite shadow2: " + shadow2[y][-z-1])
            if shadow1[y][z] == shadow2[y][-z-1] and shadow1[y][z] == "#":
                min+=1
                print("used same")
            elif shadow1[y][z]=="#" and shadow2[y][-z-1]=="." or shadow1[y][z]=="." and shadow2[y][-z-1]=="#":
                min+=1
                print("used different")
            # if shadow1[y][z] != "*" and shadow2[y][-z-1] != "*":
            #     min+=1
    # print(min)
    max = 0
    for y in range(len(shadow1)):
        for z in range(len(shadow1[y])):
            currentBlock1 = shadow1[y][-z-1]
            if currentBlock1 == "#":
                numholes2 = 0
                for block in shadow2[y]:
                    if block == ".":
                        numholes2 += 1
                # print("adding "+str(len(shadow1[0]) - numholes2)+" numholes: "+str(numholes2))
                max += len(shadow1[0]) - numholes2
            # elif shadow2[y][z] == "#":
            #     numholes2 = 0
            #     for block in shadow2[y]:
            #         if block == "*":
            #             numholes2 += 1
            #     max += len(shadow1[0]) - numholes2

    # print(max)
    # finalarray.append(""+str(max)+" "+str(min))
    # return finalarray
    return str(max)+" "+str(min)
    
main()