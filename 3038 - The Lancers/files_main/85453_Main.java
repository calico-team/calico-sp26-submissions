import java.io.*;

class Main {
    /**
     * For each test case, output the result of redacting the initial string A.
     * 
     * A: the initial string
     * B: the target string
     */
    static String solve(String A, String B) {
        // YOUR CODE HERE
        String copy = A;
        int indexA = 0;
        String[] thing = new String[copy.length()];
        for(int i = 0; i < copy.length(); i++) {
            thing[i] = copy.substring(i, i + 1);
        }
        for(int i = 0; i < B.length(); i++) {
            while(!copy.substring(indexA, indexA + 1).equals(B.substring(i, i + 1))) {
                thing[indexA] = "#";
                indexA++;
            }
            indexA++;
        }
        if(indexA < copy.length()) {
            for(int i = indexA; i < copy.length(); i++) {
                thing[i] = "#";
            }
        }
        String answer = "";
        for(int i = 0; i < thing.length; i++) {
            answer += thing[i];
        }
        return answer;
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
