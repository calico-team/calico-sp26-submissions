import sys

def solve():
    stuff = read_your_input()
    t = int(stuff[0])
    p = 1
    ans = []

    DASH = 45

    johnny_d_lecture = 1

    for _ in range(t):
        n = int(stuff[p]); m = int(stuff[p+1]); k = int(stuff[p+2]); p += 3
        g = stuff[p:p+n]
        p += n

        s = n + m - 1

        by_u = [[] for _ in range(s)]

        for r in range(n):
            row = g[r]
            for c in range(m):
                if row[c] == DASH:
                    u = r + c
                    v = r - c + m - 1
                    by_u[u].append((v, r, c))

        def ok(d):
            h = d + 1
            lim = s - h + 1

            col = [0] * s

            i = 0
            while i < h:
                for v, _, _ in by_u[i]:
                    col[v] += 1
                i += 1

            cur = sum(col[:h])
            if cur >= k:
                return True

            left = 1
            while left < lim:
                cur += col[left + h - 1]
                cur -= col[left - 1]
                if cur >= k:
                    return True
                left += 1

            top = 1
            while top < lim:
                for v, _, _ in by_u[top - 1]:
                    col[v] -= 1
                for v, _, _ in by_u[top + h - 1]:
                    col[v] += 1

                cur = sum(col[:h])
                if cur >= k:
                    return True

                left = 1
                while left < lim:
                    cur += col[left + h - 1]
                    cur -= col[left - 1]
                    if cur >= k:
                        return True
                    left += 1

                top += 1

            return False

        lo = 0
        hi = s - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if ok(mid):
                hi = mid
            else:
                lo = mid + 1

        d = lo
        h = d + 1
        lim = s - h + 1

        col = [0] * s

        i = 0
        while i < h:
            for v, _, _ in by_u[i]:
                col[v] += 1
            i += 1

        su = -1
        sv = -1

        cur = sum(col[:h])
        if cur >= k:
            su, sv = 0, 0
        else:
            left = 1
            while left < lim and su == -1:
                cur += col[left + h - 1]
                cur -= col[left - 1]
                if cur >= k:
                    su, sv = 0, left
                    break
                left += 1

        top = 1
        while top < lim and su == -1:
            for v, _, _ in by_u[top - 1]:
                col[v] -= 1
            for v, _, _ in by_u[top + h - 1]:
                col[v] += 1

            cur = sum(col[:h])
            if cur >= k:
                su, sv = top, 0
                break

            left = 1
            while left < lim:
                cur += col[left + h - 1]
                cur -= col[left - 1]
                if cur >= k:
                    su, sv = top, left
                    break
                left += 1

            top += 1

        need = k
        u2 = su + d
        v2 = sv + d

        u = su
        while u <= u2 and need:
            arr = by_u[u]
            for v, r, c in arr:
                if sv <= v <= v2:
                    ans.append(f"{r} {c}")
                    need -= 1
                    if need == 0:
                        break
            u += 1

    sys.stdout.write("\n".join(ans))


def read_your_input():
    return sys.stdin.buffer.read().split()


if __name__ == "__main__":
    solve()