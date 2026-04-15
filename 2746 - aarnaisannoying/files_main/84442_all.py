n = int(input())
for i in range(n):
    string_A  = input()
    string_B = input()
    
    B_ind = 0
    ans = ''
    
    for i in range(len(string_A)):
        if B_ind < len(string_B) and string_A[i] == string_B[B_ind]:
            ans += string_A[i]
            B_ind += 1
        else:
            ans += '#'
            
    print(ans)