
def solve(A: str, B: str) -> str:
    text1 = ""
    count = 0
    for a in A:
        if count < len(B) and a==B[count]:
            count += 1
            text1 = text1 + a
        else:
            text1 = text1 +"#"
    return text1


def main():
    T = int(input())
    for _ in range(T):
        A = input()
        B = input()
        print(solve(A, B))

if __name__ == '__main__':
    main()
