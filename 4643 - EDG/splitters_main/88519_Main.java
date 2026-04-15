import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine(); // 处理换行符

        for (int i = 0; i < T; i++) {
            String A = sc.nextLine();
            String B = sc.nextLine();
            System.out.println(solve(A, B));
        }
        sc.close();
    }

    public static String solve(String original, String target) {
        char[] arr = original.toCharArray();
        int ptr = 0;

        // 第一遍：按顺序匹配target字符
        for (int i = 0; i < arr.length && ptr < target.length(); i++) {
            if (arr[i] == target.charAt(ptr)) {
                ptr++;
            } else {
                arr[i] = '#';
            }
        }

        // 第二遍：确保多余字符全替换为#
        for (int i = 0; i < arr.length; i++) {
            boolean keep = false;
            int temp = 0;
            for (int j = 0; j <= i && temp < target.length(); j++) {
                if (original.charAt(j) == target.charAt(temp)) {
                    temp++;
                    if (j == i) keep = true;
                }
            }
            if (!keep) arr[i] = '#';
        }

        return new String(arr);
    }
}