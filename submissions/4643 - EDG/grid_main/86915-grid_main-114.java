import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JoshContext041207 {
    // 快速 I/O 类，应对 Bonus 测试集的大规模数据读取
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String tStr = sc.next();
        if (tStr == null) return;
        int T = Integer.parseInt(tStr);

        while (T-- > 0) {
            int N = sc.nextInt();
            long[] A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = sc.nextLong();
            }

            // 特判 N=1 的情况
            if (N == 1) {
                System.out.println(A[0]);
                continue;
            }

            // L 和 R 数组用于记录每个位置候选值的上下界
            long[] L = new long[N];
            long[] R = new long[N];

            L[0] = A[0];
            R[0] = A[0];

            // 1. 正向寻找最优解平台
            for (int i = 1; i < N; i++) {
                if (A[i] > R[i - 1]) {
                    L[i] = R[i - 1];
                    R[i] = A[i];
                } else if (A[i] < L[i - 1]) {
                    L[i] = A[i];
                    R[i] = L[i - 1];
                } else { // L[i - 1] <= A[i] <= R[i - 1]
                    L[i] = A[i];
                    R[i] = A[i];
                }
            }

            long[] b = new long[N];
            // 最后一个位置在合法区间内任取一个值即可，这里取下界 L
            b[N - 1] = L[N - 1];

            // 2. 反向回溯，贪心确定每个 b[i]
            for (int i = N - 2; i >= 0; i--) {
                b[i] = Math.max(L[i], Math.min(R[i], b[i + 1]));
            }

            // 使用 StringBuilder 快速拼接输出内容
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                sb.append(b[i]);
                if (i != N - 1) {
                    sb.append(" ");
                }
            }
            System.out.println(sb.toString());
        }
    }
}