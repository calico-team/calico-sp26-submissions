def main():
    import sys
    data = sys.stdin.read().split()
    ptr = 0
    T = int(data[ptr])
    ptr += 1
    for _ in range(T):
        N = int(data[ptr])
        ptr += 1
        print(' '.join(data[ptr:ptr+N]))
        ptr += N

if __name__ == "__main__":
    main()
