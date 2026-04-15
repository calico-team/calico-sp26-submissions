T = int(input())
for _ in range(T):
    A = input().strip()
    B = input().strip()
    result = []
    b_idx = 0
    len_b = len(B)

    for char in A:
        if b_idx < len_b and char == B[b_idx]:
            result.append(char)
            b_idx += 1
        else:
            result.append("#")
    print("".join(result))

