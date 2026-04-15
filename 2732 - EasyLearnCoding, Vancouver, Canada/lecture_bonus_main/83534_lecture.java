import java.io.*;
import java.util.*;


public class lecture {

    public static void main(String[] args) throws Exception {
        SpatialService service = new SpatialService();
        service.processQueue();
    }
}

class SpatialService {
    private final FastDataPipeline pipeline;
    private final PrintWriter reporter;

    SpatialService() {
        this.pipeline = new FastDataPipeline(System.in);
        this.reporter = new PrintWriter(System.out);
    }

    public void processQueue() throws IOException {
        int batches = pipeline.readInteger();
        while (batches-- > 0) {
            int h = pipeline.readInteger();
            int w = pipeline.readInteger();
            int limit = pipeline.readInteger();

            byte[][] topology = new byte[h][w];
            for (int i = 0; i < h; i++) {
                String row = pipeline.readToken();
                for (int j = 0; j < w; j++) {
                    topology[i][j] = (byte) (row.charAt(j) == '-' ? 1 : 0);
                }
            }

            OptimizationResult result = performSpatialRefinement(topology, h, w, limit);
            for (Node n : result.getDataset()) {
                reporter.println(n.y + " " + n.x);
            }
        }
        reporter.flush();
    }

    private OptimizationResult performSpatialRefinement(byte[][] map, int h, int w, int q) {

        int dim = h + w;
        int shift = w - 1;
        int[][] integral = new int[dim + 1][dim + 1];

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (map[y][x] == 1) {
                    int p = y + x;
                    int q_coord = y - x + shift;
                    integral[p + 1][q_coord + 1]++;
                }
            }
        }


        for (int i = 1; i <= dim; i++) {
            for (int j = 1; j <= dim; j++) {
                integral[i][j] += integral[i - 1][j] + integral[i][j - 1] - integral[i - 1][j - 1];
            }
        }


        int minBound = 0, maxBound = dim;
        while (minBound < maxBound) {
            int testRadius = (minBound + maxBound) >>> 1;
            if (findViableCluster(integral, testRadius, dim, q) != null) {
                maxBound = testRadius;
            } else {
                minBound = testRadius + 1;
            }
        }

        int[] finalEnvelope = findViableCluster(integral, minBound, dim, q);
        return extractNodes(map, finalEnvelope, h, w, shift, q);
    }

    private int[] findViableCluster(int[][] m, int r, int d, int k) {
        for (int i = 0; i < d; i++) {
            int i2 = Math.min(d - 1, i + r);
            for (int j = 0; j < d; j++) {
                int j2 = Math.min(d - 1, j + r);
                int count = m[i2 + 1][j2 + 1] - m[i][j2 + 1] - m[i2 + 1][j] + m[i][j];
                if (count >= k) return new int[]{i, j, i2, j2};
            }
        }
        return null;
    }

    private OptimizationResult extractNodes(byte[][] grid, int[] env, int H, int W, int s, int k) {
        List<Node> collection = new ArrayList<>(k);
        int p1 = env[0], q1 = env[1], p2 = env[2], q2 = env[3];

        for (int y = 0; y < H && collection.size() < k; y++) {
            int xStart = Math.max(0, Math.max(p1 - y, y - (q2 - s)));
            int xEnd = Math.min(W - 1, Math.min(p2 - y, y - (q1 - s)));

            for (int x = xStart; x <= xEnd && collection.size() < k; x++) {
                if (grid[y][x] == 1) collection.add(new Node(y, x));
            }
        }
        return new OptimizationResult(collection);
    }
}

class Node {
    int y, x;
    Node(int y, int x) { this.y = y; this.x = x; }
}

class OptimizationResult {
    private final List<Node> dataset;
    OptimizationResult(List<Node> d) { this.dataset = d; }
    List<Node> getDataset() { return dataset; }
}

class FastDataPipeline {
    private final InputStream source;
    private final byte[] buffer = new byte[65536];
    private int ptr = 0, len = 0;

    FastDataPipeline(InputStream in) { this.source = in; }

    private int fetch() throws IOException {
        if (ptr >= len) {
            len = source.read(buffer);
            ptr = 0;
            if (len <= 0) return -1;
        }
        return buffer[ptr++];
    }

    public String readToken() throws IOException {
        StringBuilder sb = new StringBuilder();
        int b = fetch();
        while (b != -1 && b <= 32) b = fetch();
        while (b > 32) {
            sb.append((char) b);
            b = fetch();
        }
        return sb.toString();
    }

    public int readInteger() throws IOException {
        int b = fetch();
        while (b != -1 && b <= 32) b = fetch();
        boolean neg = (b == '-');
        if (neg) b = fetch();
        int res = 0;
        while (b >= '0' && b <= '9') {
            res = (res << 3) + (res << 1) + (b - '0');
            b = fetch();
        }
        return neg ? -res : res;
    }
}