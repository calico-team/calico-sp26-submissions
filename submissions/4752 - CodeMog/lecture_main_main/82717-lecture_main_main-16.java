import java.io.*;
import java.util.*;

public class Main {
    static int[] auraArr;
    static int[][] seats;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            String[] grid = new String[N];
            for (int i = 0; i < N; i++) grid[i] = br.readLine().trim();

            List<int[]> availList = new ArrayList<>();
            List<Integer> auraList = new ArrayList<>();

            for (int r = 0; r < N; r++) {
                String row = grid[r];
                int[] leftOcc = new int[M];
                int cnt = 0;
                for (int c = 0; c < M; c++) {
                    leftOcc[c] = cnt;
                    if (row.charAt(c) == '#') cnt++;
                }
                int[] rightOcc = new int[M];
                cnt = 0;
                for (int c = M - 1; c >= 0; c--) {
                    rightOcc[c] = cnt;
                    if (row.charAt(c) == '#') cnt++;
                }
                for (int c = 0; c < M; c++) {
                    if (row.charAt(c) == '-') {
                        availList.add(new int[]{r, c});
                        auraList.add(Math.min(leftOcc[c], rightOcc[c]));
                    }
                }
            }

            int n = availList.size();
            seats = availList.toArray(new int[0][]);
            auraArr = new int[n];
            for (int i = 0; i < n; i++) auraArr[i] = auraList.get(i);

            // Binary search on D = max Manhattan distance
            int lo = 0, hi = (N - 1) + (M - 1);
            int[] bestResult = null;
            int bestAura = Integer.MAX_VALUE;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int[] res = tryD(mid, K, n);
                if (res != null) {
                    int totalAura = 0;
                    for (int idx : res) totalAura += auraArr[idx];
                    if (bestResult == null || totalAura < bestAura) {
                        bestResult = res;
                        bestAura = totalAura;
                    }
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            // Output
            for (int idx : bestResult) {
                sb.append(seats[idx][0]).append(' ').append(seats[idx][1]).append('\n');
            }
        }

        System.out.print(sb);
    }

    // Try to find K seats with max pairwise Manhattan dist <= D
    // Strategy: sliding window over sorted seats by (r+c) and (r-c) — use bounding box in rotated coords
    // For Manhattan distance: max |ri-rj|+|ci-cj| = max of (rotated coords differences)
    // In rotated coords u=r+c, v=r-c: Manhattan dist = max(|ui-uj|, |vi-vj|)
    // So max pairwise Manhattan = max(range of u, range of v) among chosen seats
    // We want max(range_u, range_v) <= D
    // => range_u <= D AND range_v <= D
    // Sort by u. Sliding window where u[right]-u[left] <= D, then check if range of v <= D
    // Among valid windows, pick best K by aura.
    static int[] tryD(int D, int K, int n) {
        // Sort seats by u = r+c
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) order[i] = i;
        Arrays.sort(order, (a, b) -> {
            int ua = seats[a][0] + seats[a][1];
            int ub = seats[b][0] + seats[b][1];
            return ua - ub;
        });

        // Sliding window on u, maintain sorted structure on v to get range
        // We want min range_v window of size >= K with range_u <= D
        // Use TreeMap<v, count> for window
        TreeMap<Integer, Integer> vMap = new TreeMap<>();
        int left = 0;
        int[] bestWindow = null;
        int bestAura = Integer.MAX_VALUE;

        for (int right = 0; right < n; right++) {
            int idx = order[right];
            int v = seats[idx][0] - seats[idx][1];
            vMap.merge(v, 1, Integer::sum);

            // Shrink from left while u range > D
            while (true) {
                int ul = seats[order[left]][0] + seats[order[left]][1];
                int ur = seats[order[right]][0] + seats[order[right]][1];
                if (ur - ul <= D) break;
                int lv = seats[order[left]][0] - seats[order[left]][1];
                vMap.merge(lv, -1, Integer::sum);
                if (vMap.get(lv) == 0) vMap.remove(lv);
                left++;
            }

            int windowSize = right - left + 1;
            if (windowSize >= K) {
                int vRange = vMap.lastKey() - vMap.firstKey();
                if (vRange <= D) {
                    // Valid window — pick K seats with min aura
                    int[] candidates = new int[windowSize];
                    for (int i = 0; i < windowSize; i++) candidates[i] = order[left + i];
                    // Sort candidates by aura, pick K smallest
                    Integer[] candIdx = new Integer[windowSize];
                    for (int i = 0; i < windowSize; i++) candIdx[i] = candidates[i];
                    Arrays.sort(candIdx, (a, b) -> auraArr[a] - auraArr[b]);
                    int totalAura = 0;
                    for (int i = 0; i < K; i++) totalAura += auraArr[candIdx[i]];
                    if (bestWindow == null || totalAura < bestAura) {
                        bestAura = totalAura;
                        bestWindow = new int[K];
                        for (int i = 0; i < K; i++) bestWindow[i] = candIdx[i];
                    }
                }
            }
        }

        return bestWindow;
    }

    static void read_your_input() {}
}