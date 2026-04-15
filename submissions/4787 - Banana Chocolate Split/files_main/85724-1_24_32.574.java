import java.io.*;

public class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        // YOUR CODE HERE
        StringBuilder builder = new StringBuilder(A);
        int bChar = 0;
        for (int i = 0; i < A.length(); i++) {
            if (!(A.substring(i, i + 1).equals(B.substring(bChar, bChar + 1)))) {
                builder.replace(i, i + 1, "#");
            } else {
                if (bChar < B.length() - 1) {
                    bChar++;
                } else {
                    for (int j = i + 1; j < A.length(); j++) {
                        builder.replace(j, j + 1, "#");
                    }
                    return(builder.toString());
                }
            }
        }
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
