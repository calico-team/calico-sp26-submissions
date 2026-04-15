import java.util.*;
import java.io.*;

public class Q12 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int[] R = new int[M];
        int[] C = new int[M];
        int[] W = new int[M];
        int[] deg = new int[N + 1];
        long[] V = new long[M];
        double[] logV = new double[M];

        for (int k = 0; k < M; k++) {
            st = new StringTokenizer(br.readLine());
            R[k] = Integer.parseInt(st.nextToken());
            C[k] = Integer.parseInt(st.nextToken());
            V[k] = Long.parseLong(st.nextToken());
            W[k] = Integer.parseInt(st.nextToken());
            logV[k] = Math.log(V[k]);
            deg[R[k]]++;
            deg[C[k]]++;
        }

        int[][] adj = new int[N + 1][];
        for (int i = 0; i <= N; i++) {
            adj[i] = new int[deg[i]];
        }

        int[] pos = new int[N + 1];
        for (int k = 0; k < M; k++) {
            adj[R[k]][pos[R[k]]++] = k;
            adj[C[k]][pos[C[k]]++] = k;
        }

        boolean[] disc = new boolean[M];
        long MAX_A = (long) 1e9;

        double[] b = new double[N + 1];
        for (int i = 1; i <= N; i++) {
            double num = 0;
            double den = 0;
            for (int k : adj[i]) {
                num += W[k] * logV[k] * 0.5;
                den += W[k];
            }
            b[i] = (den > 0) ? num / den : 0;
        }
        for (int iter = 0; iter < 40; iter++) {
            for (int i = 1; i <= N; i++) {
                double num = 0;
                double den = 0;
                for (int k : adj[i]) {
                    int o = (R[k] == i) ? C[k] : R[k];
                    num += W[k] * (logV[k] - b[o]);
                    den += W[k];
                }
                if (den > 0)
                    b[i] = num / den;
            }
        }

        long[] a = new long[N + 1];
        for (int i = 1; i <= N; i++)
            a[i] = clamp(Math.round(Math.exp(b[i])), MAX_A);

        for (int round = 0; round < 3; round++) {
            if (D > 0)
                selectDiscards(a, R, C, V, W, disc, M, D);

            double[] logA = new double[N + 1];
            for (int i = 1; i <= N; i++)
                logA[i] = Math.log(a[i]);

            for (int pass = 0; pass < 5; pass++) {
                for (int i = 1; i <= N; i++) {
                    if (adj[i].length == 0)
                        continue;

                    double logNum = 0, wDen = 0;
                    for (int k : adj[i]) {
                        if (disc[k])
                            continue;
                        int o = (R[k] == i) ? C[k] : R[k];
                        logNum += W[k] * (logV[k] - logA[o]);
                        wDen += W[k];
                    }
                    if (wDen == 0)
                        continue;

                    long center = clamp(Math.round(Math.exp(logNum / wDen)), MAX_A);

                    long[] cands = new long[6];
                    int nc = 0;
                    for (long c : new long[] { center - 1, center, center + 1,
                            a[i] - 1, a[i], a[i] + 1 }) {
                        if (c < 1 || c > MAX_A)
                            continue;
                        boolean dup = false;
                        for (int j = 0; j < nc; j++) {
                            if (cands[j] == c) {
                                dup = true;
                                break;
                            }
                        }
                        if (!dup)
                            cands[nc++] = c;
                    }

                    long bestVal = a[i];
                    double bestPen = Double.MAX_VALUE;
                    for (int ci = 0; ci < nc; ci++) {
                        long nv = cands[ci];
                        double pen = 0;
                        for (int k : adj[i]) {
                            if (disc[k])
                                continue;
                            int o = (R[k] == i) ? C[k] : R[k];
                            pen += W[k] * Math.abs((double) nv * a[o] - V[k]) / V[k];
                        }
                        if (pen < bestPen) {
                            bestPen = pen;
                            bestVal = nv;
                        }
                    }
                    a[i] = bestVal;
                    logA[i] = Math.log(a[i]);
                }
            }
        }

        if (D > 0)
            selectDiscards(a, R, C, V, W, disc, M, D);
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (i > 1)
                sb.append(" ");
            sb.append(a[i]);
        }
        sb.append("\n");

        int dCount = 0;
        for (int k = 0; k < M; k++)
            if (disc[k])
                dCount++;
        sb.append(dCount);
        for (int k = 0; k < M; k++)
            if (disc[k]) {
                sb.append(" ");
                sb.append(k + 1);
            }
        sb.append("\n");
        System.out.print(sb);
    }

    public static long clamp(long v, long maxA) {
        return Math.max(1, Math.min(maxA, v));
    }

    public static void selectDiscards(long[] a, int[] R, int[] C, long[] V,
            int[] W, boolean[] disc, int M, int D) {
        if (D >= M) {
            Arrays.fill(disc, true);
            return;
        }

        double[] pen = new double[M];
        for (int k = 0; k < M; k++)
            pen[k] = W[k] * Math.abs((double) a[R[k]] * a[C[k]] - V[k]) / V[k];

        double[] sorted = pen.clone();
        Arrays.sort(sorted);
        double threshold = sorted[M - D];
        Arrays.fill(disc, false);
        int count = 0;
        for (int k = 0; k < M && count < D; k++)
            if (pen[k] > threshold) {
                disc[k] = true;
                count++;
            }
        for (int k = 0; k < M && count < D; k++)
            if (!disc[k] && pen[k] >= threshold) {
                disc[k] = true;
                count++;
            }
    }
}
