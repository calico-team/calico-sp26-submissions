t = int(input())
import math
for _ in range(t):
    l,w,e,r = map(int,input().split())

    #print(f'e is {e} every lap is {2*(l+w)*r}')
    print(int(math.ceil(e/(2*(l+w)*r))))
