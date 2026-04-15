import sys

def sol(nm, arr):
    if nm == 1:
        return [arr[0]]

    if nm == 2:
        return [arr[0], arr[1]]

    cands = {
        arr[0], arr[1], arr[2],
        min(arr[0], arr[1]), max(arr[0], arr[1]),
        min(arr[1], arr[2]), max(arr[1], arr[2]),
        min(arr[0], arr[2]), max(arr[0], arr[2]),
    }

    bst = None
    res = None

    for mid in cands:
        lft = mid
        if lft < min(arr[0], mid):
            lft = min(arr[0], mid)
        if lft > max(arr[0], mid):
            lft = max(arr[0], mid)

        rgt = mid
        if rgt < min(arr[2], mid):
            rgt = min(arr[2], mid)
        if rgt > max(arr[2], mid):
            rgt = max(arr[2], mid)

        cost = (
            abs(lft - mid)
            + abs(mid - rgt)
            + abs(arr[0] - lft)
            + abs(arr[1] - mid)
            + abs(arr[2] - rgt)
        )

        if bst is None or cost < bst:
            bst = cost
            res = [lft, mid, rgt]

    return res

def main():
    data = sys.stdin.buffer.read().split()
    tcs = int(data[0])
    idx = 1
    out = []

    for _ in range(tcs):
        nm = int(data[idx])
        idx += 1
        arr = list(map(int, data[idx:idx + nm]))
        idx += nm
        ans = sol(nm, arr)
        out.append(" ".join(map(str, ans)))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()