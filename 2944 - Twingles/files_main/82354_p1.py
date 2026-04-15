t = int(input())

for _ in range(t):
    a,b = input(),input()
    j = 0
    ans = ''
    for i in a:
        if j < len(b) and i == b[j]:
            ans+=i
            j+=1
        else:
            ans+='#'
    print(ans)