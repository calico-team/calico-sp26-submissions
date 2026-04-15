n = int(input())

for _ in range(n):
    s1 = input()
    s2 = input()
    no = set()
    s2_idx = 0
    for i in range(len(s1)):
        if s2_idx == len(s2):
            break
        if s1[i] == s2[s2_idx]:
            no.add(i)
            s2_idx += 1
    new_string = []
    for i in range(len(s1)):
        if i not in no:
            new_string.append("#")
        else:
            new_string.append(s1[i])
    print("".join(new_string))