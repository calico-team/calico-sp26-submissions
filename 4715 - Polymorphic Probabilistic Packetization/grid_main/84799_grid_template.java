import java.io.*;

class grid_template {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken();
        int T = (int) in.nval;
        for (int t = 0; t < T; t++) {
            in.nextToken();
            int N = (int) in.nval;
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

    /**
     * Find an array B of N integers representing the filled-in second row, chosen to minimize the sum of absolute
     * differences of adjacent numbers on the grid.
     * <p>
     * N: the number of columns in the 2 x N grid A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        int[] heights = new int[N];
        int[] low = new int[N];
        int[] high = new int[N];

        low[0] = A[0];
        high[0] = A[0];

        for (int i = 1; i < N; i++) {
            int a = A[i];
            if (a >= low[i - 1]) {
                low[i] = Math.min(a, high[i - 1]);
                high[i] = a;
            } else {
                low[i] = a;
                high[i] = low[i - 1];
            }
        }

        heights[N - 1] = low[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            int x = heights[i + 1];
            if (x < low[i]) {
                x = low[i];
            } else {
                if (x > high[i]) x = high[i];
            }
            heights[i] = x;
        }

        return heights;
    }

}
