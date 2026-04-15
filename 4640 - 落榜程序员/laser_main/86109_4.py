case_number = int(input())
cases = []

for i in range(case_number):
    cases.append([])
    KNMPQ = input()
    info = KNMPQ.split(" ")
    cases[i].append(int(info[1]))#N
    cases[i].append(int(info[2]))#M
    cases[i].append(int(info[4]))#Q
    cases[i].append(int(info[3]))#P
    #NMQP
    cases[i].append([])
    for j in range(int(info[0])):
        coordinate = input().split(" ")
        coordinate[0] = int(coordinate[0])
        coordinate[1] = int(coordinate[1])
        cases[i][4].append(coordinate)
# print(cases)
for i in range(case_number):
    N = cases[i][0]#X轴边界
    M = cases[i][1]#Y轴边界
    P = cases[i][2]#X轴移动
    Q = cases[i][3]#Y轴移动
    original = cases[i][4][0].copy()
    # print(original)
    now = original.copy()
    found = False
    first = True
    while not found:
        now[0] = (now[0] + P)%N
        now[1] = (now[1] + Q)%M
        for  j in range(1,len(cases[i][4])):
            if now == cases[i][4][j]:
                ans = j
                found = True
                break


        # print("now",now)
        # print("original",original)
        if now == original and not first:
            ans = 0
            found = True
        first = False
    print(ans)







