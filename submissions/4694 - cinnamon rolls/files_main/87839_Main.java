import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();

        while (T-- > 0) {
            String A = sc.next();
            String B = sc.next();

            StringBuilder result = new StringBuilder();
            int bIndex = 0;

            for (int i = 0; i < A.length(); i++) {
                char charA = A.charAt(i);

                if (bIndex < B.length() && charA == B.charAt(bIndex)) {
                    result.append(charA);
                    bIndex++;
                } else {
                    result.append('#');
                }
            }
            System.out.println(result.toString());
        }
    }
}