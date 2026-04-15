import java.io.*;
import java.util.*;

class Pair {
    int a, b;
    public Pair(int r, int s) {
        a = r;
        b = s;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return a == pair.a && b == pair.b;
    }

    @Override
    public int hashCode() {
        return Objects.hash(a, b);
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            get();
            int K = g(), N = g(), M = g(), P = g(), Q = g();
            HashSet<Pair> ast = new HashSet<>();
            HashMap<Pair, Integer> m = new HashMap<>();

            int currX = -1, currY = -1;

            for (int j = 0; j < K; j++) {
                get();
                int x = g(), y = g();
                ast.add(new Pair(x, y));
                m.put(new Pair(x, y), j);

                if (j == 0) { currX = x; currY = y; }
            }
            o:
            while (true) {
                for (int j = 0; j < Q; j++) {
                    currX++;
                    if (currX >= N) {
                        currX = 0;
                    }
                    for (int k = 0; k < P; k++) {
                        currY++;
                        if (currY >= M) {
                            currY = 0;
                        }
                    }

                    if (ast.contains(new Pair(currX, currY))) {
                        System.out.println(m.get(new Pair(currX, currY)));
                        break o;
                    }
                }
            }
        }
    }

    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer t;

    static void get() throws Exception { t = new StringTokenizer(reader.readLine()); }
    static int g() { return Integer.parseInt(t.nextToken()); }
    static int p() throws Exception { return Integer.parseInt(reader.readLine()); }
    static long gL() { return Long.parseLong(t.nextToken()); }
    static long pL() throws Exception { return Long.parseLong(reader.readLine()); }
}