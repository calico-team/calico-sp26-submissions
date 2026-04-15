import java.util.Scanner;

public class files_template {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();
        sc.nextLine();

        while (T-- > 0) {
            String a = sc.nextLine();
            String b = sc.nextLine();

            StringBuilder ans = new StringBuilder();
            int bIdx = 0;
            int bLen = b.length();
            for (int i = 0; i < a.length(); i++) {
                char currentChar = a.charAt(i);
                if (bIdx < bLen && currentChar == b.charAt(bIdx)) {
                    ans.append(currentChar);
                    bIdx++;
                }else{
                    ans.append('#');
                }
            }
            System.out.println(ans.toString());
        }
        sc.close();
    }
}