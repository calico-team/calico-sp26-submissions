import java.io.*;
import java.util.*;

class Main {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
  static int[] solve(int N, int[] A) {
    int[] b = new int[N];
    for (int i = 0; i < N; i++) {
        if (N == 1 || i == 0 || i == N - 1) {
            b[i] = A[i];
        } else {    
            int[] choices = {A[i-1], A[i], A[i+1]};
            Arrays.sort(choices);
            b[i] = choices[1];
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
