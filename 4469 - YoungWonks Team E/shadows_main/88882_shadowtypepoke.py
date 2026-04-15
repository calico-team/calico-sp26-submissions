import sys

def main():
    data = sys.stdin.read().splitlines()
    lines = []
    for ln in data:
        stripped = ln.strip()
        if stripped != '':
            lines.append(stripped)

    idx = 0
    t = int(lines[idx])
    idx += 1

    for tc in range(t):
        n = int(lines[idx])
        idx += 1
        s1 = []
        for i in range(n):
            s1.append(lines[idx])
            idx += 1
        s2 = []
        for i in range(n):
            s2.append(lines[idx])
            idx += 1

        max_total = 0
        min_total = 0
        for i in range(n):
            a = 0
            for ch in s1[i]:
                if ch == '#':
                    a += 1
            b = 0
            for ch in s2[i]:
                if ch == '#':
                    b += 1
            max_total += a * b
            if a > 0 and b > 0:
                if a > b:
                    min_total += a
                else:
                    min_total += b

        #i failed this
        #irihribnrnfweq;ndn

        print(max_total, min_total)

main()