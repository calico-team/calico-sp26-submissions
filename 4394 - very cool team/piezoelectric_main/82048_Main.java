import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            get();
            int L = g(), W = g(), E = g(), R = g();
            int perLap = R*(2*L + 2*W);
            System.out.println(E / perLap);
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