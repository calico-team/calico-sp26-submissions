import java.io.*;

class ThirdProb {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        String real_word = "";
        Integer B_count = 0;
        Integer A_index = 0;
        while (A_index < A.length()) {
            if ( B_count < B.length() && A.charAt(A_index) == B.charAt(B_count) ) {
                    real_word = real_word + A.charAt(A_index);
                    B_count += 1;
            }
            else {
                real_word = real_word + "#";
                }
            A_index += 1;
            }
        return real_word;
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
