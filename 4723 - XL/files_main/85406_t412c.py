def main():
    import sys
    input = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for t in range(T):
        A = input[ptr]
        ptr += 1
        B = input[ptr]
        ptr += 1
        res = ""
        j = 0
        for i in range(len(A)):
            if j < len(B) and A[i] == B[j]:
                res += A[i]
                j += 1
            else:
                res += "#"
        print(res)
main()