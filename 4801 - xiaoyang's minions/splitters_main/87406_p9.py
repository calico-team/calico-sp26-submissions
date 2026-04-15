from math import gcd
def solve(N, M, factory):
    ls = [(0,0,30,30)]
    successful = 0
    total = 2**30*3**30
    while (len(ls) != 0):
        new_ls = []
        for tuple in ls:
            #print(tuple)
            if not (0 <= tuple[1] <= M-1 and 0 <= tuple[0] <= N-1):
                successful += 2**tuple[2] * 3**tuple[3]
                #print("out of factory")
                continue
            pos = [tuple[0],tuple[1]]
            factory_tile = factory[pos[0]][pos[1]]
            #print(factory_tile)
            if factory_tile == '^':
                pos[0] -= 1
                new_ls.append((pos[0],pos[1],tuple[2],tuple[3]))
            elif factory_tile == 'v':
                pos[0] += 1
                new_ls.append((pos[0],pos[1],tuple[2],tuple[3]))
            elif factory_tile == '>':
                pos[1] += 1
                new_ls.append((pos[0],pos[1],tuple[2],tuple[3]))
            elif factory_tile == '<':
                pos[1] -= 1
                new_ls.append((pos[0],pos[1],tuple[2],tuple[3]))
            elif factory_tile == 'X':
                continue
            elif factory_tile == 'S':
                ls_valid = []
                ls_check = [(pos[0]-1,pos[1]),(pos[0]+1,pos[1]),(pos[0],pos[1]-1),(pos[0],pos[1]+1)]
                for type in ls_check:
                    if not (0 <= type[1] <= M-1 and 0 <= type[0] <= N-1):
                        continue
                    ntype = list(type)
                    factory_tile = factory[type[0]][type[1]]
                    if factory_tile == '^':
                        ntype[0] -= 1
                    elif factory_tile == 'v':
                        ntype[0] += 1
                    elif factory_tile == '>':
                        ntype[1] += 1
                    elif factory_tile == '<':
                        ntype[1] -= 1
                    elif factory_tile == 'X':
                        ls_valid.append(type)
                    else:
                        continue
                    if ntype != list(pos):
                        ls_valid.append(type)
                ls_valid = list(set(ls_valid))
                #print(ls_valid)
                if (len(ls_valid) == 3):
                    for ntuple in ls_valid:
                        new_ls.append((ntuple[0],ntuple[1],tuple[2],tuple[3]-1))
                elif (len(ls_valid) == 2):
                    for ntuple in ls_valid:
                        new_ls.append((ntuple[0],ntuple[1],tuple[2]-1,tuple[3]))
                else:
                    for ntuple in ls_valid:
                        new_ls.append((ntuple[0],ntuple[1],tuple[2],tuple[3]))
        ls = new_ls
        #print(ls)
    return (successful//gcd(successful,total), total//gcd(successful,total))

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
