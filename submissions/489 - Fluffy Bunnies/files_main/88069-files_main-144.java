import java.io.*;

public class Solution2 {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        int i = 0; // counter for A
        int n = 0; // counter for B
        
        StringBuilder sb = new StringBuilder();
        
        while (i < A.length()) {
	        if (n < B.length() && A.charAt(i) == B.charAt(n)) {
	        	sb.append(A.charAt(i));
	        	
	        	i++;
	        	n++;
	        } else {
	        	sb.append('#');
	        	i++;
	        }
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
