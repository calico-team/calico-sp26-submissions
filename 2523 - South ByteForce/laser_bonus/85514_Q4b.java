import java.util.*;
import java.io.*;

public class Q4b {
    public static long[] extGcd(long a, long b) {
        if (b == 0)
            return new long[] { a, 1, 0 };
        long[] r = extGcd(b, a % b);
        return new long[] { r[0], r[2], r[1] - (a / b) * r[2] };
    }

    public static long modInv(long a, long m) {
        if (m == 1)
            return 0;
        a = ((a % m) + m) % m;
        long[] r = extGcd(a, m);
        return ((r[1] % m) + m) % m;
    }

    public static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    public static int solve(int K, int N, int M, int P, int Q, int[][] ast) {
        int x0 = ast[0][0];
        int y0 = ast[0][1];

        long gcd1 = gcd(Q, N);
        long rModX = N / gcd1;
        long gcd2 = gcd(P, M);
        long rModY = M / gcd2;
        long lcm = (rModX / gcd(rModX, rModY)) * rModY;

        long bestT = Long.MAX_VALUE;
        int bestAstIndex = -1;

        for (int i = 0; i < K; i++) {
            long dx = ((((long) (ast[i][0] - x0)) % N) + N) % N;
            long dy = ((((long) (ast[i][1] - y0)) % M) + M) % M;

            if (dx % gcd1 != 0)
                continue;
            long r1 = (((dx / gcd1) % rModX) * modInv((Q / gcd1), rModX)) % rModX;
            if (dy % gcd2 != 0)
                continue;
            long r2 = (((dy / gcd2) % rModY) * modInv((P / gcd2), rModY)) % rModY;

            long gcdMod = gcd(rModX, rModY);
            long diff = r2 - r1;
            if (diff % gcdMod != 0)
                continue;

            long n2DivGcd = rModY / gcdMod;
            long k = (((((diff / gcdMod) % n2DivGcd) + n2DivGcd) % n2DivGcd) * modInv((rModX / gcdMod), n2DivGcd))
                    % n2DivGcd;
            long hitSteps = r1 + rModX * k;
            hitSteps = hitSteps % lcm;
            if (hitSteps <= 0)
                hitSteps += lcm;

            if (hitSteps < bestT || (hitSteps == bestT && i < bestAstIndex)) {
                bestT = hitSteps;
                bestAstIndex = i;
            }
        }

        return bestAstIndex;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int Q = Integer.parseInt(st.nextToken());
            int[][] ast = new int[K][2];
            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());
                ast[j][0] = Integer.parseInt(st.nextToken());
                ast[j][1] = Integer.parseInt(st.nextToken());
            }
            System.out.println(solve(K, N, M, P, Q, ast));
        }
    }
}
