import java.util.*;
import java.io.*;

public class Q7 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    if (c > 0)
                        sb.append(' ');
                    sb.append((r + 2 * c) % 5);
                }
                sb.append('\n');
            }
        }
        System.out.print(sb);
    }
}
