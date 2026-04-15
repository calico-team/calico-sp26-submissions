import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;

        int T = Integer.parseInt(line.trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(' ');
                sb.append(st.nextToken());
            }
            sb.append('\n');

            if (sb.length() > 1000000) {
                System.out.print(sb);
                sb.setLength(0);
            }
        }
        System.out.print(sb);
    }
}