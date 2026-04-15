import java.util.*;
import java.io.*;

public class Q6 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine().trim());

            int[] countS1 = new int[N];
            for (int row = 0; row < N; row++) {
                String line = br.readLine().trim();
                for (int col = 0; col < N; col++)
                    if (line.charAt(col) == '#')
                        countS1[row]++;
            }

            int[] countS2 = new int[N];
            for (int row = 0; row < N; row++) {
                String line = br.readLine().trim();
                for (int col = 0; col < N; col++)
                    if (line.charAt(col) == '#')
                        countS2[row]++;
            }

            long maxVol = 0;
            long minVol = 0;
            for (int row = 0; row < N; row++) {
                long a = countS1[row];
                long b = countS2[row];
                maxVol += a * b;
                minVol += Math.max(a, b);
            }

            System.out.print(maxVol + " " + minVol + "\n");
        }
    }
}
