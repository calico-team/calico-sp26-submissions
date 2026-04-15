t = int(input())

for _ in range(t):
    a = input()
    b = input()

    ans = ""
    b_ptr = 0
    for i in range(len(a)):
        if b_ptr>=len(b):
            ans+='#'
            continue
        if a[i]==b[b_ptr]:
            ans+=a[i]
            b_ptr+=1 
        else:
            ans+='#'
    print(ans)
