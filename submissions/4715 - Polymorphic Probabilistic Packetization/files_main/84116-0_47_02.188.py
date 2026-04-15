T = int(input())

for _ in range(T):
    A = input().strip()
    B = input().strip()
    b_index = 0
    ans = "" 
    for c in A:
        if b_index < len(B) and c == B[b_index]:
            ans += c
            b_index += 1
        else:
            ans += "#"
    print(ans)