
T = int(input())
for _ in range(T):
    A = input().strip()
    B = input().strip()
        
    A_list = list(A)
    j = 0  # 指向 B 的指针
        
    for i in range(len(A)):
        if j < len(B) and A[i] == B[j]:
            j += 1  # 保留这个字符
        else:
            A_list[i] = '#'  # 替换成 #
        
    print(''.join(A_list))
