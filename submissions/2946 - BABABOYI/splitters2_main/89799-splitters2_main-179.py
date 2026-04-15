import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    for _ in range(T):
        P = int(input_data[idx])
        A = int(input_data[idx+1])
        B = int(input_data[idx+2])
        idx += 3
        
        D = [2] * A + [3] * B
        
        C = []
        curr_P = P
        for d in reversed(D):
            C.append(curr_P % d)
            curr_P = curr_P // d
        C.reverse()
        
        grid = [">>v.."]
        
        for i in range(len(D)):
            d = D[i]
            c = C[i]
            
            grid.append("..v..")
            
            if d == 2:
                if c == 0:
                    grid.append("..SX.")
                else:
                    grid.append("..S>>")
            else:
                if c == 0:
                    grid.append(".XSX.")
                elif c == 1:
                    grid.append(".XS>>")
                else:
                    grid.append("<<S>>")
                    
        grid.append("..X..")
        
        print(f"{len(grid)} 5")
        for row in grid:
            print(row)

if __name__ == '__main__':
    solve()