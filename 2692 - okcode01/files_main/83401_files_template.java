import java.io.*;

class Solution {
    /**
     * For each test case, output the result of redacting the initial string A.
     *
     * A: the initial string
     * B: the target string
     */
     static String solve(String A, String B) {
         char[] arrA = A.toCharArray();
         char[] arrB = B.toCharArray();
         char[] result = new char[arrA.length];

         int bint = 0;

         for (int i = 0; i < arrA.length; i++) {
             if (bint < arrB.length && arrA[i] == arrB[bint]) {
                 result[i] = arrA[i];
                 bint++;
             }
             else {
                 result[i] = '#';
             }
         }

         return new String(result);
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
