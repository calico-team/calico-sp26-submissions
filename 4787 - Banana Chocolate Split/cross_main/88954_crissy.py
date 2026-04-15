t = int(input())
for _ in range(t):
    x,y = map(int, input().split())
    fullcross = list()
    c = 0
    b = 0
    rowcross = list()
    for i in range(x):
        for j in range(y):
            sum = c + j
            if sum > 4:
                sum = sum % 4
            print(sum, end = " ")
        c += 2
        fullcross.append(rowcross)
        print(" ")    
    
        

    
    