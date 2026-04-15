import java.io.*;
import java.util.*;

public class Splitters2Submit {
    static void markLeft(char[] row) {
        row[0] = '<';
        row[1] = '<';
        row[2] = '<';
    }

    static void markRight(char[] row) {
        row[4] = '>';
        row[5] = '>';
        row[6] = '>';
    }

    static String[] makeGrid(long p, int a, int b) {
        long[] twos = new long[a + 1];
        long[] threes = new long[b + 1];
        twos[0] = 1;
        threes[0] = 1;
        for (int i = 1; i <= a; i++) {
            twos[i] = twos[i - 1] * 2L;
        }
        for (int i = 1; i <= b; i++) {
            threes[i] = threes[i - 1] * 3L;
        }

        ArrayList<int[]> plan = new ArrayList<>();
        long cur = p;
        int x = a;
        int y = b;

        while (x > 0) {
            long chunk = twos[x - 1] * threes[y];
            int bit = cur >= chunk ? 1 : 0;
            cur -= (long) bit * chunk;
            x--;
            plan.add(new int[] {0, bit});
        }

        while (y > 0) {
            long chunk = threes[y - 1];
            int digit = (int) (cur / chunk);
            cur -= (long) digit * chunk;
            y--;
            plan.add(new int[] {1, digit});
        }

        int height = 2 * plan.size() + 2;
        int width = 7;
        char[][] grid = new char[height][width];
        for (int i = 0; i < height; i++) {
            Arrays.fill(grid[i], '.');
        }

        grid[0][0] = '>';
        grid[0][1] = '>';
        grid[0][2] = '>';
        grid[0][3] = 'v';

        for (int idx = 0; idx < plan.size(); idx++) {
            int[] step = plan.get(idx);
            int kind = step[0];
            int value = step[1];
            int r = 2 * idx + 1;
            boolean last = idx + 1 == plan.size();
            grid[r][3] = 'S';

            if (kind == 0) {
                if (value == 1) {
                    markLeft(grid[r]);
                } else {
                    grid[r][2] = 'X';
                }
            } else {
                if (value >= 1) {
                    markLeft(grid[r]);
                } else {
                    grid[r][2] = 'X';
                }

                if (value == 2) {
                    markRight(grid[r]);
                } else {
                    grid[r][4] = 'X';
                }
            }

            grid[r + 1][3] = 'v';
            if (last) {
                grid[r + 2][3] = 'X';
            }
        }

        String[] out = new String[height];
        for (int i = 0; i < height; i++) {
            out[i] = new String(grid[i]);
        }
        return out;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int t = fs.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int tc = 0; tc < t; tc++) {
            long p = fs.nextLong();
            int a = fs.nextInt();
            int b = fs.nextInt();
            String[] factory = makeGrid(p, a, b);
            sb.append(factory.length).append(' ').append(factory[0].length()).append('\n');
            for (String row : factory) {
                sb.append(row).append('\n');
            }
        }
        System.out.print(sb);
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);
            long sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}