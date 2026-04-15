n = int(input())

for i in range(n):
    N,P,R,K = map(int, input().split(" "))
    power_level = P
    ok = True
    list1 = [int(i) for i in input().split(" ")]
    for j in range(N):
        if power_level >= list1[j]:
            power_level -= list1[j]
            if (j+1) % K == 0:
                power_level += R
        else:
            ok = False
            break
    if ok and power_level >= 0:
        print("nah i’d win")
    else:
        print("nah i’d lose")
    
