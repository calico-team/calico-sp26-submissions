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
             int[] sorted = new int[N];
             for (int i = 0; i < N; i++) {
                 sorted[i] = A[i];
             }
             Arrays.sort(sorted);
             int med = sorted[N / 2];

             long cost1 = 0;
             for (int i = 0; i < N - 1; i++) {
                 long d = A[i] - A[i + 1];
                 if (d < 0) {
                     cost1 = cost1 - d;
                 } else {
                     cost1 = cost1 + d;
                 }
             }

             long cost2 = 0;
             for (int i = 0; i < N; i++) {
                 long d = A[i] - med;
                 if (d < 0) {
                     cost2 = cost2 - d;
                 } else {
                     cost2 = cost2 + d;
                 }
             }

             int[] b = new int[N];
             if (cost1 < cost2) {
                 for (int i = 0; i < N; i++) {
                     b[i] = A[i];
                 }
             } else {
                 for (int i = 0; i < N; i++) {
                     b[i] = med;
                 }
             }
             return b;
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
