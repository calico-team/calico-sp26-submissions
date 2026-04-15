def solve():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        rslt = []
        b_indx = 0
        for i in A:
            if b_indx < len(B) and i == B[b_indx]:
                rslt.append(i)
                b_indx += 1
            else:
                rslt.append('#')
        print(''.join(rslt))
if __name__ == "__main__":
    solve()