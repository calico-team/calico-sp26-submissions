package lecture.templates;

import java.io.*;
import java.util.*;

class Solution {
    /**
     * M: number of rows in the lecture hall
     * N: number of columns in the lecture hall
     * K: number of friends who need seats
     * GRID: array of M strings of length N; '#' is a blocked seat, '-' is an empty seat
     *
     * Return a list of K int[2] {row, col} for the chosen seats.
     */
    static List<int[]> solve(int M, int N, int K, String[] GRID) {
        int[][] seats = new int[N * M][4];
        int E = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (GRID[i].charAt(j) == '-') {
                    seats[E][0] = i;
                    seats[E][1] = j;
                    seats[E][2] = i + j;
                    seats[E][3] = i - j;
                    E++;
                }
            }
        } List<int[]> group = new ArrayList<>();
        if (E < K) return group;
        int bestDist = Integer.MAX_VALUE;

        for (int center = 0; center < E; center++) {
            int cu = seats[center][2];
            int cv = seats[center][3];
            int[] dist = new int[E];
            for (int i = 0; i < E; i++) {
                int du = seats[i][2] - cu;
                if (du < 0) du = -du;
                int dv = seats[i][3] - cv;
                if (dv < 0) dv = -dv;
                int d = Math.max(du, dv);
                dist[i] = d * E + i;
            } Arrays.sort(dist);
            int maxDist = dist[K - 1] / E;
            if (maxDist < bestDist) {
                bestDist = maxDist;
                group = new ArrayList<>();
                for (int i = 0; i < K; i++) {
                    int idx = dist[i] % E;
                    group.add(new int[]{seats[idx][0], seats[idx][1]});
                }
            }
        } return group;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);
        in.resetSyntax();
        in.wordChars('!', '~');
        in.whitespaceChars(0, ' ');

        in.nextToken(); int T = Integer.parseInt(in.sval);
        for (int t = 0; t < T; t++) {
            in.nextToken(); int M = Integer.parseInt(in.sval);
            in.nextToken(); int N = Integer.parseInt(in.sval);
            in.nextToken(); int K = Integer.parseInt(in.sval);
            String[] GRID = new String[M];
            for (int i = 0; i < M; i++) {
                in.nextToken();
                GRID[i] = in.sval;
            }
            List<int[]> result = solve(M, N, K, GRID);
            for (int[] p : result) {
                pw.println(p[0] + " " + p[1]);
            }
        }
        pw.flush();
    }
}
