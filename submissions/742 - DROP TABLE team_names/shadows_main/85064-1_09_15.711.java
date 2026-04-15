import java.io.*;

class Solution {
    /**
     * Return the maximal and minimal volume of the shape (in that order)
     *
     * N: max dimensions of shape
     * S1: projection (shadow) in X-Z plane
     * S2: projection (shadow) in Y-Z plane
     */
    static String solve(int N, String[] S1, String[] S2) {
        int max = 0;
        int min = 0;
        for (int i = 0; i < N; i++) {
            int a = countChars(S1[i], '#');
            int b = countChars(S2[i], '#');
            max += a * b;
            min += Math.max(a, b);
        }
        return max + " " + min;
    }

    static int countChars(String s, char c) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                count++;
            }
        }
        return count;

    }

    static String combine(String s1, String s2) {
        StringBuilder sb1 = new StringBuilder(s1);
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == '.' && s2.charAt(i) == '#') {
                sb1.setCharAt(i, '#');
            }
        }
        return sb1.toString();
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(in.readLine());
            String[] S1 = new String[N];
            for (int i = 0; i < N; i++) {
                S1[i] = in.readLine();
            }
            String[] S2 = new String[N];
            for (int i = 0; i < N; i++) {
                S2[i] = in.readLine();
            }
            out.println(solve(N, S1, S2));
        }

        out.flush();
        out.close();
        in.close();
    }
}
