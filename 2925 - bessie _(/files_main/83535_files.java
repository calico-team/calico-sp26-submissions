import java.io.*;

public class files {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        int ind = 0;
        String ans = "";
        for(int i = 0; i < A.length(); i++) {
            if(ind < B.length() && A.charAt(i) == B.charAt(ind)) {
                ans += A.charAt(i);
                ind++;
            }
            else {
                ans += "#";
            }
        }
        return ans;
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
