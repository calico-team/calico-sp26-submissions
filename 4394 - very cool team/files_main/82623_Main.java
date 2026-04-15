import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            String one = reader.readLine();
            String two = reader.readLine();
            StringBuilder s = new StringBuilder();
            int curri = 0;
            for (int j = 0; j < one.length(); j++) {
                if (curri == two.length()) { s.append("#"); continue; };

                if (one.charAt(j) == two.charAt(curri)) {
                    s.append(one.charAt(j));
                    curri++;
                } else s.append("#");
            }

            System.out.println(s.toString());
        }
    }

    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer t;

    static void get() throws Exception { t = new StringTokenizer(reader.readLine()); }
    static int g() { return Integer.parseInt(t.nextToken()); }
    static int p() throws Exception { return Integer.parseInt(reader.readLine()); }
    static long gL() { return Long.parseLong(t.nextToken()); }
    static long pL() throws Exception { return Long.parseLong(reader.readLine()); }
}