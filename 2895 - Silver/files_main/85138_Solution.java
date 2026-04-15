import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     *
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        StringBuilder sb = new StringBuilder();
        int pointerA = 0;
        int pointerB = 0;
        while(pointerB < B.length()){
            if(A.charAt(pointerA) == B.charAt(pointerB)){
                sb.append(A.charAt(pointerA));
                pointerA++;
                pointerB++;
            }else{
                sb.append('#');
                pointerA++;
            }
        }
        while(pointerA < A.length()){
            sb.append('#');
            pointerA++;
        }
        return sb.toString();
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