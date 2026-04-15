
line = input()
l, w, e, r = map(int, line.split())

    
pr_ans =e // ((l+w)*2*r) 
ans =  e// ((l+w)*2*r) if e/ ((l+w)*2*r) == pr_ans else e// ((l+w)*2*r)+1

print(e // ((l+w)*2*r))