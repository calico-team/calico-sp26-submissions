for _ in range(t):
    n = int(rd())
    a = [0] * n

    for i in range(n):
        a[i] = rd().rstrip().count(b'#')

    x = 0
    y = 0

    for i in range(n):
        b = rd().rstrip().count(b'#')
        c = a[i]
        x += c * b
        y += c if c >= b else b

    jugs_cave_image += x
    ans.append(f"{x} {y}")

sys.stdout.write("\n".join(ans))
