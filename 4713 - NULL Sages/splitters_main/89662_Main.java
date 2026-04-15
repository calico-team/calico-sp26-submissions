import java.util.*;

public class Main {
    static int N, M;
    static char[][] grid;
    static long resP, resQ;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        read_your_input();
    }

    static void dfs(int x, int y, long num, long den) {
        char c = grid[x][y];

        if (c == 'X') {
            destroy_the_tiles();
            return;
        }

        if (isExit(x, y)) {
            resP = num;
            resQ = den;
            return;
        }

        if (isConv(c)) {
            int nx = x, ny = y;
            if (c == '^') nx--;
            else if (c == 'v') nx++;
            else if (c == '<') ny--;
            else if (c == '>') ny++;
            dfs(nx, ny, num, den);
            return;
        }

        if (c == 'S') {
            List<int[]> valid = new ArrayList<>();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                char nc = grid[nx][ny];
                if (nc == 'X') {
                    valid.add(new int[]{nx, ny});
                    continue;
                }
                boolean back = false;
                if (nc == '^' && d == 1) back = true;
                if (nc == 'v' && d == 0) back = true;
                if (nc == '<' && d == 3) back = true;
                if (nc == '>' && d == 2) back = true;
                if (!back) valid.add(new int[]{nx, ny});
            }
            int cnt = valid.size();
            for (int[] v : valid) {
                dfs(v[0], v[1], num, den * cnt);
            }
        }
    }

    static boolean isExit(int x, int y) {
        char c = grid[x][y];
        return (c == '^' && x == 0) ||
                (c == 'v' && x == N-1) ||
                (c == '<' && y == 0) ||
                (c == '>' && y == M-1);
    }

    static boolean isConv(char c) {
        return c == '^' || c == 'v' || c == '<' || c == '>';
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static void destroy_the_tiles() {}

    static void read_your_input() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            N = sc.nextInt();
            M = sc.nextInt();
            grid = new char[N][M];
            for (int i = 0; i < N; i++) {
                grid[i] = sc.next().trim().toCharArray();
            }
            resP = 0;
            resQ = 1;
            dfs(0, 0, 1, 1);
            long g = gcd(resP, resQ);
            System.out.println((resP / g) + " " + (resQ / g));
        }
        sc.close();
    }
}