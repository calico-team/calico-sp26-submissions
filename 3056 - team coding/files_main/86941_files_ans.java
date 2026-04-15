import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        String redacted = "";
        int i = 0
        for (int x = 0; x < A.length(); x++) {
            if (i < B.length() && A.charAt[x].equals(B.charAt[i])) {
                redacted = redacted + Character.toString(A.charAt[x]);
                i++;
            } else {
                redacted = redacted + "#";
            }
        }
        return redacted;
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
