import java.util.Scanner;

public class JoshContext041202 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 读取测试用例数量
        if (scanner.hasNextInt()) {
            int t = scanner.nextInt();

            while (t-- > 0) {
                int l = scanner.nextInt(); // 长度
                int w = scanner.nextInt(); // 宽度
                int e = scanner.nextInt(); // 需要的总电量
                int r = scanner.nextInt(); // 每步(米)产生的电量

                // 计算跑一圈产生的电量
                int electricityPerLap = 2 * (l + w) * r;

                // 计算所需圈数并输出
                System.out.println(e / electricityPerLap);
            }
        }

        scanner.close();
    }
}