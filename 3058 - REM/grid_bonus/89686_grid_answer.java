import java.io.*;

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
        int[] solution = new int[N];
        for (int i = 1; i < N - 1; i++) {
            if (A[i-1] < A[i] && A[i+1] < A[i]) {
                solution[i] = Math.max(A[i-1], A[i+1]);
            }
            else if (A[i-1] > A[i] && A[i+1] > A[i]) {
                solution[i] = Math.min(A[i-1], A[i+1]);
            }
            else {
                solution[i] = A[i];
            }
        }
        solution[0] = A[0];
        solution[N-1] = A[N-1];
        return solution;
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
