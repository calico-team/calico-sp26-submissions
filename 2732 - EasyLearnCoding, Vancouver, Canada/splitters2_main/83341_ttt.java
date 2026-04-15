import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class ttt {

    public static void main(String[] args) {
        try {
            CoreEngine engine = new CoreEngine(System.in, System.out);
            engine.execute();
        } catch (Exception e) {

        }
    }
}

class CoreEngine {
    private final FastScanner reader;
    private final PrintWriter writer;

    CoreEngine(InputStream in, OutputStream out) {
        this.reader = new FastScanner(in);
        this.writer = new PrintWriter(out);
    }

    public void execute() throws IOException {
        int workload = reader.nextInt();
        while (workload-- > 0) {
            BigInteger seed = new BigInteger(reader.next());
            int alpha = reader.nextInt();
            int beta = reader.nextInt();

            TemporalState state = computeStates(seed, alpha, beta);
            renderLayout(state);
        }
        writer.flush();
    }

    private TemporalState computeStates(BigInteger val, int a, int b) {
        List<SignalNode> nodes = new ArrayList<>();
        BigInteger current = val;

        while ((a > 0 || b > 0) && current.signum() != 0) {
            BigInteger threshold = BigInteger.valueOf(2).pow(a).multiply(BigInteger.valueOf(3).pow(b));
            if (current.equals(threshold)) break;

            if (a > 0) {
                BigInteger bitShift = current.shiftLeft(1);
                int flag = bitShift.compareTo(threshold) < 0 ? 0 : 1;
                nodes.add(new SignalNode(2, flag));
                current = (flag == 0) ? bitShift : bitShift.subtract(threshold);
                a--;
            } else {
                BigInteger tri = current.multiply(BigInteger.valueOf(3));
                int quotient = tri.divide(threshold).intValue();
                nodes.add(new SignalNode(3, quotient));
                current = tri.subtract(threshold.multiply(BigInteger.valueOf(quotient)));
                b--;
            }
        }

        boolean terminalActive = current.signum() != 0;
        return new TemporalState(nodes, terminalActive);
    }

    private void renderLayout(TemporalState state) {
        int length = state.signals.size();
        int cols = 2 * length + 2;
        int rows = 5;


        char[] buffer = new char[rows * cols];
        Arrays.fill(buffer, '.');


        buffer[0 * cols + 0] = 'v';
        buffer[1 * cols + 0] = 'v';
        buffer[2 * cols + 0] = '>';
        if (cols > 1) buffer[2 * cols + 1] = '>';


        for (int i = 0; i < length; i++) {
            SignalNode s = state.signals.get(i);
            int x = 2 + (2 * i);
            buffer[2 * cols + x] = 'S';
            if (x + 1 < cols) buffer[2 * cols + (x + 1)] = '>';

            if (s.type == 2) {
                buffer[1 * cols + x] = (s.magnitude == 1) ? '^' : 'X';
                if (s.magnitude == 1) buffer[0 * cols + x] = '^';
            } else {
                buffer[1 * cols + x] = (s.magnitude >= 1) ? '^' : 'X';
                if (s.magnitude >= 1) buffer[0 * cols + x] = '^';
                buffer[3 * cols + x] = (s.magnitude >= 2) ? 'v' : 'X';
                if (s.magnitude >= 2) buffer[4 * cols + x] = 'v';
            }
        }


        buffer[2 * cols + (cols - 1)] = state.isActive ? '>' : 'X';


        writer.println(rows + " " + cols);
        for (int r = 0; r < rows; r++) {
            writer.println(new String(buffer, r * cols, cols));
        }
    }

    private static class SignalNode {
        int type, magnitude;
        SignalNode(int t, int m) { this.type = t; this.magnitude = m; }
    }

    private static class TemporalState {
        List<SignalNode> signals;
        boolean isActive;
        TemporalState(List<SignalNode> s, boolean a) { this.signals = s; this.isActive = a; }
    }

    private static class FastScanner {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreElements()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    return null;
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
    }
}