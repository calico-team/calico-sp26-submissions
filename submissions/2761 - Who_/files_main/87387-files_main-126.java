import java.util.*;

public class Tester {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();
        while (t-- > 0) {
            String str1 = scanner.nextLine();
            String str2 = scanner.nextLine();
            char[] result = str1.toCharArray();
            int j = 0;
            for (int i = 0; i < str1.length(); i++) {
                if (j < str2.length() && str1.charAt(i) == str2.charAt(j)) {
                    j++;
                } else {
                    result[i] = '#';
                }
            }
            System.out.println(new String(result));
        }
    }
}