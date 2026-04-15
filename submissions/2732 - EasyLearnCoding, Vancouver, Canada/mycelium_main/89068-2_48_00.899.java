import java.io.*;
import java.util.*;

public class ucb {

    static class GrowthController {
        int width, height;
        int xOffset, yOffset;
        LongBitset blocked;
        LongBitset isMycelium;

        GrowthController(int xg, int yg, int xm, int ym, int padding) {

            int minX = Math.min(xg, xm) - padding;
            int maxX = Math.max(xg, xm) + padding;
            int minY = Math.min(yg, ym) - padding;
            int maxY = Math.max(yg, ym) + padding;

            this.xOffset = minX;
            this.yOffset = minY;
            this.width = maxX - minX + 1;
            this.height = maxY - minY + 1;

            int totalCapacity = width * height;
            this.blocked = new LongBitset(totalCapacity);
            this.isMycelium = new LongBitset(totalCapacity);
        }

        int getCellId(int x, int y) {
            return (x - xOffset) * height + (y - yOffset);
        }


        void performExpansion(IntList frontier, IntList nextFrontier, IntHashSet seen) {
            for (int i = 0; i < frontier.size; i++) {
                int currentId = frontier.get(i);
                int cx = currentId / height;
                int cy = currentId % height;


                trySpread(cx, cy + 1, nextFrontier, seen); // north
                trySpread(cx, cy - 1, nextFrontier, seen); // south
                trySpread(cx + 1, cy, nextFrontier, seen); // east
                trySpread(cx - 1, cy, nextFrontier, seen); // west
            }
        }

        private void trySpread(int nx, int ny, IntList nextFrontier, IntHashSet seen) {
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                int nid = nx * height + ny;
                if (!blocked.get(nid) && seen.add(nid)) {
                    nextFrontier.add(nid);
                }
            }
        }
    }

    static long solveCase(int xg, int yg, int xm, int ym) {
        int dist = Math.abs(xg - xm) + Math.abs(yg - ym);
        int simulationBuffer = dist + 12;

        GrowthController engine = new GrowthController(xg, yg, xm, ym, simulationBuffer);

        int gStart = engine.getCellId(xg, yg);
        int mStart = engine.getCellId(xm, ym);

        engine.blocked.set(gStart);
        engine.blocked.set(mStart);
        engine.isMycelium.set(mStart);

        IntList grassFrontier = new IntList();
        IntList mycFrontier = new IntList();
        grassFrontier.add(gStart);
        mycFrontier.add(mStart);

        long mycTotalCount = 1;
        int timeStep = 0;


        double maxDensity = (double)engine.width * engine.height;

        while (true) {
            timeStep++;

            IntList potentialGrass = null;
            IntList potentialMyc = null;
            IntHashSet grassSnapshot = null;


            if (timeStep % 2 == 0) {
                potentialGrass = new IntList();
                grassSnapshot = new IntHashSet(Math.max(16, grassFrontier.size * 6));
                engine.performExpansion(grassFrontier, potentialGrass, grassSnapshot);
            }


            if (timeStep % 7 == 0) {
                potentialMyc = new IntList();
                IntHashSet mycSnapshot = new IntHashSet(Math.max(16, mycFrontier.size * 6));
                engine.performExpansion(mycFrontier, potentialMyc, mycSnapshot);
            }


            if (timeStep % 2 == 0 && timeStep % 7 == 0) {
                IntList filteredMyc = new IntList();
                for (int i = 0; i < potentialMyc.size; i++) {
                    int cell = potentialMyc.get(i);
                    if (!grassSnapshot.contains(cell)) {
                        filteredMyc.add(cell);
                    }
                }
                potentialMyc = filteredMyc;
            }


            if (timeStep % 2 == 0) {
                for (int i = 0; i < potentialGrass.size; i++) {
                    engine.blocked.set(potentialGrass.get(i));
                }
                grassFrontier = potentialGrass;
            }


            if (timeStep % 7 == 0) {
                for (int i = 0; i < potentialMyc.size; i++) {
                    int cell = potentialMyc.get(i);
                    engine.blocked.set(cell);
                    engine.isMycelium.set(cell);
                }
                mycTotalCount += potentialMyc.size;
                mycFrontier = potentialMyc;


                if (potentialMyc.isEmpty()) break;
            }


            double currentCoverage = mycTotalCount / maxDensity;
        }

        return mycTotalCount;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder output = new StringBuilder();

        int t = fs.nextInt();
        while (t-- > 0) {
            int xg = fs.nextInt(), yg = fs.nextInt();
            int xm = fs.nextInt(), ym = fs.nextInt();
            output.append(solveCase(xg, yg, xm, ym)).append('\n');
        }
        System.out.print(output);
    }



    static class FastScanner {
        private final InputStream is;
        private final byte[] buf = new byte[1 << 16];
        private int p = 0, l = 0;
        FastScanner(InputStream s) { is = s; }
        private int read() throws IOException {
            if (p >= l) { l = is.read(buf); p = 0; if (l <= 0) return -1; }
            return buf[p++];
        }
        int nextInt() throws IOException {
            int c = read();
            while (c != -1 && c <= 32) c = read();
            int s = 1;
            if (c == '-') { s = -1; c = read(); }
            int v = 0;
            while (c > 32) { v = v * 10 + (c - '0'); c = read(); }
            return v * s;
        }
    }

    static class IntList {
        int[] data = new int[16];
        int size = 0;
        void add(int x) {
            if (size == data.length) data = Arrays.copyOf(data, data.length << 1);
            data[size++] = x;
        }
        int get(int i) { return data[i]; }
        boolean isEmpty() { return size == 0; }
    }

    static class IntHashSet {
        int[] table;
        boolean[] used;
        int mask, size;
        IntHashSet(int cap) {
            int n = 1; while (n < cap) n <<= 1;
            table = new int[n]; used = new boolean[n]; mask = n - 1;
        }
        boolean add(int x) {
            int i = mix(x) & mask;
            while (used[i]) {
                if (table[i] == x) return false;
                i = (i + 1) & mask;
            }
            used[i] = true; table[i] = x; size++; return true;
        }
        boolean contains(int x) {
            int i = mix(x) & mask;
            while (used[i]) {
                if (table[i] == x) return true;
                i = (i + 1) & mask;
            }
            return false;
        }
        private int mix(int x) {
            x ^= (x >>> 16); x *= 0x7feb352d; x ^= (x >>> 15);
            x *= 0x846ca68b; x ^= (x >>> 16); return x;
        }
    }

    static class LongBitset {
        long[] words;
        LongBitset(int n) { words = new long[(n + 63) >> 6]; }
        boolean get(int i) { return ((words[i >> 6] >>> (i & 63)) & 1L) != 0; }
        void set(int i) { words[i >> 6] |= (1L << (i & 63)); }
    }
}