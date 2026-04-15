import sys

def censor_this_please(A: str, B: str) -> str:
    result = []
    b_idx = 0
    
    for char in A:
        # Agar B ke characters bache hain aur current character match karta hai
        if b_idx < len(B) and char == B[b_idx]:
            result.append(char)
            b_idx += 1
        else:
            # Warna # laga do
            result.append('#')
            
    return "".join(result)

def read_your_input():
    input_data = sys.stdin.read().split()
    if not input_data:
        return []
    
    T = int(input_data[0])
    test_cases = []
    idx = 1
    
    for _ in range(T):
        # Input format ke mutabiq A aur B ko pair mein store karna
        A = input_data[idx]
        B = input_data[idx + 1]
        test_cases.append((A, B))
        idx += 2
        
    return test_cases

if __name__ == '__main__':
    cases = read_your_input()
    for A, B in cases:
        print(censor_this_please(A, B))