def main():
    import sys
    lines = [line.strip() for line in sys.stdin if line.strip()]
    ptr = 0
    T = int(lines[ptr])
    ptr += 1
    for _ in range(T):
        N = int(lines[ptr])
        ptr += 1
        A = list(map(int, lines[ptr].split()))
        ptr += 1
        print(' '.join(map(str, A)))

if __name__ == "__main__":
    main()


