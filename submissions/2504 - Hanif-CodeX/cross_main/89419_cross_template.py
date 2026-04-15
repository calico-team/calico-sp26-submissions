def solve(N, M):
    """
    Create an N x M G such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the G
    M: number of columns in the G
    """
    G = []
    for r in range(N):
        rw = []
        for c in range(M):
            # Applying the periodic formula (2*r + c) % 5
            rw.append((2 * r + c) % 5)
        G.append(rw)
    return G

def main():
    import sys
    # Using sys.stdin for faster input reading with large constraints (up to 1000x1000)
    id = sys.stdin.read().split()
    if not id:
        return
    
    T = int(id[0])
    ptr = 1
    for _ in range(T):
        N = int(id[ptr])
        M = int(id[ptr+1])
        ptr += 2
        
        G = solve(N, M)
        for rw in G:
            print(*(rw))

if __name__ == '__main__':
    main()