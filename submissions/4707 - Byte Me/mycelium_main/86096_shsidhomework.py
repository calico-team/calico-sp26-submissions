t = int(input())

def solve(g1,g2,m1,m2):
    coor_g = [(g1,g2)]
    coor_m = [(m1,m2)]
    i_len = len(coor_m)
    m_exp = True
    count = 1
    while m_exp:
        if count %14 ==0:
            for i in coor_g:
                up = (i[0],i[1]+1)
                down = (i[0],i[1]-1)
                left = (i[0]-1,i[1])
                right = (i[0]+1,i[1])
                if up not in coor_m:
                    coor_g.append(up)
                if down not in coor_m:
                    coor_g.append(down)
                if left not in coor_m:
                    coor_g.append(left)
                if right not in coor_m:
                    coor_g.append(right)
                coor_g = list(set(coor_g))
            
            for i in coor_m:
                up = (i[0],i[1]+1)
                down = (i[0],i[1]-1)
                left = (i[0]-1,i[1])
                right = (i[0]+1,i[1])
                if up not in coor_g:
                    coor_m.append(up)
                if down not in coor_g:
                    coor_m.append(down)
                if left not in coor_g:
                    coor_m.append(left)
                if right not in coor_g:
                    coor_m.append(right)
                coor_m = list(set(coor_m))
                if i_len == len(coor_m):
                    return i_len
                else:
                    i_len = len(coor_m)
        elif count %7 == 0:
            for i in coor_m:
                up = (i[0],i[1]+1)
                down = (i[0],i[1]-1)
                left = (i[0]-1,i[1])
                right = (i[0]+1,i[1])
                if up not in coor_g:
                    coor_m.append(up)
                if down not in coor_g:
                    coor_m.append(down)
                if left not in coor_g:
                    coor_m.append(left)
                if right not in coor_g:
                    coor_m.append(right)
                coor_m = list(set(coor_m))
                if i_len == len(coor_m):
                    return i_len
                else:
                    i_len = len(coor_m)
        elif count %2==0:
            for i in coor_g:
                up = (i[0],i[1]+1)
                down = (i[0],i[1]-1)
                left = (i[0]-1,i[1])
                right = (i[0]+1,i[1])
                if up not in coor_m:
                    coor_g.append(up)
                if down not in coor_m:
                    coor_g.append(down)
                if left not in coor_m:
                    coor_g.append(left)
                if right not in coor_m:
                    coor_g.append(right)
                coor_g = list(set(coor_g))
        count+=1

                

            
                

    return len(coor_m)




for i in range(t):
    g1,g2,m1,m2 = map(int,input().split())
    print(solve(g1,g2,m1,m2)+1)
    
    