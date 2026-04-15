
def nahid():

    tester = input().split(" ")

    N = int(tester[0])
    P = int(tester[1])
    R = int(tester[2])
    K = int(tester[3])

    E = input().split(" ")
    counter = 0
    healcounter = K

    for counter in range(N):
        if healcounter == 0:
            P = P+R
            P -= int(E[counter])
            counter += 1
            healcounter = K
            healcounter -= 1
        else:
            P -= int(E[counter])
            counter += 1
            healcounter -= 1

    if P < 0:
        print("nah i'd lose")
    else:
        print("nah i'd win")


cases = int(input())
for i in range(cases):
    nahid()