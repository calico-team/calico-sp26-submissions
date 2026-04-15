import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            make_the_criss_cross(N, M, sb);
        }

        System.out.print(sb);
    }

    static void make_the_criss_cross(int N, int M, StringBuilder sb) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (c > 0) sb.append(' ');
                sb.append((r * 2 + c) % 5);
            }
            sb.append('\n');
        }
    }

    static void read_your_input() throws IOException {
        System.setIn(new FileInputStream("input.txt"));
    }
}