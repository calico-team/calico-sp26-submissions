import java.util.*;

public class JoshContext041208 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();
        while (T-- > 0) {
            long P = sc.nextLong();
            int A = sc.nextInt();
            int B = sc.nextInt();
            solve(P, A, B);
        }
    }

    static void solve(long P, int A, int B) {
        // 构造一个 3 列宽，长度足以容纳 A+B 个 Splitter 的工厂
        // 第一列：主干道和分流器
        // 第二列：缓冲区/导向带
        // 第三列：收集(出口)或销毁(X)

        int rows = (A + B) * 2 + 1;
        int cols = 3;
        char[][] grid = new char[rows][cols];
        for (char[] row : grid) Arrays.fill(row, '.');

        long currentP = P;
        int currRow = 0;

        // 处理 A 个二分器 (基数为2)
        for (int i = 0; i < A; i++) {
            grid[currRow][0] = 'S';
            grid[currRow][1] = '>';
            // 如果 P 的当前位是 1，收集；否则销毁
            grid[currRow][2] = (currentP % 2 == 1) ? '>' : 'x';
            currentP /= 2;

            grid[currRow + 1][0] = 'v'; // 指向下一个 Splitter
            currRow += 2;
        }

        // 处理 B 个三分器 (基数为3)
        for (int i = 0; i < B; i++) {
            grid[currRow][0] = 'S';
            // 三分器需要两个额外出口
            // 出口1：
            grid[currRow][1] = '>';
            grid[currRow][2] = (currentP % 3 >= 1) ? '>' : 'x';
            // 出口2：
            grid[currRow + 1][1] = '>';
            grid[currRow + 1][2] = (currentP % 3 >= 2) ? '>' : 'x';

            currentP /= 3;
            grid[currRow + 1][0] = 'v';
            grid[currRow][0] = 'S'; // 重新确认，Splitter 会分流到右和下

            // 为了让 S 能看到下方是有效格，下方必须是传送带或 X
            // 且不能指向自己。由于指向下方 'v' 是合法的，满足条件。
            currRow += 2;
        }

        // 链条末端
        grid[currRow][0] = 'x';

        // 输出工厂
        System.out.println(rows + " " + cols);
        for (int i = 0; i < rows; i++) {
            System.out.println(new String(grid[i]));
        }
    }
}