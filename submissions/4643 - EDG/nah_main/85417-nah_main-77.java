import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JoshContext041203 {
    // 使用快速 I/O 提高大量数据读取速度
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
        int t = Integer.parseInt(tStr);

        while (t-- > 0) {
            int n = sc.nextInt();
            long p = sc.nextLong(); // 初始咒力
            long r = sc.nextLong(); // 反转术式恢复的咒力
            int k = sc.nextInt();   // 触发反转术式需要的击败数

            boolean win = true;

            // 依次处理 N 个咒灵
            for (int i = 1; i <= n; i++) {
                long e = sc.nextLong();

                // 如果已经输了，只需要把当前测试用例剩下的输入读完即可
                if (win) {
                    p -= e; // 消耗咒力

                    if (p < 0) {
                        win = false; // 咒力跌破0，直接失败
                    } else {
                        // 存活并且击败数量是 K 的倍数，恢复咒力
                        if (i % k == 0) {
                            p += r;
                        }
                    }
                }
            }

            // 输出结果
            if (win) {
                System.out.println("nah i'd win");
            } else {
                System.out.println("nah i'd lose");
            }
        }
    }
}