import sys
input = sys.stdin.readline

def solve(Z, A, B):
    
    ops = []
    cur_A, cur_B, cur_Z = A, B, Z

    while cur_A > 0 or cur_B > 0:
        if cur_A >0:
            half =(2 ** (cur_A - 1)) *(3 ** cur_B)
            if cur_Z >= half:
                ops.append('halve_collect')
                cur_Z -= half
            else:
                ops.append('halve_destroy')
            cur_A -=1
        else:
            third= 3 ** (cur_B - 1)
            if cur_Z >= 2 * third:
                ops.append('third_collect2')
                cur_Z -= 2 * third
            elif cur_Z >= third:
                ops.append('third_collect1_destroy1')
                cur_Z -=third
            else:
                ops.append('third_destroy2')
            cur_B -= 1

    n = len(ops) 
    C,D = 3, 2 * n + 1

    grid = [['.' for _ in range(D)] for _ in range(C)]
    grid[0][0] = 'v'
    grid[1][0] = '>'

    for k, op in enumerate(ops):
        c = 2 * k +1        
        rt= 'X' if k == n - 1 else '>'  

        grid[1][c] = 'S'
        grid[1][c + 1] = rt

        if op == 'halve_collect':
            grid[0][c] = '^'   
            grid[2][c] = '^'  
        elif op == 'halve_destroy':
            grid[0][c] = 'v'   
            grid[2][c] = 'X'  
        elif op == 'third_collect2':
            grid[0][c] = '^'   
            grid[2][c] = 'v'  
        elif op == 'third_collect1_destroy1':
            grid[0][c] = '^'  
            grid[2][c] = 'X' 
        elif op == 'third_destroy2':
            grid[0][c] = 'X'  
            grid[2][c] = 'X' 

    print(C,D)
    for row in grid:
        print(''.join(row))

def main():
    T = int(input())
    for _ in range(T):
        Z, A, B = map(int, input().split())
        solve(Z, A, B)

main()