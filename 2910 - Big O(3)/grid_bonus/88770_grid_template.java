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
        int[] B = new int[N];

        int[] C = A.clone();
        Arrays.sort(C);
        int median;
        if (N % 2 == 1) {
            median = C[N / 2];
        } else {
            median = (C[N / 2 - 1] + C[N / 2]) / 2;
        }

        int cost1 = 0;
        for(int i=0; i < N-1; i++) {
            cost1 += Math.abs(A[i]-A[i+1]);
        }

        int cost2 = 0;
        for (int i = 0; i < N; i++) {
            cost2 += Math.abs(A[i] - median);
        }

        int cost3 = 0;
        for(int i = 0; i < N; i++) {
            cost3 += Math.abs(A[i] - C[i]);
        }
        for(int i = 0; i < N-1; i++) {
            cost3 += Math.abs(C[i] - C[i+1]);
        }

        if (cost1 <= cost2 && cost1 <= cost3) {
            for (int i = 0; i < N; i++) {
                B[i] = A[i];
            }
        } else if (cost2 <= cost1 && cost2 <= cost3) {
            for (int i = 0; i < N; i++) {
                B[i] = median;
            }
        } else {
            for (int i = 0; i < N; i++) {
                B[i] = C[i];
            }
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
