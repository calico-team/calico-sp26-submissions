import sys
from heapq import *
input = sys.stdin.readline

def solve():
    X, C, K =map(int, input().split())
    grid = []
    for _ in range(X):
        grid.append(input().strip())
    
    DIRS= [(-1,0),(1,0),(0,-1),(0,1)]
    
    empty_cells = []
    Y = {}
    for r in range(X):
        for c in range(C):
            if grid[r][c] == '-':
                w = 0
                for dr, dc in DIRS:
                    nr, nc = r+dr, c+dc
                    if nr < 0 or nr >= X or nc < 0 or nc >= C:
                        w -= 1
                    elif grid[nr][nc] == '#':
                        w -= 1
                empty_cells.append((r, c))
                Y[(r, c)] = w
    
    N = len(empty_cells)

    adj = {}
    for r, c in empty_cells:
        neighbors = []
        for dr, dc in DIRS:
            nr, nc = r+dr, c+dc
            if 0 <= nr < X and 0 <= nc < C and grid[nr][nc] == '-':
                neighbors.append((nr, nc))
        adj[(r, c)] = neighbors

    def greedy_from(start_idx):
        chosen = []
        in_chosen= set()
        tot_aura = 0

        sc = empty_cells[start_idx]
        chosen.append(sc)
        in_chosen.add(sc)
        tot_aura += Y[sc]

        friend_count = {}
        for cell in empty_cells:
            friend_count[cell] = 0

        for nb in adj[sc]:
            friend_count[nb] += 1
        
        for _ in range(K - 1):
            best_cell = None
            best_gain = -float('inf')
            for cell in empty_cells:
                if cell not in in_chosen:
                    gain = Y[cell] + 2 * friend_count[cell]
                    if gain > best_gain or (gain == best_gain and cell < best_cell):
                        best_gain = gain
                        best_cell = cell
            
            if best_cell is None:
                break
            
            chosen.append(best_cell)
            in_chosen.add(best_cell)
            tot_aura += best_gain

            for nb in adj[best_cell]:
                if nb not in in_chosen:
                    friend_count[nb] +=1
        
        return tot_aura, chosen

    best_aura= -float('inf')
    best_chosen = None

    if N <=200 or K <= 10:
        candidates = range(N)
    else:

        sort_indices =sorted(range(N), key=lambda i: Y[empty_cells[i]], reverse=True)
        candidates = sort_indices[:min(N, 50)]
    
    for start_idx in candidates:
        aura, chosen= greedy_from(start_idx)
        if aura > best_aura:
            best_aura= aura
            best_chosen =chosen

    for r, c in best_chosen:
        print(r, c)

def main():
    T =int(input())
    for _ in range(T):
        solve()

main()
