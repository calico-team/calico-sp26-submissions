def solve(A: str, B: str) -> str:
    """
    For each test case, output the result of redacting the initial string A.

    A: the initial string
    B: the target string
    """
    def replace(a:str, b:str) -> str:

    result = []
    j = 0
    for i in a:
        if j < len(b) and i == b[j]:
            j += 1
            result.append(i)
        else:
            result.append("#")
    return ''.join(result)


a = "ccaalliiccoo"
b = "calico"
print(replace(a,b))
a ="big_bens_bday"
b = "bbb"
print(replace(a,b))
a = "job"
b = "jb"
print(replace(a,b))
a = "include_over_californication"
b = "ilovecalico"
print(replace(a,b))
a ="six_seven_rizzler_sigma_banned_discord_skibidi_toilet"
b ="severance"
print(replace(a,b))
    return ""

def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
