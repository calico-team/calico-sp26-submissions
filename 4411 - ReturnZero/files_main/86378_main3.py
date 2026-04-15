
def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    new = ""
    hash_table_set = set()
    point = 0
    for i in range(len(A)):
        if  point < len(B) and A[i] == B[point]:
            hash_table_set.add(i)
            point+=1
    print(hash_table_set,"points")
    
    for i in range(len(A)):
        if i in hash_table_set:
            new+=A[i]
        else:
            new+="#"
    
    return new

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
