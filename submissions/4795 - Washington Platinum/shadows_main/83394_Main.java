import java.io.*;

public class Main {
    
    // speed
    static class FastScanner {
        InputStream in;
        byte[] buf = new byte[1 << 15];
        int head = 0, tail = 0;

        public FastScanner(InputStream in) { this.in = in; }

        public int read() throws IOException {
            if (head >= tail) {
                head = 0;
                tail = in.read(buf, 0, buf.length);
                if (tail <= 0) return -1;
            }
            return buf[head++];
        }

        public int nextInt() throws IOException {
            int c = read();
            while (c <= 32) {
                if (c == -1) return -1;
                c = read();
            }
            int res = 0;
            while (c > 32) {
                res = res * 10 + c - '0';
                c = read();
            }
            return res;
        }

        public void shadow(int N, int[] counts) throws IOException {
            for (int i = 0; i < N; i++) {
                int count = 0;
                int rdChar = 0;
                while (rdChar < N) {
                    if (head >= tail) {
                        head = 0;
                        tail = in.read(buf, 0, buf.length);
                        if (tail <= 0) break;
                    }
                    byte c = buf[head++];
                    if (c == '#') {
                        count++;
                        rdChar++;
                    } else if (c == '.') {
                        rdChar++;
                    }
                }
                counts[i] = count;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        
        int T = in.nextInt(); if (T == -1) return;
        
        StringBuilder sb = new StringBuilder();
        int[] A = new int[1005];
        int[] B = new int[1005];
        
        for (int t = 0; t < T; t++) {
            int N = in.nextInt();
            
            in.shadow(N, A);
            in.shadow(N, B);
            
            long maxB = 0;
            long minB = 0;
            
            for (int i = 0; i < N; i++) {
                maxB += (long) A[i] * B[i];
                minB += Math.max(A[i], B[i]);
            }
            
            sb.append(maxB).append(" ").append(minB).append("\n");
        }
        
        System.out.print(sb.toString());
    }
}