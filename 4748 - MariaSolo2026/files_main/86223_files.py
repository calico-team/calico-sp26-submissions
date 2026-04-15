def files(A, B):
    result = []          # final string yahan banayenge
    j = 0                # B ke pointer
    
    for char in A:       # A ke har character pe
        if j < len(B) and char == B[j]:
            result.append(char)   # match mila → rakh do
            j += 1
        else:
            result.append('#')    # match nahi → # kar do
    
    return ''.join(result)