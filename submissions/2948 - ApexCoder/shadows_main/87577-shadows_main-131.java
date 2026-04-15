import java.io.*;

class Solution {
    /**
     * Return the maximal and minimal volume of the shape (in that order)
     *
     * N: max dimensions of shape
     * S1: projection (shadow) in X-Z plane
     * S2: projection (shadow) in Y-Z plane
     */
    static String solve(int N, String[] S1, String[] S2) {
        long maxVol = 0;
        long minVol = 0;
        for (int z = 0; z < N; z++) {
            int a = 0, b = 0;
            for (int x = 0; x < N; x++) {
                if (S1[z].charAt(x) == '#') {
                    a++;
                }
            }
            for (int y = 0; y < N; y++) {
                if (S2[z].charAt(y) == '#') {
                    b++;
                }
            }
            if ((a == 0) != (b == 0)) {
                return "0 0";
            }
            if (a == 0) {
                continue;
            }
            maxVol += (long) a * b;
            minVol += Math.max(a, b);
        }
        return maxVol + " " + minVol;
    }

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(in.readLine());
            String[] S1 = new String[N];
            for (int i = 0; i < N; i++) {
                S1[i] = in.readLine();
            }
            String[] S2 = new String[N];
            for (int i = 0; i < N; i++) {
                S2[i] = in.readLine();
            }
            out.println(solve(N, S1, S2));
        }
        
        out.flush();
        out.close();
        in.close();
    }
}
