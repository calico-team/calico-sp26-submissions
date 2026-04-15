T = int(input("number of test cases"))
finished = 0
for i in range(T):
        A = input("give a string")
        B = input("give another string")
        A2 = ""
        j = 0
        for i in range(len(A)):
                if finished == 0 and A[i] == B[j]:
                        A2 += B[j]
                        j += 1
                        if j == len(B):
                                finished = 1
                else:
                        A2 += "#"
        j = 0
        finished = 0
        print(A2)
