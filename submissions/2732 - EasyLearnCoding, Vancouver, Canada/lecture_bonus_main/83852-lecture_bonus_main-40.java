import java.util.*;
import java.io.*;

public class AverageClass {

    static int johnny_d_lecture;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            String[] grid = new String[N];
            for (int i = 0; i < N; i++) grid[i] = br.readLine();
            int[][] ans = solve(N, M, K, grid);
            for (int[] s : ans) sb.append(s[0]).append(' ').append(s[1]).append('\n');
        }
        System.out.print(sb);
    }

    static int[][] solve(int N, int M, int K, String[] grid) {

        // ── 1. Collect available seats + aura losses ──────────────────────────
        // aura(r,c) = min(# occupied seats strictly left of c, # occupied seats strictly right of c)
        List<int[]> raw = new ArrayList<>();
        for (int r = 0; r < N; r++) {
            String row = grid[r];
            int occ = 0;
            int[] leftOcc = new int[M];
            for (int c = 0; c < M; c++) {
                leftOcc[c] = occ;
                if (row.charAt(c) == '#') occ++;
            }
            occ = 0;
            for (int c = M - 1; c >= 0; c--) {
                if (row.charAt(c) == '-') raw.add(new int[]{r, c, Math.min(leftOcc[c], occ)});
                else occ++;
            }
        }

        int S = raw.size();
        int[] R = new int[S], C = new int[S], A = new int[S];
        int[] U = new int[S], V = new int[S];
        for (int i = 0; i < S; i++) {
            R[i] = raw.get(i)[0];
            C[i] = raw.get(i)[1];
            A[i] = raw.get(i)[2];
            U[i] = R[i] + C[i];   // rotated coordinate (diagonal)
            V[i] = R[i] - C[i];   // rotated coordinate (anti-diagonal)
        }

        // ── 2. Sort by U, tie-break by V ─────────────────────────────────────
        // Manhattan trick: |r1-r2|+|c1-c2| = max(|U1-U2|, |V1-V2|).
        // K seats all within max distance D ⟺ U-span ≤ D AND V-span ≤ D.
        Integer[] ord = new Integer[S];
        for (int i = 0; i < S; i++) ord[i] = i;
        Arrays.sort(ord, (a, b) -> U[a] != U[b] ? U[a] - U[b] : V[a] - V[b]);

        int[] su = new int[S], sv = new int[S], sa = new int[S], oi = new int[S];
        for (int i = 0; i < S; i++) {
            oi[i] = ord[i];
            su[i] = U[ord[i]];
            sv[i] = V[ord[i]];
            sa[i] = A[ord[i]];
        }

        // ── 3. Binary search on D ─────────────────────────────────────────────
        int lo = 0, hi = 2 * (N + M);
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (canFit(su, sv, S, K, mid)) hi = mid;
            else lo = mid + 1;
        }

        // ── 4. Find the minimum-aura seat set achieving distance D = lo ───────
        int[] bestPos = findBest(su, sv, sa, S, K, lo);

        int[][] result = new int[K][2];
        for (int i = 0; i < K; i++) {
            result[i][0] = R[oi[bestPos[i]]];
            result[i][1] = C[oi[bestPos[i]]];
        }
        return result;
    }

    // ── canFit(D) ─────────────────────────────────────────────────────────────
    // Two pointers on U maintain a sliding U-window with span ≤ D.
    // Inside the window, we use a sorted map on V and a second V two-pointer
    // to check if any V-window of width D contains ≥ K seats.
    // V two-pointer advances monotonically → O(distinct_V) amortized per outer step.
    // Total: O(S log S) (dominated by TreeMap insert/remove).
    static boolean canFit(int[] su, int[] sv, int S, int K, int D) {
        TreeMap<Integer, Integer> vCnt = new TreeMap<>(); // V-value → count in U-window
        int total = 0, left = 0;

        for (int right = 0; right < S; right++) {
            vCnt.merge(sv[right], 1, Integer::sum);
            total++;

            while (su[right] - su[left] > D) {
                int vl = sv[left];
                if (vCnt.merge(vl, -1, Integer::sum) == 0) vCnt.remove(vl);
                total--;
                left++;
            }

            if (total < K) continue;

            // Slide a V-window [vLo, vLo+D] across the sorted V-values.
            // Two pointers: vLo starts at minimum V in window, vHi at the furthest V ≤ vLo+D.
            int seated = 0;
            Integer vLo = vCnt.firstKey();
            Integer vHi = vLo;
            seated = vCnt.get(vLo);

            // Expand vHi as far right as possible within vLo + D
            while (true) {
                Integer next = vCnt.higherKey(vHi);
                if (next == null || next > vLo + D) break;
                vHi = next;
                seated += vCnt.get(vHi);
            }
            if (seated >= K) return true;

            // Slide vLo right, adjusting vHi
            while (true) {
                seated -= vCnt.get(vLo);
                Integer newLo = vCnt.higherKey(vLo);
                if (newLo == null) break;
                vLo = newLo;
                // Expand vHi to cover up to vLo + D
                while (true) {
                    Integer next = vCnt.higherKey(vHi);
                    if (next == null || next > vLo + D) break;
                    vHi = next;
                    seated += vCnt.get(vHi);
                }
                if (seated >= K) return true;
            }
        }
        return false;
    }

    // ── findBest(D) ───────────────────────────────────────────────────────────
    // Same U two-pointer structure. For each valid V-window (V-span ≤ D, count ≥ K),
    // we want the K seats with minimum total aura.
    // We iterate all V-windows (V two-pointer), collect seats, pick K smallest auras.
    // The total work is O(S * window_size) in the worst case, which is acceptable
    // in practice because when D is small, windows are small; when D is large, we
    // find the answer quickly.
    static int[] findBest(int[] su, int[] sv, int[] sa, int S, int K, int D) {
        // vMap: V-value → TreeMap<sorted_pos, aura>. Gives V-sorted iteration + O(log S) ops.
        TreeMap<Integer, TreeMap<Integer, Integer>> vMap = new TreeMap<>();
        int total = 0, left = 0;
        int bestAura = Integer.MAX_VALUE;
        int[] bestPos = null;

        for (int right = 0; right < S; right++) {
            vMap.computeIfAbsent(sv[right], x -> new TreeMap<>()).put(right, sa[right]);
            total++;

            while (su[right] - su[left] > D) {
                TreeMap<Integer, Integer> inner = vMap.get(sv[left]);
                inner.remove(left);
                if (inner.isEmpty()) vMap.remove(sv[left]);
                total--;
                left++;
            }

            if (total < K) continue;

            // Build V-sorted arrays for this U-window
            int[] vArr = new int[total], posArr = new int[total], aArr = new int[total];
            int idx = 0;
            for (Map.Entry<Integer, TreeMap<Integer, Integer>> e : vMap.entrySet()) {
                int vv = e.getKey();
                for (Map.Entry<Integer, Integer> e2 : e.getValue().entrySet()) {
                    vArr[idx] = vv;
                    posArr[idx] = e2.getKey();
                    aArr[idx] = e2.getValue();
                    idx++;
                }
            }

            // Two pointers on V: slide [ii, jj] window with V-span ≤ D
            int jj = 0;
            for (int ii = 0; ii < total; ii++) {
                if (jj < ii) jj = ii;
                while (jj + 1 < total && vArr[jj + 1] - vArr[ii] <= D) jj++;
                int wSize = jj - ii + 1;
                if (wSize < K) continue;

                // From seats in [ii, jj], pick K with minimum aura sum.
                // We want K smallest auras — use a partial sort (nth_element equivalent):
                // copy auras, sort, sum first K.
                int[] winAuras = Arrays.copyOfRange(aArr, ii, jj + 1);
                Arrays.sort(winAuras);
                int winBest = 0;
                for (int p = 0; p < K; p++) winBest += winAuras[p];

                if (winBest < bestAura) {
                    bestAura = winBest;
                    // Find which sorted positions give these K smallest auras.
                    // Min-heap on (aura, pos) picks exactly the K smallest.
                    PriorityQueue<int[]> pq = new PriorityQueue<>(
                            (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]
                    );
                    for (int p = ii; p <= jj; p++) pq.offer(new int[]{aArr[p], posArr[p]});
                    bestPos = new int[K];
                    for (int p = 0; p < K; p++) bestPos[p] = pq.poll()[1];
                }
                if (bestAura == 0) break; // can't improve
            }
            if (bestAura == 0) break;
        }
        return bestPos;
    }
}
