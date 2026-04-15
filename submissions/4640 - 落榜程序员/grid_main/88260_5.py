case_numeber = int(input())
cases = []
for i in range(case_numeber):
    number = int(input())
    user_input = input().split()
    for j in range(len(user_input)):
        user_input[j] = int(user_input[j])
    cases.append(user_input)

for i in range(case_numeber):
    ans  = []
    A_set = cases[i]
    ans.append(A_set[0])
    for j in range(1,len(cases[i])-1):
        left = ans[j-1]
        up = A_set[j]
        up_right = A_set[j+1]
        if left < up_right < up or left > up_right > up:
            ans.append(up_right)
        elif abs(up_right - up) < abs(up_right - left):
            ans.append(up)
        else:
            ans.append(left)
    ans.append(A_set[len(A_set)-1])
    ans_string =  ""
    for j in range(len(ans)):
        ans_string += str(ans[j])+" "
    print(ans_string)