cases = []
case_number = int(input())
for i in range(case_number):
    cases.append([])
    cases[i].append(input())
    cases[i].append(input())
# print(cases)
for i in range(len(cases)):
    original = cases[i][0]
    target = []
    final = ""
    for j in range(len(cases[i][1])):
        target.append(cases[i][1][j])
    # print(target)
    next = 0
    for j in range(len(original)):
        # print(next)
        if next != len(target):
            if original[j] == target[next]:
                next = next + 1
                final = final + original[j]
            else:
                final = final + "#"
        else:
            final = final + "#"
    print(final)





