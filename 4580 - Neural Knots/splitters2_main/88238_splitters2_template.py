import sys
from fractions import Fraction

def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    steps = [2] * A + [3] * B
    L = len(steps)
    
    R = 2 * L + 2
    C = 5
    grid = [['.' for _ in range(C)] for _ in range(R)]
    
    grid[0][0] = '>'
    grid[0][1] = '>'
    grid[0][2] = 'v'
    grid[1][2] = 'v'
    
    trgt = Fraction(P, (2**A) * (3**B))
    
    for i, k in enumerate(steps):
        r = 2 + 2 * i  
        grid[r][2] = 'S'
        
        if i == L - 1:
            grid[r+1][2] = 'X'
        else:
            grid[r+1][2] = 'v'
            
        val = trgt * k
        d = val.numerator // val.denominator  
        trgt = val - d                      

        grid[r][1] = '<'
        if d >= 1:
            grid[r][0] = '<'  
        else:
            grid[r][0] = 'X'  

        if k == 3:
            grid[r][3] = '>'
            if d >= 2:
                grid[r][4] = '>' 
            else:
                grid[r][4] = 'X' 
        else: 
            grid[r][3] = '<'
            grid[r][4] = '.'
            
    return [''.join(row) for row in grid]


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()