import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JoshContext041201 {
    // 快速 I/O 类，应对 K 的总和达 10^5 的输入
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String tStr = sc.next();
        if (tStr == null) return;
        int T = Integer.parseInt(tStr);

        while (T-- > 0) {
            int K = sc.nextInt();
            long N = sc.nextLong();
            long M = sc.nextLong();
            long P = sc.nextLong(); // Y-axis steps
            long Q = sc.nextLong(); // X-axis steps

            long[] X = new long[K];
            long[] Y = new long[K];
            for (int i = 0; i < K; i++) {
                X[i] = sc.nextLong();
                Y[i] = sc.nextLong();
            }

            long startX = X[0];
            long startY = Y[0];

            long minTime = Long.MAX_VALUE;
            int bestAsteroid = -1;

            // 遍历所有小行星，求解命中的最短时间
            for (int i = 0; i < K; i++) {
                long dx = (X[i] - startX) % N;
                if (dx < 0) dx += N;

                long dy = (Y[i] - startY) % M;
                if (dy < 0) dy += M;

                long t = solve(Q, N, P, M, dx, dy);

                // 如果能击中，并且所需时间更短
                if (t != -1) {
                    if (t < minTime) {
                        minTime = t;
                        bestAsteroid = i;
                    }
                }
            }
            System.out.println(bestAsteroid);
        }
    }

    // 求解方程：t*Q ≡ dx (mod N) 且 t*P ≡ dy (mod M)
    static long solve(long Q, long N, long P, long M, long dx, long dy) {
        // 解第一个方程：t * Q ≡ dx (mod N)
        long g1 = gcd(Q, N);
        if (dx % g1 != 0) return -1;
        long Q_prime = Q / g1;
        long N_prime = N / g1;
        long dx_prime = dx / g1;
        long invQ = modInverse(Q_prime, N_prime);
        long r1 = (dx_prime * invQ) % N_prime;

        // 解第二个方程：t * P ≡ dy (mod M)
        long g2 = gcd(P, M);
        if (dy % g2 != 0) return -1;
        long P_prime = P / g2;
        long M_prime = M / g2;
        long dy_prime = dy / g2;
        long invP = modInverse(P_prime, M_prime);
        long r2 = (dy_prime * invP) % M_prime;

        // 用扩展 CRT 将两个约束合并
        return crt(r1, N_prime, r2, M_prime);
    }

    // 求解：t ≡ r1 (mod n1) 且 t ≡ r2 (mod n2)
    static long crt(long r1, long n1, long r2, long n2) {
        // 令 t = r1 + k * n1, 带入第二个方程得到：
        // k * n1 ≡ r2 - r1 (mod n2)
        long diff = (r2 - r1) % n2;
        if (diff < 0) diff += n2;

        long g = gcd(n1, n2);
        if (diff % g != 0) return -1; // 矛盾，无解

        long n1_prime = n1 / g;
        long n2_prime = n2 / g;
        long diff_prime = diff / g;

        long inv = modInverse(n1_prime, n2_prime);
        long k = (diff_prime * inv) % n2_prime;

        long t = r1 + k * n1;

        // 联合周期为 lcm(n1, n2)
        long period = n1 * n2_prime;

        // 题目要求寻找严格为正数的步数（起点也会在绕行一圈后被命中）
        if (t == 0) {
            t += period;
        }
        return t;
    }

    // 求最大公约数
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // 求扩展欧几里得 [gcd(a,b), x, y]
    static long[] extGCD(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGCD(b, a % b);
        long x1 = res[1];
        long y1 = res[2];
        return new long[]{res[0], y1, x1 - (a / b) * y1};
    }

    // 求模逆元 a^(-1) mod m
    static long modInverse(long a, long m) {
        if (m == 1) return 0;
        long[] res = extGCD(a, m);
        return (res[1] % m + m) % m;
    }
}