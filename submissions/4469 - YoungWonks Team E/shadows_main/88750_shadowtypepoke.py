import sys

def main():
    data = sys.stdin.read().splitlines()
    idx = 0
    t = int(data[idx].strip())
    idx += 1

    for tc in range(t):
        n = int(data[idx].strip())
        idx += 1
        s1 = []
        for i in range(n):
            s1.append(data[idx])
            idx += 1
        s2 = []
        for i in range(n):
            s2.append(data[idx])
            idx += 1

        max_total = 0
        min_total = 0
        for i in range(n):
            a = 0
            row1 = s1[i]
            for ch in row1:
                if ch == "#":
                    a += 1
            b = 0
            row2 = s2[i]
            for ch in row2:
                if ch == "#":
                    b += 1
            max_total += a * b
            if a > 0 and b > 0:
                if a > b:
                    min_total += a
                else:
                    min_total += b

        #i failed this

        print(max_total, min_total)

main()