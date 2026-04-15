import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            int N = p();
            int[] countRow1 = new int[N];
            int[] countRow2 = new int[N];

            for (int j = 0; j < N; j++) {
                String s = reader.readLine();
                for (int k = 0; k < N; k++) {
                    if (s.charAt(k) == '#') {
                        countRow1[j]++;
                    }
                }
            }
            for (int j = 0; j < N; j++) {
                String s = reader.readLine();
                for (int k = 0; k < N; k++) {
                    if (s.charAt(k) == '#') {
                        countRow2[j]++;
                    }
                }
            }

            int min = 0;
            for (int j = 0; j < N; j++) {
                min += Math.max(countRow1[j], countRow2[j]);
            }
            int max = 0;
            for (int j = 0; j < N; j++) {
                max += countRow1[j] * countRow2[j];
            }

            System.out.println(max + " " + min);
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