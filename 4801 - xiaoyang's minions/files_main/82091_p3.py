for _ in range(int(input())):
    a = input()
    b = input()
    ind_b = 0
    for i in range(len(a)):
        if ind_b >= len(b):
            print('#',end = '')
        elif a[i] == b[ind_b]:
            print(a[i],end = '')
            ind_b += 1
        else:
            print('#',end = '')
    print()
    
