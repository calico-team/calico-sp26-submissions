import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class P4 { 
    static FastIO io = new FastIO();

    public static void main(String[] args) throws Exception {
        int numTests = io.nextInt();
        while (numTests-- > 0) {
            solve();
        }
    }

    static void solve() throws Exception {
        int k = io.nextInt();
        int n = io.nextInt();
        int m = io.nextInt();
        int p = io.nextInt();
        int q = io.nextInt();

        var x = new int[k];
        var y = new int[k];
        x[0] = io.nextInt();
        y[0] = io.nextInt();
        for (int i=1; i<k; i++) {
            x[i] = io.nextInt()-x[0];
            y[i] = io.nextInt()-y[0];
        }
        x[0] = 0;
        y[0] = 0;

        var set = new HashSet<Point>();
        for (int i=0; i<k; i++) {
            set.add(new Point(x[i], y[i]));
        }

        // System.out.println("x = " + Arrays.toString(x));
        // System.out.println("y = " + Arrays.toString(y));

        int curX = q, curY = p;
        for (int t=1; t<=n*m; t++) {
            var cur = new Point(curX, curY);
            if (set.contains(cur)) {
                break;
            }
            curX = (curX + q)%n;
            curY = (curY + p)%m;
        }

        for (int i=0; i<k; i++) {
            if (x[i] == curX && y[i] == curY) {
                System.out.println(i);
                return;
            }
        }
    }

    record Point(int x, int y) {}



























    // ==================================================================
    // ======================== Boilerplate Code v2.1 ===================
    // ==================================================================
    static class FastIO {
        private static final int BUF_SIZE = 1 << 20;
        private final InputStream in;
        public final PrintWriter out;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr = 0, buflen = 0;
        private final StringBuilder sb = new StringBuilder(BUF_SIZE);

        public FastIO() { // default to stdin/stdout
            in = System.in;
            out = new PrintWriter(new BufferedOutputStream(System.out, BUF_SIZE),true); 
            // Note: autoFlushing on newlines can be disabled for better perf, just remember to manually flush yourself!!
        }

        public FastIO(String inputFile, String outputFile) {
            try {
                in  = new FileInputStream(inputFile);
                out = new PrintWriter(new BufferedOutputStream(new FileOutputStream(outputFile), BUF_SIZE), true);
            } catch (IOException e) { throw new UncheckedIOException(e); }
        }

        private byte read() throws IOException {
            if (ptr >= buflen) {
                buflen = in.read(buf, 0, BUF_SIZE);
                ptr = 0;
                if (buflen == -1) return -1;
            }
            return buf[ptr++];
        }

        public int nextInt() throws IOException {
            byte b; do { b = read(); } while (b != -1 && b <= ' ');
            if (b == -1) throw new IOException("End of input");
            boolean neg = (b == '-'); if (neg) b = read();
            int x = 0;
            while (b >= '0' && b <= '9') {
                x = x * 10 + (b - '0');
                b = read();
            }
            return neg ? -x : x;
        }

        public long nextLong() throws IOException {
            byte b; do { b = read(); } while (b != -1 && b <= ' ');
            if (b == -1) throw new IOException("End of input");
            boolean neg = (b == '-'); if (neg) b = read();
            long x = 0;
            while (b >= '0' && b <= '9') {
                x = x * 10 + (b - '0');
                b = read();
            }
            return neg ? -x : x;
        }

        public double nextDouble() throws IOException { return Double.parseDouble(next()); }

        public char nextChar() throws IOException {
            byte b; do { b = read(); } while (b != -1 && b <= ' ');
            if (b == -1) throw new IOException("End of input");
            return (char) b;
        }

        public String next() throws IOException {
            byte b; do { b = read(); } while (b != -1 && b <= ' ');
            if (b == -1) return null;
            sb.setLength(0);
            do {
                sb.append((char) b);
                b = read();
            } while (b != -1 && b > ' ');
            return sb.toString();
        }

        public String nextLine() throws IOException {
            StringBuilder line = new StringBuilder();
            byte b;
            while ((b = read()) != -1 && b != '\n') {
                if (b != '\r') line.append((char) b);
            }
            return line.toString();
        }

        public int[] nextArrayInt(int n) throws IOException { int[] a = new int[n]; for (int i = 0; i < n; i++) a[i] = nextInt(); return a; }
        public long[] nextArrayLong(int n) throws IOException { long[] a = new long[n]; for (int i = 0; i < n; i++) a[i] = nextLong(); return a; }
        public double[] nextArrayDouble(int n) throws IOException { double[] a = new double[n]; for (int i = 0; i < n; i++) a[i] = nextDouble(); return a; }
        public String[] nextArrayString(int n) throws IOException { String[] a = new String[n]; for (int i = 0; i < n; i++) a[i] = next(); return a; }
    }

    static long gcd(long x, long y) {
        x = Math.abs(x); y = Math.abs(y);
        while (y != 0) {
            long c = x % y;
            x = y;
            y = c;
        }
        return x;
    }

    public static int gcd(int x, int y) {
        x = Math.abs(x); y = Math.abs(y);
        while (y != 0) {
            int c = x % y;
            x = y;
            y = c;
        }
        return x;
    }
    
    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    // Returns the next permutation of [start, end) in ascending. 
    // Will return false when there are none left. Can handle duplicates just fine.
    public static boolean nextPermutation(int[] nums, int start, int end) { 
        for (int i=end-2; i>=start; i--) {
            if (nums[i] < nums[i+1]) {
                int replacement = nums[i+1]; 
                int replacementIndex = i+1;
                for (int j=i+2; j<end; j++) {
                    if (nums[j] > nums[i] && nums[j] <= replacement) {
                        replacement = nums[j];
                        replacementIndex = j;
                    }
                }
                swap(nums, i, replacementIndex);
                reverse(nums, i+1, end);  // sort the tail, which is conveniently reversed
                return true;
            }
        }
        return false;
    }

    public static void reverse(int[] nums, int start, int end) { // swaps [start, end)
        end--;
        while (start < end) {
            swap(nums, start, end);
            start++; 
            end--;
        }
    }
    
    public static void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    // Fisher-Yates shuffle algorithm - Can be used to avoid quicksort's O(N^2) worst case
    public static void arrayShuffle(int[] arr) { 
        Random r = new Random();
        for (int i=arr.length-1; i>=1; i--) {
            int inx = r.nextInt(i+1);
            int t = arr[inx];
            arr[inx] = arr[i];
            arr[i] = t;
        }
    }

    public static void arrayShuffle(long[] arr) { 
        Random r = new Random();
        for (int i=arr.length-1; i>=1; i--) {
            int inx = r.nextInt(i+1);
            long t = arr[inx];
            arr[inx] = arr[i];
            arr[i] = t;
        }
    }

    public static void arrayShuffle(double[] arr) { 
        Random r = new Random();
        for (int i=arr.length-1; i>=1; i--) {
            int inx = r.nextInt(i+1);
            double t = arr[inx];
            arr[inx] = arr[i];
            arr[i] = t;
        }
    }

    static long modpow(long a, long b, long mod) { // a^b % mod (note: 0^0 returns 1)
        a %= mod;
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = (ans * a) % mod;
            }
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    }

    // WARNING: Only works for prime MOD. 
    public static long modInverse(long a, long mod) {  
        return modpow(a, mod-2, mod); // fermat's little theorem a^(p-1) = 1(mod p)
    }

    public static int[][] buildGraph(int n, int[][] edges, boolean bidirectional) { // fast adj list builder
        var g = new int[n][];
        int[] outDegree = new int[n];
        for (int[] e : edges) {
            outDegree[e[0]]++;
            if (bidirectional) {
                outDegree[e[1]]++;
            }
        }
        for (int i=0; i<n; i++) {
            g[i] = new int[outDegree[i]];
        }
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            g[u][--outDegree[u]] = v;
            if (bidirectional) {
                g[v][--outDegree[v]] = u;
            }
        }
        return g;
    }

    public static int[] concat(int[] a, int[] b) {
        int[] result = new int[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static long[] concat(long[] a, long[] b) {
        long[] result = new long[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static String[] concat(String[] a, String[] b) {
        String[] result = new String[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static double[] concat(double[] a, double[] b) {
        double[] result = new double[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }
    
    public static char[] concat(char[] a, char[] b) {
        char[] result = new char[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static int min(int... x) { // Assumes non-zero arguments
        int m = x[0];
        for (int v : x) m = v < m ? v : m;
        return m;
    }

    public static long min(long... x) { // Assumes non-zero arguments
        long m = x[0];
        for (long v : x) m = v < m ? v : m;
        return m;
    }

    public static double min(double... x) { // Assumes non-zero arguments
        double m = x[0];
        for (double v : x) m = v < m ? v : m;
        return m;
    }

    public static char min(char... x) { // Assumes non-zero arguments
        char m = x[0];
        for (char v : x) m = v < m ? v : m;
        return m;
    }

    public static String min(String... x) { // Assumes non-zero arguments
        String m = x[0];
        for (String xx : x) {
            if (m.compareTo(xx) > 0) {
                m = xx;
            }
        }
        return m;
    }

    public static int max(int... x) { // Assumes non-zero arguments
        int m = x[0];
        for (int v : x)  m = v > m ? v : m;
        return m;
    }

    public static long max(long... x) { // Assumes non-zero arguments
        long m = x[0];
        for (long v : x)  m = v > m ? v : m;
        return m;
    }

    public static double max(double... x) { // Assumes non-zero arguments
        double m = x[0];
        for (double v : x)  m = v > m ? v : m;
        return m;
    }

    public static char max(char... x) { // Assumes non-zero arguments
        char m = x[0];
        for (char v : x)  m = v > m ? v : m;
        return m;
    }

    public static String max(String... x) { // Assumes non-zero arguments
        String m = x[0];
        for (String xx : x) {
            if (m.compareTo(xx) < 0) {
                m = xx;
            }
        }
        return m;
    }
}