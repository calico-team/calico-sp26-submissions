import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        for(int i = 0; i<A.length(); i++){
            if(A.substring(i, i+1).equals(" ")){
                continue;
            }
            if(A.charAt(i) != B.charAt(0)){
                A = A.substring(0, i)+ '#' + A.substring(i+1);
                if (B.length()>1){
                    B = B.substring(1);
                } else {
                    for (int j = 0; j<A.length(); j++){
                        A = A.substring(0, i)+ '#' + A.substring(i+1);
                    }
                }
            }
        }
        return A;
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
