import sys
import math

def solve():
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        K = int(input_data[idx]); idx += 1
        N = int(input_data[idx]); idx += 1
        M = int(input_data[idx]); idx += 1
        P = int(input_data[idx]); idx += 1
        Q = int(input_data[idx]); idx += 1
        
        asteroids = []
        for __ in range(K):
            x = int(input_data[idx]); idx += 1
            y = int(input_data[idx]); idx += 1
            asteroids.append((x, y))
        
        x0, y0 = asteroids[0]
        
        # 预计算 gcd 和逆元所需
        g1 = math.gcd(Q, N)
        g2 = math.gcd(P, M)
        
        N1 = N // g1
        M1 = M // g2
        
        Q1 = Q // g1
        P1 = P // g2
        
        # 预计算 invQ1 模 N1, invP1 模 M1
        # 因为 Q1 与 N1 互质
        invQ1 = pow(Q1, -1, N1) if N1 > 1 else 1
        invP1 = pow(P1, -1, M1) if M1 > 1 else 1
        
        best_t = None
        best_i = -1
        
        for i in range(1, K):
            x, y = asteroids[i]
            dx = (x - x0) % N
            dy = (y - y0) % M
            
            if dx % g1 != 0 or dy % g2 != 0:
                continue
            
            dxp = dx // g1
            dyp = dy // g2
            
            a = (dxp * invQ1) % N1
            b = (dyp * invP1) % M1
            
            # 解 t ≡ a (mod N1), t ≡ b (mod M1)
            # t = a + k*N1
            # a + k*N1 ≡ b (mod M1)
            # k*N1 ≡ b-a (mod M1)
            lhs = N1 % M1
            rhs = (b - a) % M1
            g = math.gcd(lhs, M1)
            if rhs % g != 0:
                continue
            
            lhs //= g
            M1g = M1 // g
            rhs //= g
            
            # 解 lhs * k ≡ rhs (mod M1g)
            # 求 lhs 模 M1g 的逆元
            inv_lhs = pow(lhs, -1, M1g)
            k0 = (rhs * inv_lhs) % M1g
            
            # 最小正 t = a + k0*N1
            t_val = a + k0 * N1
            if t_val == 0:
                # 如果 t_val == 0，表示在 t=0 步命中，但只有 i=0 才可能，这里 i>=1，所以取下一个同余解：加 LCM(N1, M1)
                lcm_val = N1 // math.gcd(N1, M1) * M1
                t_val = lcm_val
            # 确保 t_val > 0
            if t_val == 0:
                t_val = N1 * M1g
            
            if best_t is None or t_val < best_t:
                best_t = t_val
                best_i = i
        
        results.append(str(best_i))
    
    sys.stdout.write("\n".join(results))

if __name__ == "__main__":
    solve()