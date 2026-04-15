import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        StringBuilder res = new StringBuilder();
        int j= 0;
        for(int i=0;i<A.length();i++)
        {
            if(j<B.length() && B.charAt(j) == A.charAt(i)){
                res.append(A.charAt(i));
                j++;
            }
            else {
                res.append("#");
            }
        }
        return res.toString();
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
