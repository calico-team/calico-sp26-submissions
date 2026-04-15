import sys

def run():
    rl = sys.stdin.readline
    line = rl()
    
    t_cnt = int(line)
    for _ in range(t_cnt):
        k = int(rl())
        
        left_counts = [rl().count('#') for _ in range(k)]
        
        total_high = 0
        total_low = 0
        
        for w in range(k):
            right_now = rl().count('#')
            total_high += left_counts[w] * right_now
            total_low += left_counts[w] if left_counts[w] > right_now else right_now
            
        sys.stdout.write(f"{total_high} {total_low}\n")

if __name__ == '__main__':
    run()