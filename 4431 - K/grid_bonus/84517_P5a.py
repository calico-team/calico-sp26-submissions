def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        A = list(map(int, input[ptr:ptr+N]))
        ptr += N
        the_two_tower_heights = A.copy()
        print(" ".join(map(str, the_two_tower_heights)))

def read_your_input():
    import sys
    return sys.stdin.read
    
if __name__ == "__main__":
    main()