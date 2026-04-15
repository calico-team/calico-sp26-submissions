t = eval(input())
for i in range(t):
    
    inputList = input().split()
    l, w, e, r = int(inputList[0]), int(inputList[1]), int(inputList[2]), int(inputList[3])
    laps = e // (2 * (l + w) * r)  + e % (2 * (l + w) * r)
    print(laps)
    
