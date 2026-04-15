def read_input():
    T = int(input())
    cases = []
    for i in range(T):
        N = int(input())
        S1 = [input().strip() for i in range(N)]
        S2 = [input().strip() for i in range(N)]
        cases.append((N, S1, S2))
    return cases

def solve(cases):
    results = []
    for N, S1, S2 in cases:
        max_vol = 0
        min_vol = 0
        for i in range(N):
            c1 = S1[i].count('#')
            c2 = S2[i].count('#')
            max_vol += c1 * c2
            min_vol += max(c1, c2)
        results.append((max_vol, min_vol))
    return results

def koutput(results):
    for res in results:
        print(res[0], res[1])


if __name__ == '__main__':
    cases = read_input()
    results = solve(cases)
    koutput(results)
