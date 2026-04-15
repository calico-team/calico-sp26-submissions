for _ in range(t):
    n = int(next(it))
    a = [next(it).count(b'#') for _ in range(n)]
    mx = 0
    mn = 0

    for i in range(n):
        b = next(it).count(b'#')
        c = a[i]
        mx += c * b
        mn += c if c >= b else b

    jugs_cave_image += mx
    out.append(f"{mx} {mn}")

sys.stdout.write("\n".join(out))
