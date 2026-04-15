import java.io.*;
import java.math.*;
import java.util.*;
import java.util.function.*;

public class B {

    public static void main(String[] args) {
        Scanner sc = new Scanner();

        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long p = sc.nextLong(), r = sc.nextLong();
            int k = sc.nextInt();


            boolean works = true;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (p >= x) {
                    p -= x;
                }
                else {
                    works = false;
                }

                if ((i + 1) % k == 0) p += r;
            }

            println(works ? "nah i’d win" : "nah i’d lose");
        }

        flush();
    }

    /**
     * Auto flush output on user and judge end for interactive problems.
     */
    @SuppressWarnings("all")
    static boolean autoFlush = false;

    /**
     * This logic already auto flushes on user end.
     */
    @SuppressWarnings("all")
    static boolean debug;

    static {
        try {
            @SuppressWarnings("all")
            boolean temp = autoFlush ? true : System.getProperty("ONLINE_JUDGE") == null;
            debug = temp;
        } catch (Exception ignored) {

        }
    }

    @SuppressWarnings("all")
    static int MOD = 1_000_000_007;
    @SuppressWarnings("all")
    static int MOD2 = 998_244_353;
    @SuppressWarnings("all")
    static int[][] dir2 = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    @SuppressWarnings("all")
    static int[][] dir3 = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    @SuppressWarnings("all")
    static PrintWriter pw = new PrintWriter(System.out);
    @SuppressWarnings("all")
    static String delim = " ";

    @SuppressWarnings("all")
    static void println() {
        pw.println();
        if (debug) pw.flush();
    }

    @SuppressWarnings("all")
    static void print(Object x) {
        if (x != null && x.getClass().isArray()) {
            String result;
            if (x instanceof int[]) {
                result = Arrays.toString((int[]) x);
            } else if (x instanceof long[]) {
                result = Arrays.toString((long[]) x);
            } else if (x instanceof double[]) {
                result = Arrays.toString((double[]) x);
            } else if (x instanceof float[]) {
                result = Arrays.toString((float[]) x);
            } else if (x instanceof boolean[]) {
                result = Arrays.toString((boolean[]) x);
            } else if (x instanceof short[]) {
                result = Arrays.toString((short[]) x);
            } else if (x instanceof char[]) {
                result = Arrays.toString((char[]) x);
            } else if (x instanceof byte[]) {
                result = Arrays.toString((byte[]) x);
            } else {
                result = Arrays.toString((Object[]) x);
            }
            pw.print(result);
        } else {
            pw.print(x);
        }
        if (debug) pw.flush();
    }

    @SuppressWarnings("all")
    static void println(Object x) {
        print(x);
        println();
    }

    @SuppressWarnings("all")
    static <T> void iterPrint(Iterable<T> arr) {
        boolean space = false;
        for (T t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static <T> void iterPrint(T[] arr) {
        boolean space = false;
        for (T t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void iterPrint(int[] arr) {
        boolean space = false;
        for (int t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void iterPrint(long[] arr) {
        boolean space = false;
        for (long t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void iterPrint(double[] arr) {
        boolean space = false;
        for (double t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void iterPrint(char[] arr) {
        boolean space = false;
        for (char t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void iterPrint(boolean[] arr) {
        boolean space = false;
        for (boolean t : arr) {
            if (space) print(delim);
            print(t);
            space = true;
        }
        println();
    }

    @SuppressWarnings("all")
    static void printf(String format, Object... args) {
        pw.printf(format, args);
        if (debug) pw.flush();
    }

    static void flush() {
        pw.flush();
    }

    @SuppressWarnings("all")
    static class Scanner {
        BufferedReader br;
        StringTokenizer curr;
        String delim = " \t\n\r\f";

        Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        Scanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.out.println("Switching to stdin...");
                br = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        boolean setDelimiter(String delim) {
            this.delim = delim;
            return curr == null;
        }

        String getDelimiter() {
            return delim;
        }

        String next() {
            while (curr == null) {
                try {
                    curr = new StringTokenizer(br.readLine(), delim);
                } catch (IOException e) {
                    return null;
                }
                if (curr.countTokens() == 0) {
                    curr = null;
                    continue;
                }
            }
            String result = curr.nextToken();
            if (!curr.hasMoreTokens()) curr = null;
            return result;
        }

        boolean hasNext() {
            try {
                return curr == null && curr.hasMoreTokens() || br.ready();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        BigInteger nextBigInteger() {
            return new BigInteger(next());
        }

        boolean nextBoolean() {
            return Boolean.parseBoolean(next());
        }

        boolean[] nextBinaryString() {
            return nextBinaryString('1');
        }

        boolean[] nextBinaryString(char truth) {
            String s = next();
            int n = s.length();
            boolean[] result = new boolean[n];
            for (int i = 0; i < n; i++) {
                result[i] = s.charAt(i) == truth;
            }
            return result;
        }

        String nextLine() {
            if (curr == null) {
                try {
                    return br.readLine();
                } catch (IOException e) {
                    return null;
                }
            }
            StringBuilder remaining = new StringBuilder();
            remaining.append(curr.nextToken());
            while (curr.hasMoreTokens()) {
                remaining.append(' ').append(curr.nextToken());
            }
            return remaining.toString();
        }

        String[] nextStringArray(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        long[] nextLongArray(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        double[] nextDoubleArray(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }

        BigInteger[] nextBigIntegerArray(int n) {
            BigInteger[] arr = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextBigInteger();
            }
            return arr;
        }

        boolean[] nextBooleanArray(int n) {
            boolean[] arr = new boolean[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextBoolean();
            }
            return arr;
        }
    }

    @SuppressWarnings("all")
    static class Pair<A, B> {
        public A a;
        public B b;

        public Pair() {
            a = null;
            b = null;
        }

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public String toString() {
            return toString("<", ", ", ">");
        }

        public String toString(String prefix, String delimiter, String suffix) {
            StringBuilder sb = new StringBuilder();
            sb.append(prefix);
            sb.append(a);
            sb.append(delimiter);
            sb.append(b);
            sb.append(suffix);
            return sb.toString();
        }
    }

    @SuppressWarnings("all")
    static List<Integer>[] toAdjList(int n, int[][] edges, boolean directed) {
        List<Integer>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            adjList[u].add(v);
            if (!directed) adjList[v].add(u);
        }
        return adjList;
    }

    @SuppressWarnings("all")
    static List<int[]>[] toAdjListWeighted(int n, int[][] edges, boolean directed) {
        List<int[]>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].add(new int[]{v, w});
            if (!directed) adjList[v].add(new int[]{u, w});
        }
        return adjList;
    }

    @SuppressWarnings("all")
    static HashSet<Integer>[] toAdjSet(int n, int[][] edges, boolean directed) {
        HashSet<Integer>[] adjSet = new HashSet[n];
        for (int i = 0; i < n; i++) {
            adjSet[i] = new HashSet<>();
        }
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            adjSet[u].add(v);
            if (!directed) adjSet[v].add(u);
        }
        return adjSet;
    }

    @SuppressWarnings("all")
    static int[] shortestPathUnweighted(int n, int start, Iterable<Integer>[] adj) {
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : adj[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    queue.offer(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] == Integer.MAX_VALUE) dist[i] = -1;
        }
        return dist;
    }

    @SuppressWarnings("all")
    static long[] shortestPathWeighted(int n, int start, Iterable<int[]>[] adj) {
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1]));
        pq.offer(new long[]{start, 0});

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            int u = (int) curr[0];
            long d = curr[1];
            if (d > dist[u]) continue;

            for (int[] next : adj[u]) {
                int v = next[0], w = next[1];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new long[]{v, dist[v]});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == Long.MAX_VALUE) dist[i] = -1;
        }

        return dist;
    }

    @SuppressWarnings("all")
    static class TreeInfo {
        public int[] parents;
        public int[] depths;
    }

    /**
     * Finds parents and depths of nodes in a tree.
     */
    @SuppressWarnings("all")
    static TreeInfo treeDfs(int root, int n, Iterable<Integer>[] adj) {
        TreeInfo result = new TreeInfo();

        int[] parents = new int[n];
        int[] depths = new int[n];
        parents[root] = -1;
        depths[root] = 0;

        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            int depth = depths[curr];
            for (int next : adj[curr]) {
                if (next == parents[curr]) continue;
                parents[next] = curr;
                depths[next] = depth + 1;
                stack.push(next);
            }
        }

        result.parents = parents;
        result.depths = depths;

        return result;
    }

    @SuppressWarnings("all")
    static int[][] treeBinLift(int n, int LOG, int[] parent) {
        int[][] binLift = new int[n][LOG];
        for (int i = 0; i < n; i++) {
            binLift[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                binLift[i][j] = binLift[i][j - 1] == -1 ? -1 : binLift[binLift[i][j - 1]][j - 1];
            }
        }
        return binLift;
    }

    @SuppressWarnings("all")
    static int kthAncestor(int u, int k, int[][] binLift) {
        int LOG = binLift[0].length;
        if (k == 0) return u;
        for (int j = 0; j < LOG; j++) {
            if ((k & (1 << j)) > 0) {
                u = binLift[u][j];
                if (u == -1) return -1;
            }
        }
        return u;
    }

    @SuppressWarnings("all")
    static int lca(int u, int v, int[] depth, int[][] binLift) {
        int LOG = binLift[0].length;
        if (depth[u] < depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        u = kthAncestor(u, depth[u] - depth[v], binLift);
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (binLift[u][j] != binLift[v][j]) {
                u = binLift[u][j];
                v = binLift[v][j];
            }
        }
        return binLift[u][0];
    }

    @SuppressWarnings("all")
    static int treeDist(int u, int v, int[] depth, int[][] binLift) {
        int lca = lca(u, v, depth, binLift);
        return depth[u] + depth[v] - 2 * depth[lca];
    }

    @SuppressWarnings("all")
    static List<Integer> kmp(String s, String pattern) {
        int n = s.length(), m = pattern.length();
        List<Integer> result = new ArrayList<>();
        int[] pi = new int[m];
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) j = pi[j - 1];
            if (pattern.charAt(i) == pattern.charAt(j)) j++;
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && s.charAt(i) != pattern.charAt(j)) j = pi[j - 1];
            if (s.charAt(i) == pattern.charAt(j)) j++;
            if (j == m) {
                result.add(i - m + 1);
                j = pi[j - 1];
            }
        }
        return result;
    }

    @SuppressWarnings("all")
    static int[] maxOddPalindrome(String s) {
        int n = s.length();
        int[] result = new int[n];
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : Math.min(result[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s.charAt(i - k) == s.charAt(i + k)) k++;
            result[i] = --k;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return result;
    }

    @SuppressWarnings("all")
    static int[] maxEvenPalindrome(String s) {
        int n = s.length();
        int[] result = new int[n];
        int l = 0, r = -1;
        for (int i = 1; i < n; i++) {
            int k = (i > r) ? 0 : Math.min(result[l + r - i], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s.charAt(i - k - 1) == s.charAt(i + k)) k++;
            result[i - 1] = k;
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return result;
    }

    @SuppressWarnings("all")
    static long invMod(long val, long mod) {
        val = val % mod;
        return val <= 1 ? val : mod - mod / val * invMod(mod % val, mod) % mod;
    }

    @SuppressWarnings("all")
    static long invMod2(long a, long mod) {
        long t = 0, newT = 1;
        long r = mod, newR = a;

        while (newR != 0) {
            long quotient = r / newR;

            long tempT = t;
            t = newT;
            newT = tempT - quotient * newT;

            long tempR = r;
            r = newR;
            newR = tempR - quotient * newR;
        }
        if (r > 1) {
            return -1;
        }
        if (t < 0) {
            t = t + mod;
        }
        return t;
    }

    @SuppressWarnings("all")
    static long exp(long val, long pow, long mod) {
        if (pow < 0) return invMod(exp(val, -pow, mod), mod);
        val %= mod;
        long result = 1 % mod;
        while (pow > 0) {
            if ((pow & 1) > 0) result = (result * val) % mod;
            val = (val * val) % mod;
            pow /= 2;
        }
        return result;
    }

    @SuppressWarnings("all")
    static long saferMul(long a, long b, long M) {
        a %= M;
        b %= M;
        long ret = a * b - (long) ((1.0 / M) * a * b) * M;
        ret = ((ret % M) + M) % M;
        return ret;
    }

    @SuppressWarnings("all")
    static long saferExp(long a, long b, long M) {
        if (b < 0) return invMod(exp(a, -b, M), M);
        a %= M;
        long res = 1 % M;
        while (b > 0) {
            if ((b & 1) > 0) res = saferMul(res, a, M);
            a = saferMul(a, a, M);
            b /= 2;
        }
        return res;
    }

    @SuppressWarnings("all")
    static long[] A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    @SuppressWarnings("all")
    static boolean isPrime(long n) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        long s = Long.numberOfTrailingZeros(n - 1), d = n >> s;
        for (long a : A) {
            long p = saferExp(a % n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n != 0 && i-- > 0) {
                p = saferMul(p, p, n);
            }
            if (p != n - 1 && i != s) return false;
        }
        return true;
    }

    @SuppressWarnings("all")
    static long pollard(long n) {
        if (n % 2 == 0) return 2;
        long x = 0, y = 0, t = 30, prd = 2, i = 1, q;

        while (t++ % 40 != 0 || gcd(prd, n) == 1) {
            if (x == y) {
                x = ++i;
                y = (saferMul(x, x, n) + i) % n;
            }
            q = saferMul(prd, Math.abs(x - y), n);
            if (q != 0) prd = q;
            x = (saferMul(x, x, n) + i) % n;
            y = (saferMul(y, y, n) + i) % n;
            y = (saferMul(y, y, n) + i) % n;
        }
        return gcd(prd, n);
    }

    @SuppressWarnings("all")
    static List<Long> factor(long n) {
        List<Long> res = new ArrayList<>();
        if (n == 1) return res;
        if (isPrime(n)) {
            res.add(n);
            return res;
        }
        long x = pollard(n);
        res.addAll(factor(x));
        res.addAll(factor(n / x));
        return res;
    }

    @SuppressWarnings("all")
    static long[] fact = null;
    @SuppressWarnings("all")
    static long[] invFact = null;
    @SuppressWarnings("all")
    static long tempMod = -1;

    @SuppressWarnings("all")
    static void popFact(int max) {
        fact = new long[max + 1];
        fact[0] = 1;
        for (int i = 1; i <= max; i++) {
            fact[i] = i * fact[i - 1];
        }
        tempMod = -1;
    }

    @SuppressWarnings("all")
    static void popFact(int max, long mod) {
        fact = new long[max + 1];
        invFact = new long[max + 1];
        fact[0] = 1 % mod;
        for (int i = 1; i <= max; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        invFact[max] = invMod(fact[max], mod);
        for (int i = max; i >= 1; i--) {
            invFact[i - 1] = (i * invFact[i]) % mod;
        }
        tempMod = mod;
    }

    @SuppressWarnings("all")
    static long choose(int n, int k) {
        if (k > n) return 0;
        if (n > 20) {
            k = Math.min(k, n - k);
            long result = 1;
            for (int x = 0; x < k; x++) {
                result *= (n - x);
                result /= (x + 1);
            }
            return result;
        }
        if (tempMod != -1 || fact == null || fact.length <= n) popFact(Math.max(n, n << 1));
        return fact[n] / fact[k] / fact[n - k];
    }

    @SuppressWarnings("all")
    static long choose(int n, int k, long mod) {
        if (k > n) return 0;
        if (tempMod != mod || fact == null || fact.length <= n || invFact == null || invFact.length <= n)
            popFact(Math.max(n, n << 1), mod);
        return ((fact[n] * invFact[k]) % mod * invFact[n - k]) % mod;
    }

    @SuppressWarnings("all")
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    @SuppressWarnings("all")
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    @SuppressWarnings("all")
    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    @SuppressWarnings("all")
    static long phi(long n) {
        long result = n;
        for (long x = 2; x * x <= n; x++) {
            if (n % x == 0) {
                while (n % x == 0) n /= x;
                result -= result / x;
            }
        }
        return result - (n > 1 ? result / n : 0);
    }

    @SuppressWarnings("all")
    private static long FFT_MOD = MOD2;
    @SuppressWarnings("all")
    private static long ROOT = 3;
    @SuppressWarnings("all")
    private static int MAX_SIZE = Integer.MAX_VALUE;

    @SuppressWarnings("all")
    private static void ntt(long[] a) {
        int n = a.length, L = 31 - Integer.numberOfLeadingZeros(n);
        long[] rt = new long[n];
        rt[0] = rt[1] = 1;
        for (int k = 2, s = 2; k < n; k *= 2, s++) {
            long[] z = {1, exp(ROOT, FFT_MOD >> s, FFT_MOD)};
            for (int i = k; i < 2 * k; i++) {
                rt[i] = rt[i / 2] * z[i & 1] % FFT_MOD;
            }
        }
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        }
        for (int i = 0; i < n; i++) {
            if (i < rev[i]) {
                long temp = a[i];
                a[i] = a[rev[i]];
                a[rev[i]] = temp;
            }
        }
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    long z = rt[j + k] * a[i + j + k] % FFT_MOD;
                    long ai = a[i + j];
                    a[i + j + k] = ai - z + (z > ai ? FFT_MOD : 0);
                    a[i + j] = (ai + z >= FFT_MOD ? ai + z - FFT_MOD : ai + z);
                }
            }
        }
    }

    @SuppressWarnings("all")
    private static long[] conv(long[] a, long[] b) {
        if (a.length == 0 || b.length == 0) return new long[0];
        int s = a.length + b.length - 1, B = 32 - Integer.numberOfLeadingZeros(s), n = 1 << B;
        long[] L = Arrays.copyOf(a, n), R = Arrays.copyOf(b, n), out = new long[n];
        ntt(L);
        ntt(R);

        long inv = invMod(n, FFT_MOD);
        for (int i = 0; i < n; i++) {
            out[-i & (n - 1)] = L[i] * R[i] % FFT_MOD * inv % FFT_MOD;
        }

        ntt(out);
        return Arrays.copyOf(out, Math.min(MAX_SIZE, s));
    }

    @SuppressWarnings("all")
    private static long[] exp(long[] a, long e) {
        long[] res = {1};
        if (e == 0) return res;

        long[] cur = a;
        while (e > 0) {
            if (e % 2 == 1) {
                res = conv(res, cur);
            }
            e /= 2;
            cur = conv(cur, cur);
        }
        return res;
    }

    @SuppressWarnings("all")
    static int getMin(int[] arr) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < min) min = arr[i];
        }
        return min;
    }

    @SuppressWarnings("all")
    static long getMin(long[] arr) {
        long min = Long.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < min) min = arr[i];
        }
        return min;
    }

    @SuppressWarnings("all")
    static double getMin(double[] arr) {
        double min = Double.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < min) min = arr[i];
        }
        return min;
    }

    @SuppressWarnings("all")
    static int getMax(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    @SuppressWarnings("all")
    static long getMax(long[] arr) {
        long max = Long.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    @SuppressWarnings("all")
    static double getMax(double[] arr) {
        double max = Double.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }

    @SuppressWarnings("all")
    static int[] reverse(int[] arr) {
        int[] result = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = arr[arr.length - i - 1];
        }
        return result;
    }

    @SuppressWarnings("all")
    static long[] reverse(long[] arr) {
        long[] result = new long[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = arr[arr.length - i - 1];
        }
        return result;
    }

    @SuppressWarnings("all")
    static List<Integer> reverse(List<Integer> list) {
        int size = list.size();
        List<Integer> result = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            result.add(list.get(size - i - 1));
        }
        return result;
    }

    @SuppressWarnings("all")
    static String reverse(String s) {
        StringBuilder sb = new StringBuilder();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            sb.append(s.charAt(len - i - 1));
        }
        return sb.toString();
    }

    @SuppressWarnings("all")
    static int[] prefSum(int[] arr) {
        int len = arr.length;
        int[] result = new int[len];
        for (int i = 0; i < len; i++) {
            result[i] = arr[i] + (i == 0 ? 0 : result[i - 1]);
        }
        return result;
    }

    @SuppressWarnings("all")
    static long[] prefSum(long[] arr) {
        int len = arr.length;
        long[] result = new long[len];
        for (int i = 0; i < len; i++) {
            result[i] = arr[i] + (i == 0 ? 0L : result[i - 1]);
        }
        return result;
    }

    @SuppressWarnings("all")
    static Integer[] box(int[] arr) {
        Integer[] boxedArray = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxedArray[i] = arr[i];
        }
        return boxedArray;
    }

    @SuppressWarnings("all")
    static Long[] box(long[] arr) {
        Long[] boxedArray = new Long[arr.length];
        for (int i = 0; i < arr.length; i++) {
            boxedArray[i] = arr[i];
        }
        return boxedArray;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int lowerBound(int l, int r, U target, Function<Integer, U> function) {
        while (l < r) {
            int mid = (l + r) >> 1;
            U curr = function.apply(mid);
            int c = curr.compareTo(target);
            if (c < 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> long lowerBound(long l, long r, U target, Function<Long, U> function, long ignored) {
        while (l < r) {
            long mid = (l + r) >> 1;
            U curr = function.apply(mid);
            int c = curr.compareTo(target);
            if (c < 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int lowerBound(U[] arr, U target) {
        return lowerBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int lowerBound(int[] arr, int target) {
        return lowerBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int lowerBound(long[] arr, long target) {
        return lowerBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int lowerBound(double[] arr, double target) {
        return lowerBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int lowerBound(List<U> list, U target) {
        return lowerBound(0, list.size(), target, i -> list.get(i));
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int upperBound(int l, int r, U target, Function<Integer, U> function) {
        while (l < r) {
            int mid = (l + r) >> 1;
            U curr = function.apply(mid);
            int c = curr.compareTo(target);
            if (c <= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> long upperBound(long l, long r, U target, Function<Long, U> function, long ignored) {
        while (l < r) {
            long mid = (l + r) >> 1;
            U curr = function.apply(mid);
            int c = curr.compareTo(target);
            if (c <= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int upperBound(U[] arr, U target) {
        return upperBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int upperBound(int[] arr, int target) {
        return upperBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int upperBound(long[] arr, long target) {
        return upperBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static int upperBound(double[] arr, double target) {
        return upperBound(0, arr.length, target, i -> arr[i]);
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int upperBound(List<U> list, U target) {
        return upperBound(0, list.size(), target, i -> list.get(i));
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int convexMin(int l, int r, Function<Integer, U> function) {
        while (l < r) {
            int diff = (r - l) / 3;
            int mid1 = l + diff;
            int mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c < 0) {
                r = mid2 - 1;
            } else if (c > 0) {
                l = mid1 + 1;
            } else {
                l = mid1;
                r = mid2 - 1;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> int convexMax(int l, int r, Function<Integer, U> function) {
        while (l < r) {
            int diff = (r - l) / 3;
            int mid1 = l + diff;
            int mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c > 0) {
                r = mid2 - 1;
            } else if (c < 0) {
                l = mid1 + 1;
            } else {
                l = mid1;
                r = mid2 - 1;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> long convexMin(long l, long r, Function<Long, U> function, long ignored) {
        while (l < r) {
            long diff = (r - l) / 3L;
            long mid1 = l + diff;
            long mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c < 0) {
                r = mid2 - 1;
            } else if (c > 0) {
                l = mid1 + 1;
            } else {
                l = mid1;
                r = mid2 - 1;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> long convexMax(long l, long r, Function<Long, U> function, long ignored) {
        while (l < r) {
            long diff = (r - l) / 3L;
            long mid1 = l + diff;
            long mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c > 0) {
                r = mid2 - 1;
            } else if (c < 0) {
                l = mid1 + 1;
            } else {
                l = mid1;
                r = mid2 - 1;
            }
        }
        return l;
    }

    @SuppressWarnings("all")
    static double error = 1e-9;

    @SuppressWarnings("all")
    static <U extends Comparable<U>> double convexMin(double l, double r, Function<Double, U> function, boolean ignored) {
        while (r - l >= error) {
            double diff = (r - l) / 3.0;
            double mid1 = l + diff;
            double mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c < 0) {
                r = mid2;
            } else if (c > 0) {
                l = mid1;
            } else {
                l = mid1;
                r = mid2;
            }
        }
        return (l + r) / 2.0;
    }

    @SuppressWarnings("all")
    static <U extends Comparable<U>> double convexMax(double l, double r, Function<Double, U> function, boolean ignored) {
        while (r - l >= error) {
            double diff = (r - l) / 3.0;
            double mid1 = l + diff;
            double mid2 = r - diff;
            U curr1 = function.apply(mid1);
            U curr2 = function.apply(mid2);
            int c = curr1.compareTo(curr2);
            if (c > 0) {
                r = mid2;
            } else if (c < 0) {
                l = mid1;
            } else {
                l = mid1;
                r = mid2;
            }
        }
        return (l + r) / 2.0;
    }

    @SuppressWarnings("all")
    static long orientation(long x1, long y1, long x2, long y2, long x3, long y3) {
        return (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
    }

    @SuppressWarnings("all")
    static long distSq(long x1, long y1, long x2, long y2) {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }

    @SuppressWarnings("all")
    static List<long[]> convexHull(long[][] points) {
        int n = points.length;
        if (n == 1) return Arrays.asList(points);
        long minY = Long.MAX_VALUE;
        int startIdx = -1;
        for (int i = 0; i < n; i++) {
            if (points[i][1] < minY) {
                minY = points[i][1];
                startIdx = i;
            }
        }

        long startX = points[startIdx][0];
        long startY = points[startIdx][1];
        Arrays.sort(points, (a, b) -> {
            if (a[0] == startX && a[1] == startY) return -1;
            if (b[0] == startX && b[1] == startY) return 1;
            long orient = orientation(startX, startY, a[0], a[1], b[0], b[1]);
            if (orient != 0) return -Long.signum(orient);
            return Long.compare(distSq(startX, startY, a[0], a[1]), distSq(startX, startY, b[0], b[1]));
        });

        int j = n - 1;
        while (j > 0 && orientation(startX, startY, points[j][0], points[j][1], points[j - 1][0], points[j - 1][1]) == 0) {
            j--;
        }
        for (int i = j; i < j + (n - j) / 2; i++) {
            long[] temp = points[i];
            points[i] = points[n - 1 - (i - j)];
            points[n - 1 - (i - j)] = temp;
        }

        List<long[]> hull = new ArrayList<>();
        hull.add(points[0]);
        hull.add(points[1]);
        for (int i = 2; i < n; i++) {
            long[] next = points[i];
            while (hull.size() >= 2) {
                long[] curr = hull.get(hull.size() - 1);
                long[] prev = hull.get(hull.size() - 2);
                if (orientation(prev[0], prev[1], curr[0], curr[1], next[0], next[1]) < 0) {
                    hull.remove(hull.size() - 1);
                } else break;
            }
            hull.add(next);
        }
        return hull;
    }

    @SuppressWarnings("all")
    static long[][] multiply(long[][] a, long[][] b) {
        return multiply(a, b, 0);
    }

    @SuppressWarnings("all")
    static long[][] multiply(long[][] a, long[][] b, long mod) {
        int n = a.length;
        int m = a[0].length;
        int k = b[0].length;
        long[][] result = new long[n][k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < m; l++) {
                    if (mod <= 0) {
                        result[i][j] += a[i][l] * b[l][j];
                    } else {
                        result[i][j] = (result[i][j] + (a[i][l] % mod * (b[l][j] % mod))) % mod;
                    }
                }
            }
        }
        return result;
    }

    @SuppressWarnings("all")
    static long[][] add(long[][] a, long[][] b) {
        return add(a, b, 0);
    }

    @SuppressWarnings("all")
    static long[][] add(long[][] a, long[][] b, long mod) {
        int n = a.length;
        int m = a[0].length;
        long[][] result = new long[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = mod > 0 ? (a[i][j] + b[i][j] % mod) : (a[i][j] + b[i][j]);
            }
        }
        return result;
    }

    @SuppressWarnings("all")
    static long[][] exp(long[][] matrix, long pow, long mod) {
        int n = matrix.length;
        long[][] result = new long[n][n];
        for (int i = 0; i < n; i++) {
            result[i][i] = 1 % mod;
        }
        while (pow > 0) {
            if ((pow & 1) > 0) result = multiply(result, matrix, mod);
            matrix = multiply(matrix, matrix, mod);
            pow >>= 1;
        }
        return result;
    }

    @SuppressWarnings("all")
    static class ListNode<T> {
        ListNode<T> prev;
        ListNode<T> next;
        T val;

        ListNode() {
            val = null;
        }

        ListNode(T val) {
            this.val = val;
        }

        void addPrev(T val) {
            ListNode<T> node = new ListNode<>(val);
            node.next = this;
            node.prev = prev;
            if (prev != null) {
                prev.next = node;
            }
            prev = node;
        }

        void addNext(T val) {
            ListNode<T> node = new ListNode<>(val);
            node.prev = this;
            node.next = next;
            if (next != null) {
                next.prev = node;
            }
            next = node;
        }

        void detach() {
            if (prev != null) {
                prev.next = next;
            }
            if (next != null) {
                next.prev = prev;
            }
            prev = null;
            next = null;
        }
    }

    @SuppressWarnings("all")
    static class BSTNode<T extends Comparable<T>> {
        public BSTNode<T> left;
        public BSTNode<T> right;
        public T val;

        public BSTNode(T val) {
            this.val = val;
        }

        public void add(BSTNode<T> node) {
            int c = node.val.compareTo(val);
            if (c <= 0) {
                if (left == null) {
                    left = node;
                } else {
                    left.add(node);
                }
            } else {
                if (right == null) {
                    right = node;
                } else {
                    right.add(node);
                }
            }
        }
    }

    @SuppressWarnings("all")
    static class DSU {
        int[] parents;
        int[] sizes;
        int components;

        public DSU(int n) {
            parents = new int[n];
            sizes = new int[n];
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                sizes[i] = 1;
            }
            components = n;
        }

        public int find(int x) {
            return parents[x] == x ? x : (parents[x] = find(parents[x]));
        }

        public boolean union(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);
            if (xRoot == yRoot) return false;
            if (sizes[xRoot] < sizes[yRoot]) {
                return union(yRoot, xRoot);
            }
            parents[yRoot] = xRoot;
            sizes[xRoot] += sizes[yRoot];
            components--;
            return true;
        }

        public boolean connected(int x, int y) {
            return find(x) == find(y);
        }

        public boolean fullyConnected() {
            return components == 1;
        }
    }

    @SuppressWarnings("all")
    static class Trie {
        TrieMode mode;
        TrieNode root;
        int size;

        private class TrieNode {
            TrieNode[] children = new TrieNode[size];
            boolean end = false;
        }

        private enum TrieMode {
            LOWERCASE, UPPERCASE, ASCII
        }

        public Trie() {
            this(26);
            this.mode = TrieMode.LOWERCASE;
        }

        public Trie(TrieMode mode) {
            this(mode == TrieMode.ASCII ? 128 : 26);
            this.mode = mode;
        }

        public Trie(int size) {
            this.size = size;
            root = new TrieNode();
        }

        private int[] stoi(String s) {
            int[] result = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                result[i] = mode == TrieMode.LOWERCASE ? s.charAt(i) - 'a' :
                        mode == TrieMode.UPPERCASE ? s.charAt(i) - 'A' :
                                s.charAt(i);
            }
            return result;
        }

        public void insert(String word) {
            insert(stoi(word));
        }

        public boolean contains(String word) {
            return contains(stoi(word));
        }

        public void insert(int[] word) {
            TrieNode curr = root;
            int len = word.length;
            for (int i = 0; i < len; i++) {
                int c = word[i];
                if (curr.children[c] == null) {
                    curr.children[c] = new TrieNode();
                }
                curr = curr.children[c];
            }
            curr.end = true;
        }

        public boolean contains(int[] word) {
            TrieNode curr = root;
            int len = word.length;
            for (int i = 0; i < len; i++) {
                int c = word[i];
                if (curr.children[c] == null) {
                    return false;
                }
                curr = curr.children[c];
            }
            return curr.end;
        }
    }

    @SuppressWarnings("all")
    static class FenwickTree {
        long[] bit;
        int n;

        FenwickTree(int n) {
            this.n = n;
            bit = new long[n];
        }

        long sum(int r) {
            long ret = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                ret += bit[r];
            return ret;
        }

        void add(int idx, long delta) {
            for (; idx < n; idx = idx | (idx + 1))
                bit[idx] += delta;
        }
    }

    @SuppressWarnings("all")
    static class SegTree<T, R> {
        private final BinaryOperator<R> accumulator;
        private final Function<T, R> mapper;
        int n;
        R[] tree;

        SegTree(T[] arr, Function<T, R> individualMapper, BinaryOperator<R> accumulator) {
            tree = (R[]) new Object[arr.length << 2];
            this.n = arr.length;
            this.mapper = individualMapper;
            this.accumulator = accumulator;
            build(arr, 0, 0, n - 1);
        }

        private void build(T[] arr, int i, int l, int r) {
            if (l == r) {
                tree[i] = mapper.apply(arr[l]);
                return;
            }
            int m = (l + r) / 2;
            int i1 = i * 2 + 1, i2 = i1 + 1;
            build(arr, i1, l, m);
            build(arr, i2, m + 1, r);
            tree[i] = accumulator.apply(tree[i1], tree[i2]);
        }

        private void build(List<T> list, int i, int l, int r) {
            if (l == r) {
                tree[i] = mapper.apply(list.get(l));
                return;
            }
            int m = (l + r) / 2;
            int i1 = i * 2 + 1, i2 = i1 + 1;
            build(list, i1, l, m);
            build(list, i2, m + 1, r);
            tree[i] = accumulator.apply(tree[i1], tree[i2]);
        }

        R query(int l, int r) {
            return query(0, 0, n - 1, l, r);
        }

        private R query(int i, int cl, int cr, int l, int r) {
            if (l > r || l < 0 || r >= n)
                throw new IllegalArgumentException("Invalid Range: " + l + ", " + r + " for size " + n);
            if (l == cl && r == cr) return tree[i];
            int m = (cl + cr) / 2;
            int i1 = i * 2 + 1, i2 = i1 + 1;
            if (m >= r) {
                return query(i1, cl, m, l, r);
            } else if (m < l) {
                return query(i2, m + 1, cr, l, r);
            } else {
                return accumulator.apply(query(i1, cl, m, l, m), query(i2, m + 1, cr, m + 1, r));
            }
        }

        void set(int index, T val) {
            helperSet(0, 0, n - 1, index, val);
        }

        private void helperSet(int i, int l, int r, int index, T val) {
            if (l == r) {
                tree[i] = mapper.apply(val);
                return;
            }
            int m = (l + r) / 2;
            int i1 = i * 2 + 1, i2 = i1 + 1;
            if (index <= m) helperSet(i1, l, m, index, val);
            else helperSet(i2, m + 1, r, index, val);
            tree[i] = accumulator.apply(tree[i1], tree[i2]);
        }
    }

    @SuppressWarnings("all")
    static class SparseTable<T, R> {
        private final BinaryOperator<R> accumulator;
        private final Function<T, R> mapper;
        int n;
        int LOG;
        R[][] table;

        SparseTable(T[] arr, Function<T, R> individualMapper, BinaryOperator<R> accumulator) {
            this.n = arr.length;
            this.mapper = individualMapper;
            this.accumulator = accumulator;
            this.LOG = 32 - Integer.numberOfLeadingZeros(n);
            table = (R[][]) new Object[LOG + 1][n];
            build(arr);
        }

        private void build(T[] arr) {
            for (int i = 0; i < n; i++) {
                table[0][i] = mapper.apply(arr[i]);
            }
            for (int j = 1; j <= LOG; j++) {
                int len = 1 << j;
                for (int i = 0; i + len <= n; i++) {
                    table[j][i] = accumulator.apply(table[j - 1][i], table[j - 1][i + (len >> 1)]);
                }
            }
        }

        R query(int l, int r) {
            if (l > r || l < 0 || r >= n)
                throw new IllegalArgumentException("Invalid Range: " + l + ", " + r + " for size " + n);
            int len = r - l + 1;
            int k = 31 - Integer.numberOfLeadingZeros(len);
            return accumulator.apply(table[k][l], table[k][r - (1 << k) + 1]);
        }
    }

    @SuppressWarnings("all")
    // Min Tree
    static class LiChaoTree {
        long eval(long[] line, long x) {
            return line[0] * x + line[1];
        }

        int n;
        long[][] tree;

        LiChaoTree(int n) {
            this.n = n;
            this.tree = new long[n][2];
            for (int i = 0; i < n; i++) {
                tree[i][0] = 0;
                tree[i][1] = Long.MAX_VALUE;
            }
        }

        void addLine(long m, long b) {
            long[] line = {m, b};
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (eval(line, mid) < eval(tree[mid], mid)) {
                    long[] temp = tree[mid];
                    tree[mid] = line;
                    line = temp;
                }

                if (eval(line, l) < eval(tree[mid], l)) {
                    r = mid - 1;
                } else if (eval(line, r) < eval(tree[mid], r)) {
                    l = mid + 1;
                } else {
                    break;
                }
            }
        }

        long query(int x) {
            int l = 0, r = n - 1;
            long result = Long.MAX_VALUE;
            while (l <= r) {
                int mid = (l + r) >> 1;
                result = Math.min(result, eval(tree[mid], x));
                if (x == mid) {
                    break;
                } else if (x < mid) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return result;
        }
    }

    @SuppressWarnings("all")
    static class ImplicitTreap {
        private static final Random rand = new Random();
        private Node root = null;

        class Node {
            int x;
            int y;
            int size;
            boolean rev;
            long sum;
            Node left, right;

            Node(int x) {
                this.x = x;
                this.y = rand.nextInt();
                this.size = 1;
                this.rev = false;
                this.sum = x;
            }

            void push() {
                if (rev) {
                    Node tmp = left;
                    left = right;
                    right = tmp;
                    if (left != null) left.rev ^= true;
                    if (right != null) right.rev ^= true;
                    rev = false;
                }
            }

            void pull() {
                size = 1 + sizeOf(left) + sizeOf(right);
                sum = (long) x + sumOf(left) + sumOf(right);
            }
        }

        private static int sizeOf(Node t) {
            return t == null ? 0 : t.size;
        }

        private static long sumOf(Node t) {
            return t == null ? 0L : t.sum;
        }

        private static Node[] split(Node t, int k) {
            if (t == null) return new Node[]{null, null};
            t.push();
            int ls = sizeOf(t.left);
            if (k <= ls) {
                Node[] pair = split(t.left, k);
                t.left = pair[1];
                t.pull();
                pair[1] = t;
                return pair;
            } else {
                Node[] pair = split(t.right, k - ls - 1);
                t.right = pair[0];
                t.pull();
                pair[0] = t;
                return pair;
            }
        }

        private static Node merge(Node l, Node r) {
            if (l == null) return r;
            if (r == null) return l;
            l.push();
            r.push();
            if (l.y > r.y) {
                l.right = merge(l.right, r);
                l.pull();
                return l;
            } else {
                r.left = merge(l, r.left);
                r.pull();
                return r;
            }
        }

        /*
         * Add elements in their correct ordering
         */
        public void add(int x) {
            root = merge(root, new Node(x));
        }

        public void moveToEnd(int l, int r) {
            Node[] a = split(root, l);
            Node left = a[0], rest = a[1];
            Node[] b = split(rest, r - l + 1);
            Node mid = b[0], right = b[1];
            root = merge(merge(left, right), mid);
        }

        public void reverse(int l, int r) {
            Node[] a = split(root, l);
            Node left = a[0], rest = a[1];
            Node[] b = split(rest, r - l + 1);
            Node mid = b[0], right = b[1];
            if (mid != null) mid.rev ^= true;
            root = merge(merge(left, mid), right);
        }

        public long sum(int l, int r) {
            Node[] a = split(root, l);
            Node left = a[0], rest = a[1];
            Node[] b = split(rest, r - l + 1);
            Node mid = b[0], right = b[1];
            long ans = sumOf(mid);
            root = merge(merge(left, mid), right);
            return ans;
        }

        public int size() {
            return sizeOf(root);
        }
    }

    @SuppressWarnings("all")
    static class Triple<A, B, C> {
        public A a;
        public B b;
        public C c;

        public Triple() {
            a = null;
            b = null;
            c = null;
        }

        public Triple(A a, B b, C c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public String toString() {
            return toString("<", ", ", ">");
        }

        public String toString(String prefix, String delimiter, String suffix) {
            StringBuilder sb = new StringBuilder();
            sb.append(prefix);
            sb.append(a);
            sb.append(delimiter);
            sb.append(b);
            sb.append(delimiter);
            sb.append(c);
            sb.append(suffix);
            return sb.toString();
        }
    }
}