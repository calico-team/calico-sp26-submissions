a = int(input())

for _ in range(a):
    b, c = map(int, input().split())

    for i in range(b):

      
        if i % 2 == 0:
            row = []
            for j in range(c):
               
                row.append(str(j % 2))
        
      
        else:
            row = []
            for j in range(c):
                row.append(str(j + 1))

        print(" ".join(row))