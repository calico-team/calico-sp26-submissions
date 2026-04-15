import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

class mycelium_template {

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
        List<int[]> grassFrontier = new LinkedList<>();
        List<int[]> myceliumFrontier = new LinkedList<>();

        Set<Long> grass = new HashSet<>();
        Set<Long> mycelium = new HashSet<>();

        grassFrontier.add(new int[]{X_G, Y_G});
        myceliumFrontier.add(new int[]{X_M, Y_M});

        grass.add(key(X_G, Y_G));
        mycelium.add(key(X_M, Y_M));

        while (true) {
            List<int[]> nextGrass = new LinkedList<>();
            List<int[]> nextMycelium = new LinkedList<>();

            expand(grassFrontier, nextGrass, grass, mycelium);
            expand(grassFrontier, nextGrass, grass, mycelium);

            boolean myceliumGrew = false;
            for (int t = 0; t < 7; t++) {
                List<int[]> tmp = new LinkedList<>();
                expand(myceliumFrontier, tmp, mycelium, grass);
                if (!tmp.isEmpty()) myceliumGrew = true;
                myceliumFrontier = tmp;
                nextMycelium.addAll(tmp);
                if (myceliumFrontier.isEmpty()) break;
            }

            grassFrontier = nextGrass;
            myceliumFrontier = nextMycelium;

            if (!myceliumGrew) break;
        }

        return mycelium.size();
    }

    static long key(int x, int y) {
        return (((long) x) << 32) ^ (y & 0xffffffffL);
    }

    static void expand(List<int[]> frontier, List<int[]> next, Set<Long> own, Set<Long> other) {
        for (int[] xy : frontier) {
            tryAdd(next, own, other, xy[0] - 1, xy[1] - 1);
            tryAdd(next, own, other, xy[0] + 1, xy[1] + 1);
            tryAdd(next, own, other, xy[0] - 1, xy[1] + 1);
            tryAdd(next, own, other, xy[0] + 1, xy[1] - 1);
        }
    }

    static void tryAdd(List<int[]> target, Set<Long> own, Set<Long> other, int x, int y) {
        long k = key(x, y);
        if (!own.contains(k) && !other.contains(k)) {
            own.add(k);
            target.add(new int[]{x, y});
        }
    }

}
