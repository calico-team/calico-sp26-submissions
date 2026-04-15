def censor_this_please(A, B):
    res = []
    b_idx = 0
    for char in A:
        if b_idx < len(B) and char == B[b_idx]:
            res.append(char)
            b_idx += 1
        else:
            res.append('#')
    return "".join(res)

def read_your_input():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    current = 1
    for _ in range(T):
        A = input_data[current]
        B = input_data[current + 1]
        print(censor_this_please(A, B))
        current += 2

if __name__ == "__main__":
    read_your_input()