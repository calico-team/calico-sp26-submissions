import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        char[] toReturn = new char[A.length()];
        B += ";";
        int bChar = 0;
        for (int aChar = 0; aChar < A.length() ; aChar++) {
            if (A.charAt(aChar) == B.charAt(bChar)) {
                toReturn[aChar] = A.charAt(aChar);
                bChar++;
            }
            else {
                toReturn[aChar] = '#';
            }
        }
        String returnString = new String(toReturn);
        return returnString;
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
