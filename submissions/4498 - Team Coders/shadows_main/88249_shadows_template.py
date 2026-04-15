def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol = 0
    for i in range(N):
        count_s1 = S1[i].count('#')
        count_s2 = S2[i].count('#')
        max_vol += count_s1 * count_s2
    
    min_vol = 0
    
    for z in range(N):
        s1_rows = [y for y in range(N) if S1[z][y] == '#']
        s2_cols = [x for x in range(N) if S2[z][x] == '#']
        
        if not s1_rows or not s2_cols:
            continue
        
        uncovered_s1 = set(s1_rows)
        uncovered_s2 = set(s2_cols)
        
        while uncovered_s1 or uncovered_s2:
            best_coverage = 0
            best_pos = None
            
            for y in s1_rows:
                for x in s2_cols:
                    coverage = 0
                    if y in uncovered_s1:
                        coverage += 1
                    if x in uncovered_s2:
                        coverage += 1
                    
                    if coverage > best_coverage:
                        best_coverage = coverage
                        best_pos = (x, y)
            
            if best_pos is None or best_coverage == 0:
                break
            
            min_vol += 1
            x, y = best_pos
            uncovered_s1.discard(y)
            uncovered_s2.discard(x)
    
    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        result = solve(N, S1, S2)
        print(result[0], result[1])


if __name__ == '__main__':
    main()