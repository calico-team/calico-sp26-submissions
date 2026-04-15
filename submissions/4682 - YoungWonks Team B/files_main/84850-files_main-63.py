# t = int(input())
# for i in range(t):
#     a = input()
#     b = input()
#     for i in b:
#         for j in range(0, len(a)):
#             if i == a[j]: 
#                 continue
#             else a[j] = '#'

t = int(input())

test_cases = []

for i in range(t):
    a = input()
    b = input()
    test_cases.append([a,b])

for test in test_cases:



    letters = []

    a = test[0]
    b = test[1]

    extra = a.split()

    new_a = ""


   

    # for char in b:
    #     letters.append(char)
    #     b.replace(char,"")
    #     a.replace(char,"")

    while len(b) >= 1:

        if a[0] == b[0]:
            new_a += a[0]
            a = a[1:]
            b = b[1:]
        
        else:

            new_a += '#'
            a = a[1:]

    print(new_a)




    # print(b,a)
        
    # for i,j in zip(letters,b):
    #     if i != j:
    #         letters.remove(i)

    
    
    # print(letters)



        