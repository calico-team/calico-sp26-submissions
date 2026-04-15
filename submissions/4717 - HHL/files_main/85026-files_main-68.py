import sys

T = sys.stdin.readline()
if T:
    for _ in range(int(T.strip())):
        a = sys.stdin.readline().rstrip('\r\n')
        b = sys.stdin.readline().rstrip('\r\n')
        j, m = 0, len(b)
        for c in a:
            if j < m and c == b[j]:
                sys.stdout.write(c)
                j += 1
            else:
                sys.stdout.write('#')
        sys.stdout.write('\n')