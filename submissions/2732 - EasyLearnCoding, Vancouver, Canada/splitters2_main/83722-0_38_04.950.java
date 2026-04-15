import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ttt {
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (c >= 0 && c <= 32) c = read();
            if (c == -1) return null;
            while (c > 32) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        int nextInt() throws IOException {
            String s = next();
            return (s == null) ? 0 : Integer.parseInt(s);
        }
    }

    static final BigInteger TWO = BigInteger.valueOf(2);
    static final BigInteger THREE = BigInteger.valueOf(3);

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        String tStr = fs.next();
        if (tStr == null) return;
        int T = Integer.parseInt(tStr);

        while (T-- > 0) {
            BigInteger P = new BigInteger(fs.next());
            int A = fs.nextInt();
            int B = fs.nextInt();
            solve(P, A, B, out);
        }
        out.flush();
    }

    static void solve(BigInteger P, int A, int B, PrintWriter out) {
        BigInteger den = TWO.pow(A).multiply(THREE.pow(B));
        BigInteger num = P;

        List<Integer> bases = new ArrayList<>();
        List<Integer> digits = new ArrayList<>();


        for (int i = 0; i < A; i++) {
            BigInteger t = num.multiply(TWO);
            int d = (t.compareTo(den) >= 0) ? 1 : 0;
            num = t.subtract(den.multiply(BigInteger.valueOf(d)));
            BigInteger g = num.gcd(den);
            num = num.divide(g);
            den = den.divide(g);
            bases.add(2);
            digits.add(d);
        }


        for (int i = 0; i < B; i++) {
            BigInteger t = num.multiply(THREE);
            int d = t.divide(den).intValue();
            num = t.subtract(den.multiply(BigInteger.valueOf(d)));
            BigInteger g = num.gcd(den);
            num = num.divide(g);
            den = den.divide(g);
            bases.add(3);
            digits.add(d);
        }

        int K = bases.size();
        int H = 5;
        int W = K + 2;
        char[][] grid = new char[H][W];
        for (char[] row : grid) Arrays.fill(row, '.');


        grid[2][0] = '>';

        for (int i = 0; i < K; i++) {
            int col = i + 1;
            int b = bases.get(i);
            int d = digits.get(i);
            grid[2][col] = 'S';

            if (b == 2) {
                if (d == 1) { grid[1][col] = '^'; grid[0][col] = '^'; }
                else { grid[1][col] = 'X'; }
            } else {
                if (d >= 1) { grid[1][col] = '^'; grid[0][col] = '^'; }
                else { grid[1][col] = 'X'; }

                if (d == 2) { grid[3][col] = 'v'; grid[4][col] = 'v'; }
                else { grid[3][col] = 'X'; }
            }
        }

        
        int lastCol = W - 1;
        grid[2][lastCol] = (num.signum() > 0) ? '>' : 'X';

        out.println(H + " " + W);
        for (int i = 0; i < H; i++) {
            out.println(new String(grid[i]));
        }
    }
}