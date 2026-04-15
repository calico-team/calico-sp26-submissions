import java.util.*;
import java.io.*;

public class Q7 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    if (c > 0)
                        System.out.print(' ');
                    System.out.print((r + 2 * c) % 5);
                }
                System.out.println();
            }
        }
    }
}
