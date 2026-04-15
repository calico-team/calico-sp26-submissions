import java.io.*;
import java.util.*;

class Solution {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        long[] L = new long[N];
        long[] R = new long[N];

        L[0] = A[0];
        R[0] = A[0];
        for (int i = 1; i < N; i++) {
            long ai = A[i];
            long l = L[i - 1], r = R[i - 1];
            if (ai < l) {
                L[i] = ai;
                R[i] = l;
            }
            else if (ai > r) {
                L[i] = r;
                R[i] = ai;
            }
            else {
                R[i] = ai;
                L[i] = ai;
            }
        }
 
        int[] B = new int[N];
        B[N - 1] = (int) L[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            B[i] = (int) Math.max(L[i], Math.min(R[i], (long) B[i + 1]));
        }
        return B;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int T = (int) in.nval;
        for (int t = 0; t < T; t++) {
            in.nextToken(); int N = (int) in.nval;
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                in.nextToken();
                A[i] = (int) in.nval;
            }
            int[] result = solve(N, A);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(' ');
                sb.append(result[i]);
            }
            pw.println(sb);
        }
        pw.flush();
    }
}
