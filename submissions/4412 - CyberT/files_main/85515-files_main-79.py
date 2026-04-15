t = int(input())
for _ in range(t):
    source = input().strip()
    helper = input().strip()
    posistion = [] 
    j = 0
    for i in range(len(source)):
        if j < len(helper) and source[i] == helper[j]:
            posistion.append(i)
            j += 1
    ans = []
    n = len(source)
    for i in range(len(posistion)):
        ans.append(source[posistion[i]])
        if i < len(posistion) - 1:
            ans.append('#' * (posistion[i+1] - posistion[i] - 1))
        else:
            ans.append('#' * (n - posistion[i] - 1))
    print("".join(ans))