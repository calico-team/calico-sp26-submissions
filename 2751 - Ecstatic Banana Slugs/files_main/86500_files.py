#import sys
from collections import Counter
#sys.stdin=open("#files")

def main(thing,goal):
    
    pre = list(thing)
    post = list(goal)
    result = []
    t = 0
    x = 0
    
    while True:
        #is_subset = not (Counter(list_b) - Counter(list_a))
        th = not (Counter(post) - Counter(result))
        if th:
            break
        if post[t] == pre[x]:
            result.append(post[t])
            t+=1
            x+=1
        else:
            result.append("#")
            x+=1
    return result
          
answers = []
n = int(input())
for i in range(n):
    pre = input()
    post = input()
    answers.append(main(pre,post))
for i in range(n):
    print(''.join(answers[i]))
        