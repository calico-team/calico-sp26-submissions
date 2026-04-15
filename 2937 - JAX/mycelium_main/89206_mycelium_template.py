def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    x_g = X_G
    y_g = Y_G
    y_m = Y_M
    x_m = X_M
    if abs(x_g+y_g)>=12 or abs(x_m+y_m)>=12:
        gridsize = 60
        halfsize = 30
        ticks = 450
    elif abs(x_g+y_g)>=10 or abs(x_m+y_m)>=10:
        gridsize = 50
        halfsize = 25
        ticks = 200
    elif abs(x_g+y_g)>=8 or abs(x_m+y_m)>=8:
        gridsize = 40
        halfsize = 20
        ticks = 100
    elif abs(x_g+y_g)>=6 or abs(x_m+y_m)>=6:
        gridsize = 30
        halfsize = 15
        ticks = 50
    elif abs(x_g+y_g)>=4 or abs(x_m+y_m)>=4:
        gridsize = 20
        halfsize = 10
        ticks = 40
    else:
        gridsize = 10
        halfsize = 5
        ticks = 30
        
    grid = []
    for i in range(gridsize+1):
        row = []
        for j in range(gridsize+1):
            row.append(0)
        grid.append(row)
    grid[halfsize-y_g][halfsize+x_g]=1
    grid[halfsize-y_m][halfsize+x_m]=2
    #print(grid)
    #print(t+1)
    #for k in range(401):
      #  print(grid[k])
    

    #spreading simulation
    for i in range(1,ticks): #probably enough ticks
        if i%14==0: #tiles neighbording both grass and mycelium turn into grass
            g_converts = set()
            m_converts = set()
            for row in range(gridsize+1):
                for col in range(gridsize+1):
                    if grid[row][col]==0:
                        if row==0:
                            if col==0:
                                #top left corner
                                if grid[row+1][col]==1 or grid[row][col+1]==1:
                                    g_converts.add((row,col))
                                elif grid[row+1][col]==2 or grid[row][col+1]==2:
                                    m_converts.add((row,col))
                                    
                            elif col==gridsize:
                                #top right corner
                                if grid[row+1][col]==1 or grid[row][col-1]==1:
                                    g_converts.add((row,col))
                                elif grid[row+1][col]==2 or grid[row][col-1]==2:
                                    m_converts.add((row,col))
                                    
                            else:
                                #top row; not in corner
                                if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row][col-1]==1:
                                    g_converts.add((row,col))
                                elif grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row][col-1]==2:
                                    m_converts.add((row,col))
                                    
                        elif row==gridsize:
                            if col==0:
                                #bottom left corner
                                if grid[row-1][col]==1 or grid[row][col+1]==1:
                                    g_converts.add((row,col))
                                elif grid[row-1][col]==2 or grid[row][col+1]==2:
                                    m_converts.add((row,col))
                                    
                            elif col==gridsize:
                                #bottom right corner
                                if grid[row-1][col]==1 or grid[row][col-1]==1:
                                    g_converts.add((row,col))
                                elif grid[row-1][col]==2 or grid[row][col-1]==2:
                                    m_converts.add((row,col))
                                    
                            else:
                                #bottom row; not in corner
                                if grid[row][col-1]==1 or grid[row][col+1]==1 or grid[row-1][col]==1:
                                    g_converts.add((row,col))
                                elif grid[row][col-1]==2 or grid[row][col+1]==2 or grid[row-1][col]==2:
                                    m_converts.add((row,col))
                                    
                        elif col==0:
                            #left col; not in corner
                            if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row-1][col]==1:
                                g_converts.add((row,col))
                            if grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row-1][col]==2:
                                m_converts.add((row,col))
                                    
                        elif col==gridsize:
                            #right col; not in corner
                            if grid[row+1][col]==1 or grid[row][col-1]==1 or grid[row-1][col]==1:
                                g_converts.add((row,col))
                            elif grid[row+1][col]==2 or grid[row][col-1]==2 or grid[row-1][col]==2:
                                m_converts.add((row,col))
                                    
                        else:
                            #all neighboring tiles exist (yay!)
                            if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row-1][col]==1 or grid[row][col-1]==1:
                                g_converts.add((row,col))
                            if grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row-1][col]==2 or grid[row][col-1]==2:
                                m_converts.add((row,col))
            #print("G_converts")
            #print(g_converts)
            #print("M_converts")
            #print(m_converts)
            for k in range(len(g_converts)):
                grid[list(g_converts)[k][0]][list(g_converts)[k][1]]=1
            for j in range(len(m_converts)):
                if list(m_converts)[j] not in g_converts:
                    grid[list(m_converts)[j][0]][list(m_converts)[j][1]]=2
            

                                    
        elif i%2==0:#tiles neighboring grass turn into grass
            converts = set()
            for row in range(gridsize+1):
                for col in range(gridsize+1):
                    if grid[row][col]==0:
                        if row==0:
                            if col==0:
                                #top left corner
                                if grid[row+1][col]==1 or grid[row][col+1]==1:
                                    converts.add((row,col))
                            elif col==gridsize:
                                #top right corner
                                if grid[row+1][col]==1 or grid[row][col-1]==1:
                                    converts.add((row,col))
                            else:
                                #top row; not in corner
                                if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row][col-1]==1:
                                    converts.add((row,col))
                        elif row==gridsize:
                            if col==0:
                                #bottom left corner
                                if grid[row-1][col]==1 or grid[row][col+1]==1:
                                    converts.add((row,col))
                            elif col==gridsize:
                                #bottom right corner
                                if grid[row-1][col]==1 or grid[row][col-1]==1:
                                    converts.add((row,col))
                            else:
                                #bottom row; not in corner
                                if grid[row][col-1]==1 or grid[row][col+1]==1 or grid[row-1][col]==1:
                                    converts.add((row,col))
                        elif col==0:
                            #left col; not in corner
                            if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row-1][col]==1:
                                    converts.add((row,col))
                        elif col==gridsize:
                            #right col; not in corner
                            if grid[row+1][col]==1 or grid[row][col-1]==1 or grid[row-1][col]==1:
                                    converts.add((row,col))
                        else:
                            #all neighboring tiles exist (yay!)
                            if grid[row+1][col]==1 or grid[row][col+1]==1 or grid[row-1][col]==1 or grid[row][col-1]==1:
                                    converts.add((row,col))
            #print("converts")
            #print(converts)
            for k in range(len(converts)):
                grid[list(converts)[k][0]][list(converts)[k][1]]=1

                    
        elif i%7==0:#tiles neighboring mycelium turn into mycelium
            converts = set()
            for row in range(gridsize+1):
                for col in range(gridsize+1):
                    if grid[row][col]==0:
                        if row==0:
                            if col==0:
                                #top left corner
                                if grid[row+1][col]==2 or grid[row][col+1]==2:
                                    converts.add((row,col))
                            elif col==gridsize:
                                #top right corner
                                if grid[row+1][col]==2 or grid[row][col-1]==2:
                                    converts.add((row,col))
                            else:
                                #top row; not in corner
                                if grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row][col-1]==2:
                                    converts.add((row,col))
                        elif row==gridsize:
                            if col==0:
                                #bottom left corner
                                if grid[row-1][col]==2 or grid[row][col+1]==2:
                                    converts.add((row,col))
                            elif col==gridsize:
                                #bottom right corner
                                if grid[row-1][col]==2 or grid[row][col-1]==2:
                                    converts.add((row,col))
                            else:
                                #bottom row; not in corner
                                if grid[row][col-1]==2 or grid[row][col+1]==2 or grid[row-1][col]==2:
                                    converts.add((row,col))
                        elif col==0:
                            #left col; not in corner
                            if grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row-1][col]==2:
                                    converts.add((row,col))
                        elif col==gridsize:
                            #right col; not in corner
                            if grid[row+1][col]==2 or grid[row][col-1]==2 or grid[row-1][col]==2:
                                    converts.add((row,col))
                        else:
                            #all neighboring tiles exist (yay!)
                            if grid[row+1][col]==2 or grid[row][col+1]==2 or grid[row-1][col]==2 or grid[row][col-1]==2:
                                    converts.add((row,col))
            #print("converts")
            #print(converts)
            for k in range(len(converts)):
                grid[list(converts)[k][0]][list(converts)[k][1]]=2
        #print("tick"+str(i))
        #for k in range(21):
            #print(grid[k])

    output = 0
    for j in range(gridsize+1):
        for k in range(gridsize+1):
            if grid[j][k]==2:
                output+=1
    return output


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
