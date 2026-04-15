import java.util.*;
import java.io.*;

public class problem4 {
	static class Asteroid {
	        long x, y;
	        int idx;
	        Asteroid(long x, long y, int idx) {
	            this.x = x;
	            this.y = y;
	            this.idx = idx;
	        }
	    }

	    
	    static long[] extGcd(long a, long b) {
	        if (b == 0) return new long[]{a, 1, 0};
	        long[] res = extGcd(b, a % b);
	        long g = res[0], x = res[2], y = res[1] - (a / b) * res[2];
	        return new long[]{g, x, y};
	    }

	    
	    static long modInv(long a, long m) {
	        long[] g = extGcd(a, m);
	        if (g[0] != 1) return -1;
	        return (g[1] % m + m) % m;
	    }

	    
	    static long[] crt(long a1, long m1, long a2, long m2) {
	        long[] g = extGcd(m1, m2);
	        long gcd = g[0];
	        if ((a2 - a1) % gcd != 0) return new long[]{-1, -1};
	        long lcm = m1 / gcd * m2;
	        long x = (a1 + (a2 - a1) / gcd * g[1] % (m2 / gcd) * m1) % lcm;
	        if (x < 0) x += lcm;
	        return new long[]{x, lcm};
	    }

	    public static void main(String[] args) throws IOException {
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        int T = Integer.parseInt(br.readLine());
	        while (T-- > 0) {
	            StringTokenizer st = new StringTokenizer(br.readLine());
	            int K = Integer.parseInt(st.nextToken());
	            long N = Long.parseLong(st.nextToken());
	            long M = Long.parseLong(st.nextToken());
	            long P = Long.parseLong(st.nextToken());
	            long Q = Long.parseLong(st.nextToken());

	            Asteroid[] asteroids = new Asteroid[K];
	            long x0 = 0, y0 = 0;
	            for (int i = 0; i < K; i++) {
	                st = new StringTokenizer(br.readLine());
	                long x = Long.parseLong(st.nextToken());
	                long y = Long.parseLong(st.nextToken());
	                asteroids[i] = new Asteroid(x, y, i);
	                if (i == 0) {
	                    x0 = x;
	                    y0 = y;
	                }
	            }

	            long minT = Long.MAX_VALUE;
	            int ansIdx = -1;

	            
	            long invQ = modInv(Q, N);
	            long invP = modInv(P, M);

	            for (Asteroid ast : asteroids) {
	                long xi = ast.x;
	                long yi = ast.y;

	                
	                long dx = (xi - x0) % N;
	                if (dx < 0) dx += N;
	                long dy = (yi - y0) % M;
	                if (dy < 0) dy += M;

	                
	                long t1 = (dx * invQ) % N;
	                long t2 = (dy * invP) % M;

	                
	                long[] crtRes = crt(t1, N, t2, M);
	                if (crtRes[0] == -1) continue;
	                long t = crtRes[0];
	                long lcm = crtRes[1];

	                
	                if (t == 0) t = lcm;

	                
	                if (t < minT) {
	                    minT = t;
	                    ansIdx = ast.idx;
	                }
	            }

	            System.out.println(ansIdx);
	        }
	        br.close();
	    }
	}
