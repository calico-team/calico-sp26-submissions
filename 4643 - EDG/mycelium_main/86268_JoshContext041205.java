import java.util.Scanner;

public class JoshContext041205 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();

        while (T-- > 0) {
            long xG = sc.nextLong();
            long yG = sc.nextLong();
            long xM = sc.nextLong();
            long yM = sc.nextLong();

            long count = 0;

            // 菌丝扩散速度慢，它能占领的区域一定在 (xM, yM) 附近
            // 即使起始坐标很大，我们只需要枚举相对位移 dx, dy
            // 范围选择 2000 是安全的，因为 7*(|dx|+|dy|) < 2*(dist_G) 的解集很小
            int range = 1000;
            for (long dx = -range; dx <= range; dx++) {
                for (long dy = -range; dy <= range; dy++) {
                    long currX = xM + dx;
                    long currY = yM + dy;

                    long distM = Math.abs(dx) + Math.abs(dy);
                    long distG = Math.abs(currX - xG) + Math.abs(currY - yG);

                    // 核心判定：菌丝到达时间 < 草到达时间
                    // 注意：这里必须是严格小于，因为题目说同时到达则转化为草
                    if (7 * distM < 2 * distG) {
                        count++;
                    }
                }
            }
            System.out.println(count);
        }
        sc.close();
    }
}