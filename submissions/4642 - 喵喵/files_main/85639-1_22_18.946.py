def nahid():
    tester = input().split(" ")
    N = int(tester[0])
    P = int(tester[1])
    R = int(tester[2])
    K = int(tester[3])
    E = input().split(" ")
    for counter in range(N):
        if counter == K-1:
            P = P+R
            P -= int(E[counter])
        else:
            P -= int(E[counter])
    if P < 0:
        return "nah i'd lose"
    else:
        return "nah i'd win"


cases = int(input())
for i in range(cases):
    print(nahid())
