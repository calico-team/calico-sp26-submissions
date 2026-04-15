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
        if (N == 0) {
            return "0 0";
        }
        if (S1 == null || S2 == null || S1.length < N || S2.length < N) {
            return "0 0";
        }
        long maxVolume = 0;
        long minVolume = 0;
        for (int z = 0; z < N; z++) {
            if (S1[z] == null || S2[z] == null) {
                return "0 0";
            }
            if (S1[z].length() != N || S2[z].length() != N) {
                return "0 0";
            }
            int countXz = 0;
            int countYz = 0;
            for (int x = 0; x < N; x++) {
                if (S1[z].charAt(x) == '#') {
                    countXz++;
                }
            }
            for (int y = 0; y < N; y++) {
                if (S2[z].charAt(y) == '#') {
                    countYz++;
                }
            }
            if ((countXz == 0) != (countYz == 0)) {
                return "0 0";
            }
            if (countXz == 0) {
                continue;
            }
            maxVolume += (long) countXz * countYz;
            minVolume += Math.max(countXz, countYz);
        }
        return maxVolume + " " + minVolume;
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
