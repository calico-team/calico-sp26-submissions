def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N = int(input[ptr])
        ptr += 1
        a = list(map(int, input[ptr:ptr+N]))
        ptr += N
        print(" ".join([str(median)]* N))
    
if __name__ == "__main__":
    main()