import java.util.*;

public class Main {
    static char[][] g;
    static int n, m;
    static long p, q;
    public static void main(String[] args) {
        read_your_input();
    }
    static void dfs(int x, int y, long top, long bot) {
        char c = g[x][y];
        if (c == 'X') {
            destroy_the_tiles();
            return;
        }
        if (c == '^' && x == 0) {
            p = top;
            q = bot;
            return;
        }
        if (c == 'v' && x == n-1) {
            p = top;
            q = bot;
            return;
        }
        if (c == '<' && y == 0) {
            p = top;
            q = bot;
            return;
        }
        if (c == '>' && y == m-1) {
            p = top;
            q = bot;
            return;
        }
        if (c == '^') {
            dfs(x-1, y, top, bot);
            return;
        }
        if (c == 'v') {
            dfs(x+1, y, top, bot);
            return;
        }
        if (c == '<') {
            dfs(x, y-1, top, bot);
            return;
        }
        if (c == '>') {
            dfs(x, y+1, top, bot);
            return;
        }
        List<int[]> list = new ArrayList<>();
        int[][] dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int[] d : dir) {
            int nx = x+d[0], ny = y+d[1];
            char ch = g[nx][ny];
            if (ch == 'X') {
                list.add(d);
                continue;
            }
            boolean ok = true;
            if (ch == '^' && d[0] == 1)
                ok = false;
            if (ch == 'v' && d[0] == -1)
                ok = false;
            if (ch == '<' && d[1] == 1)
                ok = false;
            if (ch == '>' && d[1] == -1)
                ok = false;
            if (ok)
                list.add(d);
        }

        int k = list.size();
        for (int[] d : list) {
            dfs(x+d[0], y+d[1], top, bot * k);
        }
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
            n = sc.nextInt();
            m = sc.nextInt();
            g = new char[n][m];
            for (int i = 0; i < n; i++) g[i] = sc.next().toCharArray();
            p = 0; q = 1;
            dfs(0, 0, 1, 1);
            long g = gcd(p, q);
            System.out.println(p/g + " " + q/g);
        }
        sc.close();
    }
}