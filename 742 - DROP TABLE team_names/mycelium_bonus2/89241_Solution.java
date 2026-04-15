import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    /**
     * Return the total number of tiles mycelium will ever occupy.
     *
     * X_G: x-coordinate of grass starting position
     * Y_G: y-coordinate of grass starting position
     * X_M: x-coordinate of mycelium starting position
     * Y_M: y-coordinate of mycelium starting position
     */
    static HashMap<Tile, Character> map = new HashMap<>();

    static int solve(int X_G, int Y_G, int X_M, int Y_M) {
        int iteration = 1;
        map.clear();
        map.put(new Tile(X_G, Y_G), 'g');
        map.put(new Tile(X_M, Y_M), 'm');
        boolean running = tick(iteration);
        while (running) {
            iteration++;
            running = tick(iteration);
        }

        return (int) map.values().stream().filter(c -> c == 'm').count();
    }

    static boolean tick(int iteration) {
        boolean mycTick = false;
        boolean myceliumMoved = false;
        if ((iteration % 2) == 0) {
            for (Tile t : new ArrayList<>(map.keySet())) {
                if (map.get(t) == 'g')
                    move('g', t);
            }
        }
        if ((iteration % 7) == 0) {
            mycTick = true;
            for (Tile t : new ArrayList<>(map.keySet())) {
                if (map.get(t) == 'm')
                    myceliumMoved = myceliumMoved | move('m', t); // kms
            }
        }
        if (!mycTick)
            return true;
        return myceliumMoved;

    }

    static boolean move(char c, Tile origin) {
        boolean moved = false;
        if (!map.containsKey(new Tile(origin.x, origin.y + 1))) { // up
            map.put(new Tile(origin.x, origin.y + 1), c);
            moved = true;
        }
        if (!map.containsKey(new Tile(origin.x - 1, origin.y))) { // left
            map.put(new Tile(origin.x - 1, origin.y), c);
            moved = true;
        }
        if (!map.containsKey(new Tile(origin.x, origin.y - 1))) { // down
            map.put(new Tile(origin.x, origin.y - 1), c);
            moved = true;
        }
        if (!map.containsKey(new Tile(origin.x + 1, origin.y))) { // right
            map.put(new Tile(origin.x + 1, origin.y), c);
            moved = true;
        }
        return moved;
    }

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
}

class Tile {
    public int x, y = 0;

    Tile(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int hashCode() {
        return 31 * x + y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Tile t = (Tile) o;
        return x == t.x && y == t.y;
    }

}
