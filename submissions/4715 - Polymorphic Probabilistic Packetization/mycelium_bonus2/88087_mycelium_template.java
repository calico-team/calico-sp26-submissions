import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class mycelium_template {

    static final int GRASS = 0;
    static final int MYCELIUM = 1;

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] temp = in.readLine().split(" ");
            int X_G = Integer.parseInt(temp[0]), Y_G = Integer.parseInt(temp[1]);
            int X_M = Integer.parseInt(temp[2]), Y_M = Integer.parseInt(temp[3]);
            out.println(solve(X_G, Y_G, X_M, Y_M));
        }
        out.flush();
    }

    static int solve(int X_G, int Y_G, int X_M, int Y_M) {
        int d = Math.abs(X_G - X_M) + Math.abs(Y_G - Y_M);
        int R = 2 * d + 10;

        int minX = Math.min(X_G, X_M) - R;
        int maxX = Math.max(X_G, X_M) + R;
        int minY = Math.min(Y_G, Y_M) - R;
        int maxY = Math.max(Y_G, Y_M) + R;

        PriorityQueue<State> pq = new PriorityQueue<>();
        Map<Long, Integer> owner = new HashMap<>();

        occupy(owner, X_G, Y_G, GRASS);
        occupy(owner, X_M, Y_M, MYCELIUM);

        pq.add(new State(2, GRASS, X_G - 1, Y_G));
        pq.add(new State(2, GRASS, X_G + 1, Y_G));
        pq.add(new State(2, GRASS, X_G, Y_G - 1));
        pq.add(new State(2, GRASS, X_G, Y_G + 1));

        pq.add(new State(7, MYCELIUM, X_M - 1, Y_M));
        pq.add(new State(7, MYCELIUM, X_M + 1, Y_M));
        pq.add(new State(7, MYCELIUM, X_M, Y_M - 1));
        pq.add(new State(7, MYCELIUM, X_M, Y_M + 1));

        int myceliumCount = 1;

        while (!pq.isEmpty()) {
            State cur = pq.poll();

            if (cur.x < minX || cur.x > maxX || cur.y < minY || cur.y > maxY) continue;

            long k = key(cur.x, cur.y);
            if (owner.containsKey(k)) continue;

            owner.put(k, cur.type);
            if (cur.type == MYCELIUM) myceliumCount++;

            int step = (cur.type == GRASS ? 2 : 7);

            pq.add(new State(cur.time + step, cur.type, cur.x - 1, cur.y));
            pq.add(new State(cur.time + step, cur.type, cur.x + 1, cur.y));
            pq.add(new State(cur.time + step, cur.type, cur.x, cur.y - 1));
            pq.add(new State(cur.time + step, cur.type, cur.x, cur.y + 1));
        }

        return myceliumCount;
    }

    static void occupy(Map<Long, Integer> owner, int x, int y, int type) {
        owner.put(key(x, y), type);
    }

    static long key(int x, int y) {
        return (((long) x) << 32) ^ (y & 0xffffffffL);
    }

    static class State implements Comparable<State> {

        long time;
        int type;
        int x, y;

        State(long time, int type, int x, int y) {
            this.time = time;
            this.type = type;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(State other) {
            if (time != other.time) return Long.compare(time, other.time);
            return Integer.compare(type, other.type); // grass first on tie
        }

    }

}
