inp = input()
T = int(inp)
Ns = []
As = []
for a in range(T * 2):
    inp = input()
    if a % 2 == 1:
        A = inp.split()
        As.append(A)
    else:
        Ns.append(inp)
Bs = []
for b in range(T):
    Bs.append(As[b])
    for i in range(len(Bs[b])):
        if i == 0:
            if int(Bs[b][i]) >= int(Bs[b][i + 1]) + 1 or int(Bs[b][i]) >= int(Bs[b][i + 1]) - 1:
                val = Bs[b][i + 1]
                Bs[b][i] = val
        elif i <= len(Bs[b]) - 2:
            templist = [int(Bs[b][i - 1]), int(Bs[b][i + 1])]
            if int(Bs[b][i]) >= max(templist):
                val = str(max(templist))
                Bs[b][i] = val
            elif int(Bs[b][i]) >= min(templist):
                val = str(min(templist))
                Bs[b][i] = val
        elif i == len(Bs[b]) - 1:
            if int(Bs[b][i]) >= int(Bs[b][i - 1]) + 1 or int(Bs[b][i]) >= int(Bs[b][i - 1]) - 1:
                val = Bs[b][i - 1]
                Bs[b][i] = val
for z in range(T):
    print(" ".join(Bs[z]))
