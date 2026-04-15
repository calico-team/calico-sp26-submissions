import java.util.*;
import java.io.*;

public class problem8 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long P = Long.parseLong(st.nextToken());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            List<String> factory = buildValidFactory(P, A, B);
            System.out.println(factory.size() + " " + factory.get(0).length());
            for (String row : factory) {
                System.out.println(row);
            }
        }
        br.close();
    }

    private static List<String> buildValidFactory(long P, int A, int B) {
        List<StringBuilder> grid = new ArrayList<>();
        // 初始化：起点(0,0)为右向传送带
        grid.add(new StringBuilder(">"));
        int rows = 1;
        int cols = 1;

        // ========== 1. 构建A层二分分流器链 ==========
        for (int i = 0; i < A; i++) {
            // 步骤1：先给所有行追加 '.'，扩展列数
            cols++;
            for (StringBuilder row : grid) {
                row.append('.');
            }
            // 给第0行最后一列设置 '>'
            grid.get(0).setCharAt(cols - 1, '>');

            // 步骤2：再追加一列，放置分流器S
            cols++;
            for (StringBuilder row : grid) {
                row.append('.');
            }
            grid.get(0).setCharAt(cols - 1, 'S');

            // 步骤3：向下新增一行，给S的正下方设置 'v'
            rows++;
            StringBuilder newRow = new StringBuilder();
            // 新行长度和当前cols一致，全填 '.'
            for (int j = 0; j < cols; j++) {
                newRow.append('.');
            }
            newRow.setCharAt(cols - 1, 'v'); // S的正下方是v，合法相邻
            grid.add(newRow);

            // 步骤4：给两行各追加一个 '>'，为下一层做准备
            cols++;
            grid.get(0).append('>');
            grid.get(1).append('>');
        }

        // ========== 2. 构建B层三分分流器链 ==========
        for (int i = 0; i < B; i++) {
            // 步骤1：先给所有行追加 '.'，扩展列数
            cols++;
            for (StringBuilder row : grid) {
                row.append('.');
            }
            // 给第0行最后一列设置 '>'
            grid.get(0).setCharAt(cols - 1, '>');

            // 步骤2：再追加一列，放置分流器S
            cols++;
            for (StringBuilder row : grid) {
                row.append('.');
            }
            grid.get(0).setCharAt(cols - 1, 'S');

            // 步骤3：给S的正下方两行设置 'v'，不足则新增行
            for (int r = 1; r <= 2; r++) {
                if (r >= rows) {
                    // 新增行，长度和当前cols一致
                    StringBuilder nr = new StringBuilder();
                    for (int j = 0; j < cols; j++) nr.append('.');
                    nr.setCharAt(cols - 1, 'v');
                    grid.add(nr);
                    rows++;
                } else {
                    // 已有行，直接设置
                    grid.get(r).setCharAt(cols - 1, 'v');
                }
            }

            // 步骤4：给前三行各追加一个 '>'，为下一层做准备
            cols++;
            for (int r = 0; r < 3; r++) {
                grid.get(r).append('>');
            }
            // 给剩余行补 '.'，保证所有行长度一致
            for (int r = 3; r < rows; r++) {
                grid.get(r).append('.');
            }
        }

        // ========== 3. 构建P条收集路径，其余销毁 ==========
        // 先给所有行追加一列 '.'，保证索引cols-1合法
        cols++;
        for (StringBuilder row : grid) {
            row.append('.');
        }
        int totalPaths = (int) P;
        for (int r = 0; r < rows; r++) {
            if (r < totalPaths) {
                // 收集路径：设置 'v'，出界收集
                grid.get(r).setCharAt(cols - 1, 'v');
            } else {
                // 销毁路径：设置 'X'
                grid.get(r).setCharAt(cols - 1, 'X');
            }
        }

        // ========== 4. 保证所有行长度完全一致 ==========
        for (StringBuilder row : grid) {
            while (row.length() < cols) {
                row.append('.');
            }
        }

        // ========== 5. 转换为字符串列表返回 ==========
        List<String> res = new ArrayList<>();
        for (StringBuilder row : grid) {
            res.add(row.toString());
        }
        return res;
    }
}