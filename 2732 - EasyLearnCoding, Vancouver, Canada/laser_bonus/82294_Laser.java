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

            // read in the asteroids and map their positions for O(1) lookup
            Map<Long, Integer> lazarbeam = new HashMap<>();
            for (int i = 0; i < K; i++) {
                ax[i] = sc.nextInt();
                ay[i] = sc.nextInt();
                // encode (x, y) as a single long so we can use it as a map key
                // y * N + x works as long as x < N, which is guaranteed
                lazarbeam.put((long) ay[i] * N + ax[i], i);
            }

            // the laser starts at asteroid 0's position
            long startX = ax[0];
            long startY = ay[0];

            // figure out how many steps before the laser loops back to the start
            // x cycles with period N/gcd(N,Q), y cycles with period M/gcd(M,P)
            // the laser's full period is the lcm of those two
            long periodX = N / gcd(N, Q);
            long periodY = M / gcd(M, P);
            long period = lcm(periodX, periodY);

            long cx = startX;
            long cy = startY;

            // walk the laser one step at a time
            // we start from step 1 because the laser doesn't hit its own
            // starting asteroid on step 0 — only if it wraps all the way around
            for (long step = 1; step <= period; step++) {
                cx = (cx + Q) % N;
                cy = (cy + P) % M;

                long key = cy * N + cx;
                if (lazarbeam.containsKey(key)) {
                    System.out.println(lazarbeam.get(key));
                    break;
                }
            }
        }
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    static long lcm(long a, long b) {
        // divide before multiplying to avoid overflow on large inputs
        return a / gcd(a, b) * b;
    }
}