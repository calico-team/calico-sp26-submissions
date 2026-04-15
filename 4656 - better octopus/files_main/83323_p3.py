for _ in range(int(input())):
    a=input()
    b=input()+"#"
    bl=len(b)
    bi=0
    ans=''
    for c in a:
        if c==b[bi]:
            bi+=1
            ans+=c
        else:
            ans+='#'
    print(ans)
