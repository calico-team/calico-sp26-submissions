import java.io.*;
import java.util.HashMap;
import java.util.Objects;
import java.util.StringTokenizer;
public class DBonus {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            HashMap<Point, Integer> points = new HashMap<>();
            Point pos = new Point(0, 0);
            long min = Long.MAX_VALUE; int minIndex = 0;
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken()); int y = Integer.parseInt(st.nextToken());
                if(i==0) pos = new Point(x, y);
                points.put(new Point(x, y),i);
                long cur = firstHit(n,m,pos.x,pos.y,x,y,q,p);
                if(cur>0&&cur<min) {
                    min = cur;
                    minIndex = i;
                }
            }
            bw.write(minIndex+"\n");
        }
        bw.flush();
    }
    static class Point {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (o == null || getClass() != o.getClass()) return false;
            Point points = (Point) o;
            return x == points.x && y == points.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
    static long[] egcd(long a, long b) {
        if (b == 0) {
            return new long[]{a, 1, 0};
        }
        long[] res = egcd(b, a % b);
        long g = res[0];
        long x = res[2];
        long y = res[1] - (a / b) * res[2];
        return new long[]{g, x, y};
    }
    static Long modInv(long a, long mod) {
        long[] res = egcd(a, mod);
        long g = res[0];
        long x = res[1];

        if (g != 1) return null;
        return (x % mod + mod) % mod;
    }
    static long firstHit(long n, long m, long x0, long y0, long xt, long yt, long q, long p) {
        long dx = ((xt - x0) % n + n) % n;
        long dy = ((yt - y0) % m + m) % m;
        long gx = gcd(q, n);
        long gy = gcd(p, m);
        if (dx % gx != 0 || dy % gy != 0) return -1;
        long q_ = q / gx, n_ = n / gx, dx_ = dx / gx;
        long p_ = p / gy, m_ = m / gy, dy_ = dy / gy;
        Long invQ = modInv(q_, n_);
        Long invP = modInv(p_, m_);
        long kx = (dx_ * invQ) % n_;
        long ky = (dy_ * invP) % m_;
        long g = gcd(n_, m_);
        if (((kx - ky) % g + g) % g != 0) return -1;
        long lcm = n_ / g * m_;
        long m1_ = n_ / g;
        long m2_ = m_ / g;
        Long inv = modInv(m1_, m2_);
        long t = ((ky - kx) / g % m2_ + m2_) % m2_;
        t = (t * inv) % m2_;
        long k = (kx + n_ * t) % lcm;
        return (k + lcm) % lcm;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
