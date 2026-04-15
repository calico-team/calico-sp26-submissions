import java.util.Scanner;
import java.util.Arrays;

public class JoshContext041204 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextInt()) {
            int t = scanner.nextInt();

            while (t-- > 0) {
                String a = scanner.next();
                String b = scanner.next();

                // 初始化结果数组，全部用 '#' 填充
                char[] result = new char[a.length()];
                Arrays.fill(result, '#');

                int j = 0; // 追踪字符串 B 的匹配进度

                // 遍历字符串 A
                for (int i = 0; i < a.length(); i++) {
                    // 如果 B 还没有匹配完，且当前 A 的字符与 B 的字符一致
                    if (j < b.length() && a.charAt(i) == b.charAt(j)) {
                        result[i] = a.charAt(i); // 保留该字符
                        j++; // B 的指针后移，匹配下一个字符
                    }
                }

                // 输出修改后的字符串
                System.out.println(new String(result));
            }
        }

        scanner.close();
    }
}