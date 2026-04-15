def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N = int(input[ptr])
        M = int(input[ptr+1])
        ptr += 2
        for i in range(N):
            row = []
            for j in range(M):
                val = (i + 2 *j) % 5
                row.append(str(val))
            print(" ".join(row))
            
if __name__ == "__main__":
    main()