import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Main {

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }


    static long exgcd(long a, long b, long[] arr) {
        if (b == 0) {
            arr[0] = 1;
            arr[1] = 0;
            return a;
        }
        long g = exgcd(b, a % b, arr);
        long tmp = arr[0];
        arr[0] = arr[1];
        arr[1] = tmp - (a / b) * arr[1];
        return g;
    }

    // 求逆元
    static long modInv(long a, long m) {
        long[] arr = new long[2];
        long g = exgcd(a, m, arr);
        if (g != 1) return -1;
        return (arr[0] % m + m) % m;
    }

    
    static long solveMod(long step, long target, long mod) {
        target = (target % mod + mod) % mod;
        long g = gcd(step, mod);
        if (target % g != 0) return -1;

        long newStep = step / g;
        long newTarget = target / g;
        long newMod = mod / g;

        long inv = modInv(newStep, newMod);
        if (inv == -1) return -1;

        return (newTarget * inv) % newMod;
    }

    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {
        long x0 = X[0];
        long y0 = Y[0];
        long minT = Long.MAX_VALUE;
        int ans = 0;

        long lcmNM = lcm(N, M);

        for (int i = 0; i < K; i++) {
            long dx = (X[i] - x0) % N;
            long dy = (Y[i] - y0) % M;
            if (dx < 0) dx += N;
            if (dy < 0) dy += M;

            long tx = solveMod(Q, dx, N);
            if (tx == -1) continue;

            long ty = solveMod(P, dy, M);
            if (ty == -1) continue;

            long gx = gcd(Q, N);
            long periodX = N / gx;

            long gy = gcd(P, M);
            long periodY = M / gy;

            long t = crt(tx, periodX, ty, periodY);
            if (t == -1) continue;

            long lcmPeriod = lcm(periodX, periodY);
            if (t == 0) t = lcmPeriod;

            if (t > 0 && t < minT) {
                minT = t;
                ans = i;
            }
        }

        return ans;
    }

    static long crt(long a1, long m1, long a2, long m2) {
        long[] arr = new long[2];
        long g = exgcd(m1, m2, arr);
        long diff = a2 - a1;
        if (diff % g != 0) return -1;

        long lcm = m1 / g * m2;
        long m1g = m1 / g;
        long m2g = m2 / g;

        long k = (diff / g) % m2g;
        if (k < 0) k += m2g;

        long inv = modInv(m1g, m2g);
        if (inv == -1) return -1;

        k = (k * inv) % m2g;
        if (k < 0) k += m2g;

        long t = a1 + k * m1;
        t = (t % lcm + lcm) % lcm;
        return t;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        while (T-- > 0) {
            String[] temp = in.readLine().split(" ");
            int K = Integer.parseInt(temp[0]);
            int N = Integer.parseInt(temp[1]);
            int M = Integer.parseInt(temp[2]);
            int P = Integer.parseInt(temp[3]);
            int Q = Integer.parseInt(temp[4]);

            int[] X = new int[K];
            int[] Y = new int[K];
            for (int i = 0; i < K; i++) {
                String[] point = in.readLine().split(" ");
                X[i] = Integer.parseInt(point[0]);
                Y[i] = Integer.parseInt(point[1]);
            }

            out.println(solve(K, N, M, P, Q, X, Y));
        }

        out.flush();
    }
}