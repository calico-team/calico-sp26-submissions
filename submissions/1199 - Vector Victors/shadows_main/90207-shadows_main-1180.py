def find_min(n, s1, s2):
    dict1 = {} # maps z -> (# of valid xs, coming from s1)
    for i in range(n):
        # z level is rows
        dict1[i] = s1[i].count('#')
    dict2 = {}
    for i in range(n):
        # z level is rows again
        dict2[i] = s2[i].count('#')
    
    min_vol = 0
    for z in range(n):
        # value is max(#x, #y)
        min_vol += max(dict1[z], dict2[z])
    
    return min_vol
"""
27
-3 = 24
-3 = 21
-2 = 19
-2 = 17
"""
def find_max(n, s1, s2):
    nb_in_yz = [n]*n # nb_in_yz[z] = # remaining for each y in this z level
    #print(nb_in_yz)

    max_volume = n**3
    for i in range(n):
        for j in range(n):
            if s1[i][j] == '.':
                # empty
                max_volume -= n
                nb_in_yz[i] -= 1
    
    #print(nb_in_yz)
    for i in range(n):
        for j in range(n):
            if s2[i][j] == '.':
                # empty
                #print(nb_in_yz[i])
                max_volume -= nb_in_yz[i]
    
    return max_volume

def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    min_vol = find_min(N, S1, S2)
    max_vol = find_max(N, S1, S2)
    return (max_vol, min_vol)


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
