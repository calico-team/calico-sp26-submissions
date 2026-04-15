import java.io.*;

class Solution {
    /**
     * Return the maximal and minimal volume of the shape (in that order)
     *
     * N: max dimensions of shape
     * S1: projection (shadow) in X-Z plane
     * S2: projection (shadow) in Y-Z plane
     */
    static int count(String s) {
        char[] c = s.toCharArray();
        int co = 0;
        for (int i = 0; i < s.length(); i++) {
            if(c[i] == '#')co++;
        }
        return co;
    }
    static String solve(int N, String[] S1, String[] S2) {
        int max = 0, min = 0;
        for (int i = 0; i < N; i++) { //height
            String strRow = S1[i];
            String strCol = S2[i];
            max += count(strCol) * count(strRow);
            
            min += Math.max(count(strCol), count(strRow));
            /*
            char[] rc= strRow.toCharArray();
            char[] cc= strCol.toCharArray();

            ArrayList<Integer>helpRows = new ArrayList<>();
            ArrayList<Integer>helpCols = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if(rc[j] == '#') helpRows.add(j);
                if(cc[j] == '#') helpCols.add(j);
            }*/
        }
        return max + " " + min;
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
