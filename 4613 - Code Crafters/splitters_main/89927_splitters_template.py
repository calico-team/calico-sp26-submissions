def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    memo = {}
    dirs = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}

    def get_prob(r, c):
        if r < 0 or r >= N or c < 0 or c >= M:
            return (1, 1) 
        if (r, c) in memo:
            return memo[(r, c)]
        
        tile = factory[r][c]
        if tile == 'X' or tile == '.':
            return (0, 1)
        
        if tile in dirs:
            dr, dc = dirs[tile]
            res = get_prob(r + dr, c + dc)
        elif tile == 'S':
            valid = []
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    ntile = factory[nr][nc]
                    if ntile == 'X':
                        valid.append((nr, nc))
                    elif ntile in dirs:
                        ndr, ndc = dirs[ntile]
                        if nr + ndr != r or nc + ndc != c:
                            valid.append((nr, nc))
            
            p_sum, q_sum = 0, 1
            num = len(valid)
            for nr, nc in valid:
                p, q = get_prob(nr, nc)
                q_new = q_sum * q * num
                p_new = p_sum * q * num + p * q_sum
                common = math.gcd(p_new, q_new)
                p_sum, q_sum = p_new // common, q_new // common
            res = (p_sum, q_sum)
        else:
            res = (0, 1)
            
        memo[(r, c)] = res
        return res

    return get_prob(0, 0)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
