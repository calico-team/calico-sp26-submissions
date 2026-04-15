def auratables():
    A = input().split(" ")
    B = []
    holder = []
    MDistance = []
    auraloss = []
    for i in range(int(A[0])):
        C = list(input())
        B.append(C)
    for i in range(len(B)):
        for j in range(len(B[0])):
            if B[i][j] == "-":
                temp = [i, j]
                holder.append(temp)
    for i in range(len(holder)):
        for j in range(len(holder) - 1):
            MDistance.append(distance(holder[i][1], holder[i][0], holder[j][1], holder[j][0]))
    for i in range(len(holder)):
        auraloss.append((auralosscalc(B[holder[i][0]], holder[i][1])))


def distance(x1, y1, x2, y2):
    xdif = abs(x2 - x1)
    ydif = abs(y2 - y1)
    manhattan = xdif + ydif
    return manhattan


def auralosscalc(row, pos):
    counter = 0
    for i in range(0, pos):
        if row[i] == "#":
            counter += 1
    lloss = counter
    counter = 0
    for i in range(pos, len(row)):
        if row[i] == "#":
            counter += 1
    rloss = counter
    return lloss, rloss


cases = int(input())
for i in range(cases):
    auratables()
