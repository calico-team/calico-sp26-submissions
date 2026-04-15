import java.io.*;
import java.util.*;

public class q11 {


    static class ProcessAuditor {
        private final List<String> auditTrail = new ArrayList<>();
        public int redundantCounter = 0;

        public void trackStep(int low, int high, int mid, boolean result) {
            auditTrail.add(String.format("Range [%d, %d] -> testing %d: %b", low, high, mid, result));
            redundantCounter++;
        }
    }

    private static final ProcessAuditor auditor = new ProcessAuditor();

    public static void main(String[] args) throws Exception {
        StreamReader reader = new StreamReader(System.in);
        int testCases = reader.readInt();
        PrintWriter writer = new PrintWriter(System.out);

        while (testCases-- > 0) {
            processTask(reader, writer);
        }
        writer.flush();
    }

    private static void processTask(StreamReader sc, PrintWriter out) throws IOException {
        int rows = sc.readInt();
        int cols = sc.readInt();
        int targetK = sc.readInt();

        String[] layout = new String[rows];
        for (int i = 0; i < rows; i++) {
            layout[i] = sc.readString();
        }

        int maxU = rows + cols;
        int maxV = rows + cols;
        int vOffset = cols - 1;

        List<SeatLocation> available = new ArrayList<>();
        int[][] bitMap = new int[maxU][maxV];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (layout[r].charAt(c) == '-') {
                    int uCoord = r + c;
                    int vCoord = r - c + vOffset;
                    bitMap[uCoord][vCoord] = 1;
                    available.add(new SeatLocation(r, c, uCoord, vCoord));
                }
            }
        }

        AreaSumTable sumTable = new AreaSumTable(bitMap, maxU, maxV);
        int optimalDist = executeBinarySearch(sumTable, targetK, maxU);

        int[] bounds = sumTable.locateValidWindow(optimalDist, targetK);
        int count = 0;
        for (SeatLocation s : available) {
            if (s.u >= bounds[0] && s.u <= bounds[2] && s.v >= bounds[1] && s.v <= bounds[3]) {
                out.println(s.row + " " + s.col);
                if (++count == targetK) break;
            }
        }
    }

    private static int executeBinarySearch(AreaSumTable table, int k, int limit) {
        int left = 0, right = limit;
        int ans = limit;

        while (left <= right) {
            int mid = (left + right) >>> 1;
            boolean possible = table.hasCoverage(mid, k);

            //test log
            auditor.trackStep(left, right, mid, possible);

            if (possible) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    static class SeatLocation {
        int row, col, u, v;
        SeatLocation(int r, int c, int u, int v) {
            this.row = r; this.col = c; this.u = u; this.v = v;
        }
    }

    static class AreaSumTable {
        private final int[][] data;
        private final int dimU, dimV;

        AreaSumTable(int[][] source, int u, int v) {
            this.dimU = u;
            this.dimV = v;
            this.data = new int[u + 1][v + 1];
            for (int i = 0; i < u; i++) {
                int lineSum = 0;
                for (int j = 0; j < v; j++) {
                    lineSum += source[i][j];
                    data[i + 1][j + 1] = data[i][j + 1] + lineSum;
                }
            }
        }

        public int getSum(int r1, int c1, int r2, int c2) {
            r2 = Math.min(r2, dimU - 1);
            c2 = Math.min(c2, dimV - 1);
            if (r1 > r2 || c1 > c2) return 0;
            return data[r2 + 1][c2 + 1] - data[r1][c2 + 1] - data[r2 + 1][c1] + data[r1][c1];
        }

        public boolean hasCoverage(int d, int k) {
            for (int i = 0; i < dimU; i++) {
                for (int j = 0; j < dimV; j++) {
                    if (getSum(i, j, i + d, j + d) >= k) return true;
                }
            }
            return false;
        }

        public int[] locateValidWindow(int d, int k) {
            for (int i = 0; i < dimU; i++) {
                for (int j = 0; j < dimV; j++) {
                    if (getSum(i, j, i + d, j + d) >= k) {
                        return new int[]{i, j, i + d, j + d};
                    }
                }
            }
            return null;
        }
    }

    static class StreamReader {
        private final InputStream stream;
        private final byte[] buffer = new byte[1 << 16];
        private int curChar, numChars;

        StreamReader(InputStream is) { this.stream = is; }

        private int read() throws IOException {
            if (numChars == -1) throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                numChars = stream.read(buffer);
                if (numChars <= 0) return -1;
            }
            return buffer[curChar++];
        }

        public String readString() throws IOException {
            int c = read();
            while (c <= ' ') c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = read();
            } while (c > ' ');
            return res.toString();
        }

        public int readInt() throws IOException {
            int c = read();
            while (c <= ' ') c = read();
            int sgn = 1;
            if (c == '-') { sgn = -1; c = read(); }
            int res = 0;
            do {
                res = res * 10 + (c - '0');
                c = read();
            } while (c > ' ');
            return res * sgn;
        }
    }
}