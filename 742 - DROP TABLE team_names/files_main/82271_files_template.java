import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        StringBuilder returned = new StringBuilder();
        int pointer = 0;

        for(int i = 0; i < A.length(); i++) {
            char c = A.charAt(i);

            if(pointer < B.length() && c == B.charAt(pointer)) {
                returned.append(c);
                pointer++;
            } else {
                returned.append('#');
            }

        }

        return returned.toString();
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
