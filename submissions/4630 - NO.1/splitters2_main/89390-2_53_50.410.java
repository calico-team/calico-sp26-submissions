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
        int rows = 1;
        int cols = 1;
        grid.add(new StringBuilder(">")); // 起点(0,0)右向传送带，符合规则

        // 1. 构建A层二分分流器链，严格遵循分流器规则
        for (int i = 0; i < A; i++) {
            // 扩展列，添加右向传送带
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, '>');

            // 添加分流器S，确保不与边界/其他S相邻
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, 'S');

            // 向下扩展一行，添加v向传送带（合法相邻格，非反向）
            rows++;
            StringBuilder newRow = new StringBuilder();
            for (int j = 0; j < cols; j++) newRow.append('.');
            newRow.setCharAt(cols - 1, 'v'); // S的正下方为v，不反向指向S
            grid.add(newRow);

            // 两行末尾添加>，为下一层做准备
            grid.get(0).append('>');
            grid.get(1).append('>');
            cols++;
        }

        // 2. 构建B层三分分流器链，严格遵循分流器规则
        for (int i = 0; i < B; i++) {
            // 扩展列，添加右向传送带
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, '>');

            // 添加分流器S，确保不与边界/其他S相邻
            cols++;
            for (StringBuilder row : grid) row.append('.');
            grid.get(0).setCharAt(cols - 1, 'S');

            // 向下扩展两行，添加v向传送带（合法相邻格，非反向）
            for (int r = 1; r <= 2; r++) {
                if (rows <= r) {
                    StringBuilder newRow = new StringBuilder();
                    for (int j = 0; j < cols; j++) newRow.append('.');
                    newRow.setCharAt(cols - 1, 'v');
                    grid.add(newRow);
                    rows++;
                } else {
                    grid.get(r).setCharAt(cols - 1, 'v');
                }
            }

            // 三行末尾添加>，为下一层做准备
            for (int r = 0; r < 3; r++) grid.get(r).append('>');
            cols++;
        }

        // 3. 构建P条收集路径，其余路径销毁，严格对应比例
        int totalPaths = (int) P;
        int maxRows = rows;
        // 扩展列，添加收集/销毁格
        cols++;
        for (StringBuilder row : grid) row.append('.');
        for (int r = 0; r < maxRows; r++) {
            if (r < totalPaths) {
                // 收集路径：添加v，出界收集
                grid.get(r).setCharAt(cols - 1, 'v');
            } else {
                // 销毁路径：添加X，销毁物品
                grid.get(r).setCharAt(cols - 1, 'X');
            }
        }
	// 4. 填充空格，确保矩形完整，且空格不可达
        for (StringBuilder row : grid) {
            while (row.length() < cols) row.append('.');
        }

        // 5. 验证所有规则（调试用，提交可删除）
        validateFactory(grid, A, B, P);

        // 转换为字符串列表
        List<String> res = new ArrayList<>();
        for (StringBuilder row : grid) res.add(row.toString());
        return res;
    }

    // 验证工厂是否符合所有题目规则
    private static void validateFactory(List<StringBuilder> grid, int A, int B, long P) {
        int rows = grid.size();
        int cols = grid.get(0).length();
        // 验证总格子数≤2000
        if (rows * cols > 2000) throw new RuntimeException("Grid size exceeds 2000");
        // 验证起点为传送带
        char start = grid.get(0).charAt(0);
        if (start != '>' && start != '<' && start != '^' && start != 'v')
            throw new RuntimeException("Start tile is not a conveyor");
        // 验证分流器不与边界/其他分流器相邻
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid.get(i).charAt(j) == 'S') {
                    // 验证不与边界相邻
                    if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                        throw new RuntimeException("Splitter adjacent to boundary");
                    // 验证不与其他分流器相邻
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            if (grid.get(ni).charAt(nj) == 'S')
                                throw new RuntimeException("Splitter adjacent to another splitter");
                        }
                    }
                }
            }
        }
    }
}