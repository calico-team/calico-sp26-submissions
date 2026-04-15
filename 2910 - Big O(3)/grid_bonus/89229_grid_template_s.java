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

        Arrays.sort(A);
        int median;
        if (N % 2 == 1) {
            median = A[N / 2];
            for (int i = 0; i < N; i++) {
                B[i] = median;
            }
        } else {
            median = (A[N / 2 - 1] + A[N / 2]) / 2;
            for (int i = 0; i < N; i++) {
                B[i] = A[i];
            }
        }

        return B;
        // int[] B = new int[N];
        // int r1 = 0;
        // for(int i = 0; i < N-1; i++) {
        //     r1 += Math.abs(A[i+1]-A[i]);
        // }

        // int minScore = Integer.MAX_VALUE;
        // switch (N) {
        //     case 1:
        //         for(int i = 0; i <= 1000000; i++) {
        //             if (Math.abs(A[0] - i) < r1) {
        //                 B[0] = i;
        //             }
        //         }
        //         break;
        //     case 2:
        //         for(int b = 0; b <= 1000000; b++) {
        //             for(int c = 0; c <= 1000000; c++) {
        //                 int r2 = Math.abs(b-c);
        //                 if (r1+r2+Math.abs(b-A[0]) + Math.abs(c-A[1]) < minScore) {
        //                     B[0] = b;
        //                     B[1] = c;
        //                     minScore = r1+r2+Math.abs(b-A[0]) + Math.abs(c-A[1]);
        //                 }
        //             }  
        //         }
                
        //         break;
        //     case 3:
        //         for(int b = 0; b <= 1000000; b++) {
        //             for(int c = 0; c <= 1000000; c++) {
        //                 for(int d = 0; d <= 1000000; d++) {
        //                     int r2 = Math.abs(b-c)+Math.abs(c-d);
        //                     if (r1+r2+Math.abs(b-A[0]) + Math.abs(c-A[1]) + Math.abs(d-A[2]) < minScore) {
        //                         B[0] = b;
        //                         B[1] = c;
        //                         B[2] = d;
        //                         minScore = r1+r2+Math.abs(b-A[0]) + Math.abs(c-A[1]) + Math.abs(d-A[2]);
        //                     }
        //                 }
        //             }  
        //         }

        //         break;
        // }
        // return B;
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
