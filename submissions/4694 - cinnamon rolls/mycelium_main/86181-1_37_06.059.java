import java.util.*;
import java.io.*;

public class Main {
    static final long NE = 1_200_000_000L;
    static final long ML = 2 * NE + 1;
    static final long[] DX = {0, 0, 1, -1};
    static final long[] DY = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long xg = Long.parseLong(st.nextToken()), yg = Long.parseLong(st.nextToken());
            long xm = Long.parseLong(st.nextToken()), ym = Long.parseLong(st.nextToken());
            sb.append(solve(xg, yg, xm, ym)).append('\n');
        }
        System.out.print(sb);
    }

    static long enc(long x, long y) { return (x + NE) * ML + (y + NE); }
    static long decX(long k) { return k / ML - NE; }
    static long decY(long k) { return k % ML - NE; }

    static boolean hasEmpty(long k, HashMap<Long, Byte> grid) {
        long x = decX(k), y = decY(k);
        for (int d = 0; d < 4; d++)
            if (!grid.containsKey(enc(x + DX[d], y + DY[d]))) return true;
        return false;
    }

    static long solve(long xg, long yg, long xm, long ym) {
        HashMap<Long, Byte> grid = new HashMap<>();
        Set<Long> gF = new HashSet<>(), mF = new HashSet<>();

        long gk = enc(xg, yg), mk = enc(xm, ym);
        grid.put(gk, (byte) 1); gF.add(gk);
        grid.put(mk, (byte) 2); mF.add(mk);
        long count = 1;

        for (int tick = 1; !mF.isEmpty(); tick++) {
            boolean gT = tick % 2 == 0, mT = tick % 7 == 0;
            if (!gT && !mT) continue;

            Set<Long> newG = new HashSet<>(), newM = new HashSet<>();

            if (gT) {
                for (long k : gF) {
                    long x = decX(k), y = decY(k);
                    for (int d = 0; d < 4; d++) {
                        long nk = enc(x + DX[d], y + DY[d]);
                        if (!grid.containsKey(nk)) newG.add(nk);
                    }
                }
            }

            if (mT) {
                for (long k : mF) {
                    long x = decX(k), y = decY(k);
                    for (int d = 0; d < 4; d++) {
                        long nk = enc(x + DX[d], y + DY[d]);
                        if (!grid.containsKey(nk) && !newG.contains(nk)) newM.add(nk);
                    }
                }
            }

            for (long k : newG) grid.put(k, (byte) 1);
            for (long k : newM) { grid.put(k, (byte) 2); count++; }

            if (gT) {
                Set<Long> newGF = new HashSet<>();
                for (long k : gF) if (hasEmpty(k, grid)) newGF.add(k);
                for (long k : newG) if (hasEmpty(k, grid)) newGF.add(k);
                gF = newGF;
            }

            Set<Long> newMF = new HashSet<>();
            for (long k : mF) if (hasEmpty(k, grid)) newMF.add(k);
            for (long k : newM) if (hasEmpty(k, grid)) newMF.add(k);
            mF = newMF;
        }

        return count;
    }

    static void read_your_input() throws IOException {
        System.setIn(new FileInputStream("input.txt"));
    }
}