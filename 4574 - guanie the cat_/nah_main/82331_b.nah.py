for T in range(int(input())):
    n, p, r, k = [int(i) for i in input().split()]
    nums = [int(i) for i in input().split()]
    counter = 0
    for i in nums:
        counter += 1
        if counter == k:
            counter = 0
            p += r
        p -= i
        if p < 0:
            ans = False
            break
    else:
        ans = True
    
    if ans:
        print("nah i'd win")
    else:
        print("nah i'd lose")