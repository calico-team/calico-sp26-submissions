import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = Long.parseLong(st.nextToken());
            }
            
            long[] sortedA = A.clone();
            Arrays.sort(sortedA);

            long median = sortedA[N / 2];

            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(' ');
                sb.append(median);
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}