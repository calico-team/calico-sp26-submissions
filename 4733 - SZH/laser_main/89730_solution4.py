inp = input()
T = int(inp)
Ks = []
Ns = []
Ms = []
Ps = []
Qs = []
XYcoords = []
for a in range(T):
    inp = input()
    splitted = inp.split()
    Ks.append(int(splitted[0]))
    Ns.append(int(splitted[1]))
    Ms.append(int(splitted[2]))
    Ps.append(int(splitted[3]))
    Qs.append(int(splitted[4]))
    XYcoord = []
    for b in range(Ks[a]):
        inp = input()
        splatted = inp.split()
        XYcoord.append(splatted)
    XYcoords.append(XYcoord)
results = []
for c in range(T):
    Zs = []
    Js = []
    for j in range(len(XYcoords[c])):
        z = 0
        y = 0
        if j == 0:
            reallocation = [(Qs[c] + 1), (Ps[c] + 1)]
        else:
            reallocation = [(int(XYcoords[c][j][0]) - int(XYcoords[c][1][0]) + z * Ns[c]), (int(XYcoords[c][j][1]) - int(XYcoords[c][1][1]) + y * Ms[c])]
        def function(x):
            if x == 0:
                if reallocation[x] != Qs[c] * z:
                    return True
                else:
                    return False
            elif x == 1:
                if reallocation[x] != Ps[c] * y:
                    return True
                else:
                    return False
        def determine(x):
            if x == 0:
                if reallocation[x] <= Qs[c] * z:
                    return True
                else:
                    return False
            elif x == 1:
                if reallocation[x] <= Ps[c] * y:
                    return True
                else:
                    return False
        def both():
            if function(0) or function(1):
                return True
            else:
                return False
        while both():
            if determine(1):
                y += 1
                reallocation = [(int(XYcoords[c][j][0]) - int(XYcoords[c][1][0]) + z * Ns[c]), (int(XYcoords[c][j][1]) - int(XYcoords[c][1][1]) + y * Ms[c])]
            elif not determine(1):
                y -= 1
                reallocation = [(int(XYcoords[c][j][0]) - int(XYcoords[c][1][0]) + z * Ns[c]), (int(XYcoords[c][j][1]) - int(XYcoords[c][1][1]) + y * Ms[c])]
            if determine(0):    
                z += 1
                reallocation = [(int(XYcoords[c][j][0]) - int(XYcoords[c][1][0]) + z * Ns[c]), (int(XYcoords[c][j][1]) - int(XYcoords[c][1][1]) + y * Ms[c])]
            elif not determine(0):
                z -= 1
                reallocation = [(int(XYcoords[c][j][0]) - int(XYcoords[c][1][0]) + z * Ns[c]), (int(XYcoords[c][j][1]) - int(XYcoords[c][1][1]) + y * Ms[c])]

        Zs.append(z)
        Js.append(j)
    ind = Zs.index(max(Zs))
    results.append(Js[ind])
for z in range(T):
    print(results[z])
            
