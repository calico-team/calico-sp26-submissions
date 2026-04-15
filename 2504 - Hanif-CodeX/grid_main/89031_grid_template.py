import sys

def solve(N, A):
    """
    Finds a constant value (the median) to fill row B.
    This minimizes the sum of vertical differences while 
    keeping bottom-row horizontal differences at zero.
    """
    # Sort the array to find the median
    sa = sorted(A)
    # Use the middle element as the constant value for the whole row
    mv = sa[N // 2]
    
    return [mv] * N

def main():
    id = sys.stdin.read().split()
    if not id:
        return
    
    ptr = 0
    T = int(id[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(id[ptr])
        ptr += 1
        A = []
        for _ in range(N):
            A.append(int(id[ptr]))
            ptr += 1
            
        result = solve(N, A)
        print(*(result))

if __name__ == '__main__':
    main()