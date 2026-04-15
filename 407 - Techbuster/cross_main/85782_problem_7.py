import sys
input = sys.stdin.readline

def make_criss_cross(P, M):

    out= []
    for r in range(P):
        base=(2 * r) % 5
        row = [(base + c) %5 for c in range(M)]
        out.append(' '.join(map(str, row)))
    print('\n'.join(out))

def read_input():
    T =int(input())
    for _ in range(T):
        P, M= map(int,input().split())
        make_criss_cross(P, M)

read_input()