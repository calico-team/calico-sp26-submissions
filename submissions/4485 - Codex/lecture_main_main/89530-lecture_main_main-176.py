def solve(N, M, K, GRID):
    empty_seats = []
    for row in range(N):
        for col in range(M):
            if GRID[row][col] == '-':
                empty_seats.append((row, col))
    
    cost_map = {}
    for r in range(N):
        left_blocks= 0
        for c in range(M):
            if GRID[r][c] == '#':
                left_blocks += 1
            else:
                cost_map[(r, c)] = left_blocks
        
        right_blocks = 0
        for c in range(M - 1, -1, -1):
            if GRID[r][c] == '#':
                right_blocks += 1
            else:
                cost_map[(r, c)] = min(cost_map[(r, c)], right_blocks)
    
    def check(d):
        best_group = None
        min_aura = float('inf')
        
        for i in range(len(empty_seats)):
            selected = [empty_seats[i]]
            for j in range(len(empty_seats)):
                if i == j:
                    continue
                ok = True
                for (row1, col1) in selected:
                    row2, col2 = empty_seats[j]
                    if abs(row1 - row2) + abs(col1 - col2) > d:
                        ok = False
                        break
                if ok:
                    selected.append(empty_seats[j])
                if len(selected) == K:
                    break
            
            if len(selected) == K:
                sum_aura = sum(cost_map[cell] for cell in selected)
                if sum_aura < min_aura:
                    min_aura = sum_aura
                    best_group = selected
        
        return best_group
    
    left, right = 0, N + M
    final_answer = None
    
    while left <= right:
        mid = (left + right) // 2
        temp = check(mid)
        if temp is not None:
            final_answer = temp
            right = mid - 1
        else:
            left = mid + 1
    
    return final_answer


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        
        temp = solve(N, M, K, GRID)
        for r, c in temp:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()



def read_your_input():
    import sys
    return sys.stdin.read()