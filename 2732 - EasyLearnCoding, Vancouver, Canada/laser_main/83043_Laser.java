import java.util.*;

public class Laser {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int K = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();
            int P = sc.nextInt();
            int Q = sc.nextInt();

            int[] ax = new int[K];
            int[] ay = new int[K];
            for (int i = 0; i < K; i++) {
                ax[i] = sc.nextInt();
                ay[i] = sc.nextInt();
            }

            long startX = ax[0];
            long startY = ay[0];
            long periodX = N / gcd(N, Q);
            long periodY = M / gcd(M, P);
            long period = lcm(periodX, periodY);

            long bestStep = Long.MAX_VALUE;
            int bestIdx = -1;

            for (int i = 0; i < K; i++) {
                // we want the smallest t > 0 where the laser lands on asteroid i
                // solve: startX + t*Q ≡ ax[i] (mod N)  =>  t*Q ≡ dx (mod N)
                //        startY + t*P ≡ ay[i] (mod M)  =>  t*P ≡ dy (mod M)
                long dx = ((ax[i] - startX) % N + N) % N;
                long dy = ((ay[i] - startY) % M + M) % M;

                // solve t*Q ≡ dx (mod N) for t
                long tx = solveLinear(Q, dx, N);
                // solve t*P ≡ dy (mod M) for t
                long ty = solveLinear(P, dy, M);

                // no solution for one of the axes means this asteroid is unreachable
                if (tx < 0 || ty < 0) continue;

                // now combine: t ≡ tx (mod periodX) and t ≡ ty (mod periodY)
                // using CRT
                long t = crt(tx, periodX, ty, periodY);
                if (t < 0) continue; // incompatible — asteroid unreachable

                // t == 0 means it's the starting position; that only counts
                // after a full cycle (the laser doesn't hit asteroid 0 at step 0)
                if (t == 0) t = period;

                if (t < bestStep) {
                    bestStep = t;
                    bestIdx = i;
                }
            }

            System.out.println(bestIdx);
        }
    }

    // solve a*t ≡ b (mod n), returns smallest non-negative t, or -1 if no solution
    static long solveLinear(long a, long b, long n) {
        long g = gcd(a, n);
        if (b % g != 0) return -1; // no solution
        // reduce: (a/g)*t ≡ (b/g) (mod n/g)
        long a2 = a / g, b2 = b / g, n2 = n / g;
        // t = b2 * modInverse(a2, n2) mod n2
        long inv = modInverse(a2, n2);
        return (b2 % n2 * inv) % n2;
    }

    // CRT: find t such that t ≡ r1 (mod m1) and t ≡ r2 (mod m2)
    // returns smallest non-negative t, or -1 if no solution
    static long crt(long r1, long m1, long r2, long m2) {
        // t = r1 + m1*k, need r1 + m1*k ≡ r2 (mod m2)
        // => m1*k ≡ (r2 - r1) (mod m2)
        long diff = ((r2 - r1) % m2 + m2) % m2;
        long g = gcd(m1, m2);
        if (diff % g != 0) return -1;
        long m1r = m1 / g, m2r = m2 / g;
        long k = (diff / g % m2r * modInverse(m1r, m2r)) % m2r;
        long lcm = m1 * m2r; // = lcm(m1, m2)
        return (r1 + m1 * k) % lcm;
    }

    // modular inverse via extended Euclidean — assumes gcd(a, n) == 1
    static long modInverse(long a, long n) {
        long[] r = extgcd(a, n);
        return (r[1] % n + n) % n;
    }

    // returns [gcd, x, y] such that a*x + b*y = gcd
    static long[] extgcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] r = extgcd(b, a % b);
        return new long[]{r[0], r[2], r[1] - (a / b) * r[2]};
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}