t=int(input('How many test cases? '))
for i in range(t):
    
    n, p, r, k=map(int,input('Make sure to separate each integer with a space ').split())
    curses=[]
    while True:
        curses=list(map(int,input('Enter the power of each curse and make sure to separate each number with a space ').split()))
        if len(curses)>n or len(curses)<n:
            print('Please try again ')
        else:
            break
    kill_ct=0
    lost=False
    for i in curses:
        p-=i
        kill_ct+=1
        if p<0:
            lost=True
            break
        if kill_ct==k:
            p+=r
            kill_ct=0
    if lost:
        print("nah i'd lose")
    else:
        print("nah i'd win")
    
