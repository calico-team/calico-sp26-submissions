inps = []
inp = input()
T = int(inp)
Ls = []
Ws = []
Es = []
Rs = []
for a in range(T):
    inp = input()
    splitted = inp.split()
    Ls.append(int(splitted[0]))
    Ws.append(int(splitted[1]))
    Es.append(int(splitted[2]))
    Rs.append(int(splitted[3]))
results = []
for b in range(T):
    eperlap = (Ls[b] + Ws[b]) * 2 * Rs[b]
    results.append(Es[b] // eperlap)
for z in range(T):
    print(results[z])
