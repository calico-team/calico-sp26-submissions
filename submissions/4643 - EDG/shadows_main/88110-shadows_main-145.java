import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JoshContext041210 {
    // 快速 I/O，应对大数据量读取
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
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String tStr = sc.next();
        if (tStr == null) return;
        int T = Integer.parseInt(tStr);

        while (T-- > 0) {
            int N = sc.nextInt();

            // 记录 S1 每一行的 '#' 数量
            int[] R = new int[N];
            for (int i = 0; i < N; i++) {
                String row = sc.next();
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (row.charAt(j) == '#') {
                        count++;
                    }
                }
                R[i] = count;
            }

            // 记录 S2 每一行的 '#' 数量
            int[] C = new int[N];
            for (int i = 0; i < N; i++) {
                String row = sc.next();
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (row.charAt(j) == '#') {
                        count++;
                    }
                }
                C[i] = count;
            }

            long maxVolume = 0;
            long minVolume = 0;

            // 逐层累加计算极值
            for (int i = 0; i < N; i++) {
                maxVolume += (long) R[i] * C[i];
                minVolume += Math.max(R[i], C[i]);
            }

            // 输出结果
            System.out.println(maxVolume + " " + minVolume);
        }
    }
}