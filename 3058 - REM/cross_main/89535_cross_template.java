import java.io.*;

class Solution {
    /**
     * Create an N x M grid such that every valid cross contains 0-4 exactly once.
     * 
     * N: number of rows in the grid
     * M: number of columns in the grid
     */
    static int[][] solve(int N, int M) {
        int[][] grid=new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int num = 0; num <= 4; num++) {
                    grid[i][j] = num;
                    boolean same = false;
                    if (i >= 2 && i >= 1 && i < M - 1) {
                        if (grid[i-2][j] == num || grid[i-1][j-1] == num || grid[i-1][j] == num || grid[i-1][j+1] == num) {
                            same = true;
                        }
                    }
                    if (!same){
                        break;
                    }
                }
            }
        }
        return grid;
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
