import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        int T = p();
        for (int i = 0; i < T; i++) {
            int N = p();
            int[] arr1 = new int[N];
            get();
            for (int j = 0; j < N; j++) {
                arr1[j] = g();
            }

            int[] arr2 = arr1.clone();
            StringBuilder s = new StringBuilder();
            s.append(arr2[0]).append(" ");
            for (int j = 1; j < N - 1; j++) {
                if ((arr2[j - 1] <= arr2[j] && arr1[j] >= arr2[j]) || (arr2[j - 1] >= arr2[j] && arr1[j] <= arr2[j])) {
                    if (arr1[j + 1] < arr2[j]) {
                        int maxDecrease = Math.max(arr2[j - 1], arr1[j + 1]);
                        arr2[j] = maxDecrease;
                    } else {
                        int maxIncrease = Math.min(arr1[j], arr1[j + 1]);
                        arr2[j] = maxIncrease;
                    }
                }
                s.append(arr2[j]).append(" ");
            }
            s.append(arr2[N - 1]);
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