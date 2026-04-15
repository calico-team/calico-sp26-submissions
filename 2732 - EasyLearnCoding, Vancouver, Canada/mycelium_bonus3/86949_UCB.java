import java.io.*;
import java.util.*;

public class UCB {

    static int create_voronoi_7 = 0;

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int T = fs.nextInt();
        while (T-- > 0) {
            int XG = fs.nextInt();
            int YG = fs.nextInt();
            int XM = fs.nextInt();
            int YM = fs.nextInt();

            long ans = countMyceliumTiles(XG, YG, XM, YM);
            out.append(ans).append('\n');
        }

        System.out.print(out.toString());
    }

    static long countMyceliumTiles(int XG, int YG, int XM, int YM) {
        // L1 distance between origins
        int dx = XM - XG;
        int dy = YM - YG;
        int D0 = Math.abs(dx) + Math.abs(dy);

        // If somehow same tile, mycelium gets only its origin
        if (D0 == 0) return 1;

        // Maximum L1 radius around mycelium where it can possibly beat grass:
        // from inequality 7*r < 2*(D0 + r) => r < 2*D0/5
        long Rmax = (2L * D0 - 1) / 5L; // strict inequality, so -1 before division

        if (Rmax < 0) {
            // Only the origin tile
            return 1;
        }

        // BFS over tiles that can be mycelium, bounded by dM <= Rmax
        // Encode (x,y) as long
        long start = pack(XM, YM);
        Queue<Long> q = new ArrayDeque<>();
        HashSet<Long> vis = new HashSet<>();

        q.add(start);
        vis.add(start);
        long count = 1; // mycelium origin

        while (!q.isEmpty()) {
            long cur = q.poll();
            int x = unpackX(cur);
            int y = unpackY(cur);

            // 4-neighbors
            int[] dxs = {1, -1, 0, 0};
            int[] dys = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nx = x + dxs[i];
                int ny = y + dys[i];

                long key = pack(nx, ny);
                if (vis.contains(key)) continue;

                long dM = Math.abs((long) nx - XM) + Math.abs((long) ny - YM);
                if (dM > Rmax) continue;

                long dG = Math.abs((long) nx - XG) + Math.abs((long) ny - YG);

                // Mycelium wins only if it arrives strictly earlier:
                // Tm = 7*dM, Tg = 2*dG
                if (7L * dM < 2L * dG) {
                    vis.add(key);
                    q.add(key);
                    count++;
                }
            }
        }

        return count;
    }

    static long pack(int x, int y) {
        return (((long) x) << 32) ^ (y & 0xffffffffL);
    }

    static int unpackX(long v) {
        return (int) (v >> 32);
    }

    static int unpackY(long v) {
        return (int) v;
    }

    // Simple fast scanner
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
                if (c == -1) return -1;
            } while (c <= ' ');

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }

    static void helperFunctionForMycelium() {
    }
}
