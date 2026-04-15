import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        n = int(input[idx])
        idx += 1
        s1 = []
        for i in range(n):
            s1.append(input[idx])
            idx += 1
        s2 = []
        for i in range(n):
            s2.append(input[idx])
            idx += 1

        max_total = 0
        min_total = 0
        for i in range(n):
            a = 0
            for c in range(n):
                if s1[i][c] == "#":
                    a += 1
            b = 0
            for c in range(n):
                if s2[i][c] == "#":
                    b += 1
            max_total += a * b
            if a > 0 and b > 0:
                if a > b:
                    min_total += a
                else:
                    min_total += b
        
        #dude failed this

        print(max_total, min_total)

main()