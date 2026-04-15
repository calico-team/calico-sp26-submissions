def solve():
    T = int(input())
    out = []
    for _ in range(T):
        A = input()
        B = input()
        res = []
        b_id = 0
        for char in A:
            if b_id < len(B) and char == B[b_id]:
                res.append(char)
                while b_id + 1 < len(B) and B[b_id + 1] == char:
                    b_id += 1
                b_id += 1
            else:
                res.append('#')
        out.append("".join(res))
    for line in out:
        print(line)

def read_your_input():
    solve()

if __name__ == '__main__':
    read_your_input()
