def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    
    T = int(input[ptr]); ptr += 1
    for _ in range(T):
        N = int(input[ptr]); ptr += 1
        a = list(map(int, input[ptr:ptr+N])); ptr += N
        
        if N <= 3:
            median = sorted(a)[N//2]
            print(" ".join([str(median)]* N))
            
    else:
        print(" ". join(map(str, a)))
    
if __name__ == "__main__":
    main()