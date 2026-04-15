import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        int T = p();
        for(int k = 0; k < T; k++) {
            get();
            long N = g(), P = g(), R = g(), K = g();
            long[] arr = new long[Math.toIntExact(N)];
            get();
            for (int i = 0; i < N; i++) {
                arr[i] = g();
            }

            int count = 0;
            boolean good = true;
            for (int i = 0; i < N; i++) {
                if (count == K) { P += R; count = 0; }

                if (P - arr[i] >= 0) {
                    P -= arr[i];
                    count++;
                } else {
                    System.out.println("nah i'd lose");
                    good = false;
                    break;
                }
            }
            if (good) System.out.println("nah i'd win");
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