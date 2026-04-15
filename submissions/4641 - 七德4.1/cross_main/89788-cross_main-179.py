import random
number_of_test=int(input())
values=["0","1","2","3","4"]
if number_of_test<=10 and number_of_test>1:
    for i in range(number_of_test):
        listA=input().split()
        list1=[]
        list2=[]
        list3=[]
        eliminate=[]
        M=int(listA[0])
        N=int(listA[1])

        def generaterandom(eli):
            for i in eli:
                if i in values:
                    values.remove(i)
                else: 
                    continue
            rn=random.choice(values)
            eliminatevalue(rn)
            return rn
        
        def eliminatevalue(a):
            eliminate.append(a)

        def reset():
            eliminate.clear()
            values.clear()
            for i in range(5):
                values.append(str(i))

        if M<3 or N<3:
            for i in range(M):
                for i in range(N):
                    list1.append(str(random.randint(0,4)))
                list1join=" ".join(list1)
                print(list1join)
                list1.clear()
        else:
            randomnum=str(random.randint(0,4))
            list1.append(randomnum)
            list2.append(randomnum)
            list3.append(randomnum)
            eliminatevalue(randomnum)
            list2.append(generaterandom(eliminate))
            for i in range(2,N):
                eliminatevalue(list2[i-2])
                eliminatevalue(list2[i-1])
                list2.append(generaterandom(eliminate))
                list1.append(generaterandom(eliminate))
                list3.append(generaterandom(eliminate))
                reset()
            list1.append(randomnum)
            list3.append(randomnum)
            list1join=" ".join(list1)
            list2join=" ".join(list2)
            list3join=" ".join(list3)
            print(list1join)
            print(list2join)
            print(list3join)