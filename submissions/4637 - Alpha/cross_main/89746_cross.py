T = int(input("Enter T"))#Number of repeating
countT = 0
if T >=1 and T <=10:
    while countT != T:
        dimensions = input("Enter the length of grid in form[Width Length]")
        dimensions = dimensions.split(" ")
        N = int(dimensions[0])#The rows
        M = int(dimensions[1]) #number of elements per row
        flag = True
        if M < 3 and N > 1000:
            flag = False
        grid = []
        if flag == True:
            grid = [[0 for a in range(M)] for b in range(N)]
            row_repeat = [0,2,4,1,3]
            for a in range(N):#for rows
                Find_rr= a % 5
                m = row_repeat[Find_rr]
                grid[a][0] = m
                for b in range(M-1):
                    m +=1
                    if m==5:
                        m=0
                    grid[a][b+1] = m
            for c in range(N):
                print(grid[c])
        countT += 1






    countT += 1#repead until T times