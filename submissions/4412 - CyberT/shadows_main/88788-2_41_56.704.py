def solve():
    n = int(input())
    jugs_cave_image = [input().strip() for _ in range(n)]
    s2 = [input().strip() for _ in range(n)]
    max_vol = 0
    for r in range(n):
        s1_cols = sum(1 for c in range(n) if jugs_cave_image[r][c] == '#')
        s2_deps = sum(1 for d in range(n) if s2[r][d] == '#')
        max_vol += s1_cols * s2_deps
 
    min_vol = 0
    for r in range(n):
        s1_cols = sum(1 for c in range(n) if jugs_cave_image[r][c] == '#')
        s2_deps = sum(1 for d in range(n) if s2[r][d] == '#')
        min_vol += max(s1_cols, s2_deps)
    
    print(max_vol, min_vol)

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()

def read_your_input():
    data = sys.stdin.read().split('\n')
    idx = 0
    t = int(data[idx]); idx += 1
    cases = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        s1 = [data[idx+i] for i in range(n)]; idx += n
        s2 = [data[idx+i] for i in range(n)]; idx += n
        cases.append((n, s1, s2))
    return cases