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

    static void dfs(int x, int y, long numerator, long denominator) {
        char c = grid[x][y];

        if (c == 'X') {
            destroy_the_tiles();
            return;
        }
        if (isExit(x, y)) {
            resP = numerator;
            resQ = denominator;
            return;
        }
        if (isConveyor(c)) {
            int[] next = moveConveyor(x, y, c);
            int nx = next[0];
            int ny = next[1];
            dfs(nx, ny, numerator, denominator);
            return;
        }
        if (c == 'S') {
            List<int[]> validTiles = getValidSplitterTiles(x, y);
            int count = validTiles.size();

            for (int[] nextPos : validTiles) {
                int nx = nextPos[0];
                int ny = nextPos[1];
                dfs(nx, ny, numerator, denominator * count);
            }
        }
    }
    static boolean isExit(int x, int y) {
        char c = grid[x][y];
        if (c == '^' && x == 0) return true;
        if (c == 'v' && x == N - 1) return true;
        if (c == '<' && y == 0) return true;
        if (c == '>' && y == M - 1) return true;
        return false;
    }
    static boolean isConveyor(char c) {
        return c == '^' || c == 'v' || c == '<' || c == '>';
    }

    // 传送带下一步位置
    static int[] moveConveyor(int x, int y, char c) {
        if (c == '^') return new int[]{x - 1, y};
        if (c == 'v') return new int[]{x + 1, y};
        if (c == '<') return new int[]{x, y - 1};
        if (c == '>') return new int[]{x, y + 1};
        return new int[]{x, y};
    }
    static List<int[]> getValidSplitterTiles(int x, int y) {
        List<int[]> valid = new ArrayList<>();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            char neighbor = grid[nx][ny];
            if (neighbor == 'X') {
                valid.add(new int[]{nx, ny});
                continue;
            }
            boolean pointsBack = false;
            if (neighbor == '^' && d == 1) pointsBack = true;
            if (neighbor == 'v' && d == 0) pointsBack = true;
            if (neighbor == '<' && d == 3) pointsBack = true;
            if (neighbor == '>' && d == 2) pointsBack = true;

            if (!pointsBack) {
                valid.add(new int[]{nx, ny});
            }
        }
        return valid;
    }
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    static void destroy_the_tiles() {
    }
    static void read_your_input() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            N = sc.nextInt();
            M = sc.nextInt();
            grid = new char[N][M];

            for (int i = 0; i < N; i++) {
                String line = sc.next();
                grid[i] = line.toCharArray();
            }
            resP = 0;
            resQ = 1;
            dfs(0, 0, 1, 1);
            long g = gcd(resP, resQ);
            long ansP = resP / g;
            long ansQ = resQ / g;

            System.out.println(ansP + " " + ansQ);
        }
        sc.close();
    }
}