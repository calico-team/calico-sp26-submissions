import java.util.*;
import java.io.*;

public class Q3 {
    public static String solve(String a, String b) {
        char[] ans = a.toCharArray();
        int bIndex = 0;

        for (int i = 0; i < a.length(); i++) {
            if (bIndex < b.length() && a.charAt(i) == b.charAt(bIndex))
                bIndex++;
            else
                ans[i] = '#';
        }
        String str = new String(ans);
        return str;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String a = br.readLine();
            String b = br.readLine();
            System.out.println(solve(a, b));
        }
    }
}
