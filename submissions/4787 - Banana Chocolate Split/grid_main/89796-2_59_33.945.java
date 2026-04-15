import java.io.*;
import java.util.*;

class Solution {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid (for tier 2 always 3)
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        int sumV1 = 0;
        int sumAH1 = 0;
        int sumBH1 = 0;
        int totalSum = 0;
        int totalSum2 = 0;
        int totalSum3 = 0;
        int totalSum4 = 0;
        int finalSum = 0;

        if (N == 1) {
            return new int[]{A[0]};
        }

        if (N == 2) {
            int[] B2 = {A[0], A[1]};
            for (int i = 0; i < A.length; i++) {
                sumV1 += Math.abs(A[i] - B2[i]);
                sumAH1 = Math.abs(A[0] - A[1]);
            }
            totalSum = sumV1 + sumAH1;
            sumV1 = 0;
            sumAH1 = 0;

            int[] B3 = {A[0], A[0]};
            for (int i = 0; i < A.length; i++) {
                sumV1 += Math.abs(A[i] - B3[i]);
                sumAH1 = Math.abs(A[0] - A[1]);
            }
            totalSum2 = sumV1 + sumAH1;
            sumV1 = 0;
            sumAH1 = 0;

            int[] B4 = {A[1], A[1]};
            for (int i = 0; i < A.length; i++) {
                sumV1 += Math.abs(A[i] - B4[i]);
                sumAH1 = Math.abs(A[0] - A[1]);
            }
            totalSum3 = sumV1 + sumAH1;
            if (Math.min(totalSum1, totalSum2) == totalSum1) {
                return B2;
            } else if (Math.min(totalSum2, totalSum3) == totalSum2) {
                return B3;
            } else {
                return B4;
        }

        int[] B5 = {A[0], A[1], A[2]};
        for (int i = 0; i < A.length; i++) {
            sumV1 += Math.abs(A[i] - B5[i]);
            sumAH1 = Math.abs(A[0] - A[1]) + Math.abs(A[1] - A[2]);
            sumBH1 = Math.abs(B5[0] - B5[1]) + Math.abs(B5[1] - B5[2]);
        }
        totalSum = sumV1 + sumAH1 + sumBH1;

        int[] B6 = {A[0], A[0], A[0]};
        sumV1 = 0;
        sumAH1 = 0;
        sumBH1 = 0;
        for (int i = 0; i < A.length; i++) {
            sumV1 += Math.abs(A[i] - B6[i]);
            sumAH1 = Math.abs(A[0] - A[1]) + Math.abs(A[1] - A[2]);
            sumBH1 = Math.abs(B6[0] - B6[1]) + Math.abs(B6[1] - B6[2]);
        }
        totalSum2 = sumV1 + sumAH1 + sumBH1;

        int[] B7 = {A[1], A[1], A[1]};
        sumV1 = 0;
        sumAH1 = 0;
        sumBH1 = 0;
        for (int i = 0; i < A.length; i++) {
            sumV1 += Math.abs(A[i] - B7[i]);
            sumAH1 = Math.abs(A[0] - A[1]) + Math.abs(A[1] - A[2]);
            sumBH1 = Math.abs(B7[0] - B7[1]) + Math.abs(B7[1] - B7[2]);
        }
        totalSum3 = sumV1 + sumAH1 + sumBH1;

        int[] B8 = {A[2], A[2], A[2]};
        sumV1 = 0;
        sumAH1 = 0;
        sumBH1 = 0;
        for (int i = 0; i < A.length; i++) {
            sumV1 += Math.abs(A[i] - B8[i]);
            sumAH1 = Math.abs(A[0] - A[1]) + Math.abs(A[1] - A[2]);
            sumBH1 = Math.abs(B8[0] - B8[1]) + Math.abs(B8[1] - B8[2]);
        }
        totalSum4 = sumV1 + sumAH1 + sumBH1;

        if (Math.min(totalSum, Math.min(totalSum2, Math.min(totalSum3, totalSum4))) == totalSum) {
            return B;
        } else if (Math.min(totalSum2, Math.min(totalSum3, totalSum4)) == totalSum2) {
            return B2;
        } else if (Math.min(totalSum3, totalSum4) == totalSum3) {
            return B3;
        } else {
            return B4;
        }
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
