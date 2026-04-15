import java.io.*;
import java.util.*;

public class crisscross{
    /**
     * Create an N x M grid such that every valid cross contains 0-4 exactly once.
     * 
     * N: number of rows in the grid
     * M: number of columns in the grid
     */
    static int[][] solve(int N, int M) {
        int[][] ans = new int[N][M];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                ans[i][j] = -1;
            }
        }
        for(int i = 0; i < N-2; i++) {
            for(int j = 0; j < M-2; j++) {
                ArrayList<Integer> vals = new ArrayList<Integer>();
                for(int k = 0; k <= 4; k++) vals.add(k);
                for(int k = i; k < i+3; k++) {
                    for(int l = j; l < j+3; l++) {
                        int x = partofcross(i, j, k, l);
                        if(x != -1 && ans[k][l] != -1) vals.remove(Integer.valueOf(ans[k][l]));
                    }
                }
                for(int k = i; k < i+3; k++) {
                    for(int l = j; l < j+3; l++) {
                        int x = partofcross(i, j, k, l);
                        if(x != -1 && ans[k][l] == -1) ans[k][l] = vals.remove(0);
                    }
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(ans[i][j] == -1) ans[i][j] = 0;
            }
        }
        return ans;
    }
    public static int partofcross(int i, int j, int k, int l) {
        if(i == k && j == l) return -1;
        if(k == i+2 && j == l) return -1;
        if(k == i && l == j+2) return -1;
        if(i+2 == k && j+2 == l) return -1;
        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            String[] temp = in.readLine().split(" ");
            int N = Integer.parseInt(temp[0]);
            int M = Integer.parseInt(temp[1]);

            int[][] grid = solve(N, M);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (j > 0) sb.append(' ');
                    sb.append(grid[i][j]);
                }
                sb.append('\n');
            }
            out.print(sb);
        }
        out.flush();
    }
}
