
import java.io.*;

class Solution {

    static String solve(String A, String B) {

        char[] first = A.toCharArray();
        char[] sec = B.toCharArray();

        int len1 = first.length;
        int len2 = sec.length;

        char[] ans = new char[len1];

        int step = 0;
        int matched = 0;

        while (step < len1) {
            ans[step] = '#';
            step = step + 1;
        }
        step = 0;
        while (step < len1 && matched < len2) {
            if (first[step] == sec[matched]) {
                ans[step] = sec[matched];
                matched = matched + 1;
            }
            step = step + 1;
        }

        String output = new String(ans);

        return output;

    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String A = in.readLine();
            String B = in.readLine();
            out.println(solve(A, B));
        }
        out.flush();
    }
}
