import sys

def main():
    input = sys.stdin.read().splitlines()
    t = int(input[0])
    ptr = 1
    for _ in range(t):
        A = input[ptr].strip()
        B = input[ptr+1].strip()
        ptr += 2
        res = []
        j = 0
        lenB = len(B)
        for c in A:
            if j < lenB and c == B[j]:
                res.append(c)
                j += 1
            else:
                res.append('#')
        print(''.join(res))

if __name__ == "__main__":
    main()
