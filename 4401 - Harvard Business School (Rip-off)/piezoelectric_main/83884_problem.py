

import sys


lines = sys.stdin.read().strip().split('\n')

T = int(lines[0])  # 第一行是case数量

for i in range(1, T + 1):
    l,w,e,r = map(int, lines[i].split())
    pr_ans =e // ((l+w)*2*r) 
    ans =  e// ((l+w)*2*r) if e/ ((l+w)*2*r) == pr_ans else e// ((l+w)*2*r)+1

    print(e // ((l+w)*2*r))