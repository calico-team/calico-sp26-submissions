import java.io.*;
import java.util.*;


public class ttt {

    public static void main(String[] args) {
        InputBuffer input = new InputBuffer(System.in);
        OutputReporter reporter = new OutputReporter(System.out);

        try {
            int taskCount = input.nextInt();
            while (taskCount-- > 0) {
                ProcessingContext context = new ProcessingContext(
                        input.nextLong(),
                        input.nextInt(),
                        input.nextInt()
                );

                SpatialLayout layout = LayoutEngine.assemble(context);
                reporter.log(layout);
            }
        } catch (Exception e) {

        } finally {
            reporter.close();
        }
    }
}

class ProcessingContext {
    final long seed;
    final int alpha, beta;

    ProcessingContext(long s, int a, int b) {
        this.seed = s;
        this.alpha = a;
        this.beta = b;
    }
}

class LayoutEngine {
    private static final int GRID_HEIGHT = 3;

    public static SpatialLayout assemble(ProcessingContext ctx) {
        int totalNodes = ctx.alpha + ctx.beta;


        if (totalNodes == 0) {
            return new SpatialLayout(GRID_HEIGHT, 1, new char[][]{{'1',' ','1'},{'>'}});
        }

        int[] baseSequence = generateBaseSequence(ctx.alpha, ctx.beta);
        int[] magnitudeMap = computeMagnitudes(ctx.seed, baseSequence, ctx.alpha, ctx.beta);

        return constructTopology(baseSequence, magnitudeMap);
    }

    private static int[] generateBaseSequence(int a, int b) {
        int[] seq = new int[a + b];
        for (int i = 0; i < a; i++) seq[i] = 2;
        for (int i = a; i < a + b; i++) seq[i] = 3;
        return seq;
    }

    private static int[] computeMagnitudes(long val, int[] bases, int a, int b) {
        int[] mags = new int[bases.length];
        long currentVal = val;
        int remA = a, remB = b;

        for (int i = 0; i < bases.length; i++) {
            if (bases[i] == 2) remA--;
            else remB--;

            long threshold = calculateThreshold(remA, remB, currentVal);
            int digit = (int) Math.min(bases[i] - 1L, currentVal / threshold);
            mags[i] = digit;
            currentVal -= (long) digit * threshold;
        }
        return mags;
    }

    private static long calculateThreshold(int a, int b, long cap) {
        long limit = cap + 1;
        long res = 1;
        for (int i = 0; i < a; i++) {
            if (res > limit / 2) return limit;
            res <<= 1;
        }
        for (int i = 0; i < b; i++) {
            if (res > limit / 3) return limit;
            res *= 3;
        }
        return Math.min(res, limit);
    }

    private static SpatialLayout constructTopology(int[] bases, int[] digits) {
        int columns = 2 * bases.length + 1;
        char[][] mesh = new char[GRID_HEIGHT][columns];
        for (char[] row : mesh) Arrays.fill(row, '.');


        mesh[0][0] = 'v';
        mesh[1][0] = '>';

        for (int i = 0; i < bases.length; i++) {
            int x = 2 * i + 1;
            int k = bases[i];
            int d = digits[i];

            mesh[1][x] = 'S';


            if (i + 1 < bases.length) mesh[1][x + 1] = '>';
            else mesh[1][x + 1] = 'X';


            if (k == 2) {
                if (d == 1) mesh[0][x] = '^';
                else mesh[2][x] = 'X';
            } else {
                mesh[0][x] = (d >= 1) ? '^' : 'X';
                mesh[2][x] = (d == 2) ? 'v' : 'X';
            }
        }
        return new SpatialLayout(GRID_HEIGHT, columns, mesh);
    }
}

class SpatialLayout {
    final int h, w;
    final char[][] data;

    SpatialLayout(int h, int w, char[][] data) {
        this.h = h;
        this.w = w;
        this.data = data;
    }
}

class InputBuffer {
    private final BufferedReader reader;
    private StringTokenizer tokens;

    InputBuffer(InputStream is) {
        reader = new BufferedReader(new InputStreamReader(is));
    }

    String next() throws IOException {
        while (tokens == null || !tokens.hasMoreElements()) {
            String line = reader.readLine();
            if (line == null) return null;
            tokens = new StringTokenizer(line);
        }
        return tokens.nextToken();
    }

    int nextInt() throws IOException { return Integer.parseInt(next()); }
    long nextLong() throws IOException { return Long.parseLong(next()); }
}

class OutputReporter {
    private final PrintWriter writer;

    OutputReporter(OutputStream os) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(os)));
    }

    void log(SpatialLayout layout) {

        if (layout.h == 3) {
            writer.println(layout.h + " " + layout.w);
            for (char[] row : layout.data) {
                writer.println(new String(row));
            }
        } else {
            
            writer.println("1 1");
            writer.println(">");
        }
    }

    void close() { writer.flush(); writer.close(); }
}