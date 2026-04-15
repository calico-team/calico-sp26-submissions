
def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    new = ""
    hash_table = {}
    for i in B:
        if i in hash_table:
            hash_table[i] += 1
        else:
            hash_table[i] = 1
    
    for i in A:
        if hash_table[i]!=0:
            hash_table[i]-=1
            new+="#"
        else:
            new+=i
    
    return new

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
