import java.io.*;
import java.util.*;

public class A {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
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
        StringBuilder out = new StringBuilder();

        int t = sc.nextInt();
        while (t-- > 0) {
            int[] A = new int[4];

            for (int i = 0; i < 4; i++) {
                A[i] = sc.nextInt();
            }
            int ans = solve(A);
            out.append(ans).append('\n');
        }

        System.out.print(out);
    }

    static int solve( int[] A) {
        int L = A[0];
        int W = A[1];
        int E = A[2];
        int R = A[3];
        int perm =( L+W)*2;
        return E/(perm*R);
    }
}