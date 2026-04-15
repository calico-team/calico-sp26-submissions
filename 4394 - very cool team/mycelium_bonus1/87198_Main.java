import java.io.*;
import java.util.*;

record Pair(int a, int b) {}

public class Main {
    static int[][] pos = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };

    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            HashMap<Pair, Integer> visited = new HashMap<>();
            Queue<Pair> grass = new ArrayDeque<>();
            Queue<Pair> m = new ArrayDeque<>();

            int time = 0;
            get();
            int XG = g(), YG = g(), XM = g(), YM = g();
            grass.add(new Pair(XG, YG));
            m.add(new Pair(XM, YM));
            visited.put(new Pair(XG, YG), 0);
            visited.put(new Pair(XM, YM), 1);

            int count = 1;

            while (!m.isEmpty()) {
                time += 1;

                if (time % 2 == 0){
                    int gA = grass.size();
                    for (int j = 0; j < gA; j++) {
                        Pair next = grass.poll();
                        for(int[] p : pos) {
                            int X = next.a() + p[0];
                            int Y = next.b() + p[1];
                            Pair pair = new Pair(X, Y);
                            if (!visited.containsKey(pair)) {
                                visited.put(pair, 0);
                                grass.add(pair);
                            }
                        }
                    }
                }

                if (time % 7 == 0) {
                    int mA = m.size();
                    for (int j = 0; j < mA; j++) {
                        Pair next = m.poll();
                        for(int[] p : pos) {
                            int X = next.a() + p[0];
                            int Y = next.b() + p[1];
                            Pair pair = new Pair(X, Y);
                            if (!visited.containsKey(pair)) {
                                visited.put(pair, 1);
                                m.add(pair);
                                count++;
                            }
                        }
                    }
                }
            }

            System.out.println(count);
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