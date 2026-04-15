import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class JoshContext041211 {
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

        int t = Integer.parseInt(tStr);
        // 使用带有缓冲区的 PrintWriter 实现快速输出
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            // 根据同余公式直接计算并输出网格
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    // C(r, c) = (r + 2c) mod 5
                    int value = (r + 2 * c) % 5;
                    out.print(value);

                    if (c < m - 1) {
                        out.print(" ");
                    }
                }
                out.println();
            }
        }

        // 必须 flush 确保所有缓冲区数据输出完整
        out.flush();
    }
}