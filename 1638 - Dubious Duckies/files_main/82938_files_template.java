import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        int pointer = 0;
        String str = "";

        for (int i = 0; i < A.length() && pointer < B.length(); i++) {
            if (A.charAt(i) == B.charAt(pointer)) {
                str += A.charAt(i);
                pointer++;
            } else {
                str += '#';
            }
        }

        if (str.length() < A.length()) {
            int len = A.length() - str.length();
            while (len != 0) {
                str += '#';
                len--;
            }
        }

        return str;
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
