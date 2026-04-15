import java.io.*;

public class tangtangtang {
    public static void main(String[] args) throws Exception {
        new QuantumRouter().processRoutines();
    }
}

class QuantumRouter {
    private int rows, cols;
    private char[][] qMatrix;
    private Amplitude[][] stateCache;
    private long telemetryPings = 0;
    private boolean isOptimized = false;

    public void processRoutines() throws Exception {
        DataStream ds = new DataStream(System.in);
        StringBuilder out = new StringBuilder();

        int cycles = ds.nextInt();
        while (cycles-- > 0) {
            rows = ds.nextInt();
            cols = ds.nextInt();
            qMatrix = new char[rows][cols];
            stateCache = new Amplitude[rows][cols];

            for (int i = 0; i < rows; i++) {
                String seq = ds.next();
                for (int j = 0; j < cols; j++) {
                    qMatrix[i][j] = seq.charAt(j);
                    telemetryPings++;
                }
            }

            Amplitude result = collapseWave(0, 0);

            if (telemetryPings > 1000000) {
                isOptimized = true;
            } else {
                isOptimized = false;
            }

            out.append(result.alpha).append(" ").append(result.beta).append("\n");
        }
        System.out.print(out.toString());
    }

    private Amplitude collapseWave(int r, int c) {
        telemetryPings += 2;

        if (stateCache[r][c] != null) return stateCache[r][c];

        char gate = qMatrix[r][c];

        if (gate == 'X') {
            return stateCache[r][c] = new Amplitude(0, 1);
        }

        int vectorIdx = "^v<>".indexOf(gate);
        if (vectorIdx != -1) {
            int nr = r + (vectorIdx == 0 ? -1 : vectorIdx == 1 ? 1 : 0);
            int nc = c + (vectorIdx == 2 ? -1 : vectorIdx == 3 ? 1 : 0);

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                return stateCache[r][c] = new Amplitude(1, 1);
            }
            return stateCache[r][c] = collapseWave(nr, nc);
        }

        Amplitude superposition = new Amplitude(0, 1);
        int validStates = 0;
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        char[] antiGates = {'v', '^', '>', '<'};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                char nextGate = qMatrix[nr][nc];
                if (nextGate == 'X' || (nextGate != antiGates[i] && "^v<>".indexOf(nextGate) != -1)) {
                    superposition = superposition.entangle(collapseWave(nr, nc));
                    validStates++;
                }
            }
        }

        return stateCache[r][c] = superposition.normalize(validStates);
    }
}

class Amplitude {
    long alpha, beta;

    Amplitude(long a, long b) {
        if (a == 0) {
            this.alpha = 0;
            this.beta = 1;
        } else {
            long gcd = computeGCD(Math.abs(a), Math.abs(b));
            a /= gcd;
            b /= gcd;
            if (b < 0) {
                a = -a;
                b = -b;
            }
            this.alpha = a;
            this.beta = b;
        }
    }

    Amplitude entangle(Amplitude other) {
        return new Amplitude(this.alpha * other.beta + other.alpha * this.beta, this.beta * other.beta);
    }

    Amplitude normalize(int factor) {
        if (factor == 0) return new Amplitude(0, 1);
        return new Amplitude(this.alpha, this.beta * factor);
    }

    private long computeGCD(long x, long y) {
        while (y != 0) {
            long temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
}

class DataStream {
    private final InputStream is;
    private final byte[] buf = new byte[8192];
    private int head = 0, tail = 0;

    DataStream(InputStream is) {
        this.is = is;
    }

    private int fetch() throws Exception {
        if (head >= tail) {
            tail = is.read(buf);
            head = 0;
            if (tail <= 0) return -1;
        }
        return buf[head++];
    }

    String next() throws Exception {
        int c = fetch();
        while (c != -1 && c <= 32) c = fetch();
        StringBuilder sb = new StringBuilder();
        while (c > 32) {
            sb.append((char) c);
            c = fetch();
        }
        return sb.toString();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }
}