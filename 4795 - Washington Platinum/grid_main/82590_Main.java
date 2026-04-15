import java.io.InputStream;
import java.io.PrintWriter;

public class Main {
    
    // speed
    static class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1 << 15];
        private int head = 0, tail = 0;

        public FastScanner(InputStream stream) {
            this.stream = stream;
        }

        private int read() {
            if (head >= tail) {
                head = 0;
                try {
                    tail = stream.read(buf, 0, buf.length);
                } catch (Exception e) {
                    return -1;
                }
                if (tail <= 0) return -1;
            }
            return buf[head++];
        }

        public int nextInt() {
            int c = read();
            while (c <= 32) {
                if (c == -1) return -1;
                c = read();
            }
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int res = 0;
            while (c > 32) {
                if (c >= '0' && c <= '9') {
                    res = res * 10 + c - '0';
                }
                c = read();
            }
            return res * sign;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = sc.nextInt();
        if (T == -1) return;

        while (T-- > 0) {
            int N = sc.nextInt();
            if (N <= 0) continue;
            
            int[] A = new int[N];
            for (int i = 0; i < N; i++) { A[i] = sc.nextInt(); }

            int[] L = new int[N];
            int[] R = new int[N];


            L[0] = A[0];
            R[0] = A[0];

            // forward
            for (int i = 1; i < N; i++) {
                if (A[i] >= L[i - 1] && A[i] <= R[i - 1]) {
                    L[i] = A[i];
                    R[i] = A[i];
                } else if (A[i] < L[i - 1]) {
                    L[i] = A[i];
                    R[i] = L[i - 1];
                } else {
                    L[i] = R[i - 1];
                    R[i] = A[i];
                }
            }

            int[] b = new int[N];
            b[N - 1] = L[N - 1]; 

            // back
            for (int i = N - 2; i >= 0; i--) { b[i] = Math.max(L[i], Math.min(R[i], b[i + 1])); }

            for (int i = 0; i < N; i++) { out.print(b[i] + (i == N - 1 ? "" : " ")); }
            out.println();
        }
        
        out.flush();
    }
}