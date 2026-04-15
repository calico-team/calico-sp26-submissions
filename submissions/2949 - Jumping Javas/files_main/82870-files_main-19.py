for _ in range(int(input())):
    A = input()
    B = input()
    
    C=""
    
    BCharIndex = 0
    for sourceChar in A:
        if BCharIndex >= len(B):
            break
        
        if (sourceChar == B[BCharIndex]):
            C += sourceChar
            BCharIndex = BCharIndex + 1
        else:
            C += "#"
    
    while len(C)<len(A):
        C += "#"
    
    print(C)