import java.io.*;
import java.util.*;

class Solution {
    static long[] ans;
    static int N, M;

    static long[] solve(int n, int m, String[] factory) {
        N = n;
        M = m;
        ans = new long[]{0, 1};
        char[][] grid = new char[n][m];
        for (int i = 0; i < n; i++)
            grid[i] = factory[i].toCharArray();
        find(grid, 0, 0, 1, 1);
        return ans;
    }

    static void find(char[][] grid, int r, int c, long p, long q) {
        if (r < 0 || r >= N || c < 0 || c >= M) {
            long np = ans[0] * q + p * ans[1];
            long nq = ans[1] * q;
            long g = gcd(np, nq);
            ans[0] = np / g;
            ans[1] = nq / g;
            return;
        }
        char ch = grid[r][c];
        if (ch == 'X') return;
        if (ch == '>') { find(grid, r, c+1, p, q); return; }
        if (ch == '<') { find(grid, r, c-1, p, q); return; }
        if (ch == '^') { find(grid, r-1, c, p, q); return; }
        if (ch == 'v') { find(grid, r+1, c, p, q); return; }

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        char[] back = {'v', '^', '>', '<'};
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int nr = r+dr[d], nc = c+dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            char t = grid[nr][nc];
            if (t != '.' && t != 'S' && t != back[d]) cnt++;
        }
        for (int d = 0; d < 4; d++) {
            int nr = r+dr[d], nc = c+dc[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            char t = grid[nr][nc];
            if (t != '.' && t != 'S' && t != back[d]) find(grid, nr, nc, p, q*cnt);
        }
    }

    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int T = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            String[] factory = new String[n];
            for (int i = 0; i < n; i++) factory[i] = br.readLine();
            long[] res = solve(n, m, factory);
            pw.println(res[0] + " " + res[1]);
        }
        pw.flush();
    }
}
