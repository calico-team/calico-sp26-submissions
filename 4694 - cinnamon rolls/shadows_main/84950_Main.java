import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static String nextLine() throws IOException {
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) {
            line = br.readLine();
        }
        return line == null ? null : line.trim();
    }

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(nextLine());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int N = Integer.parseInt(nextLine());

            char[][] s1 = new char[N][N];
            for (int i = 0; i < N; i++) {
                s1[i] = nextLine().toCharArray();
            }

            char[][] s2 = new char[N][N];
            for (int i = 0; i < N; i++) {
                s2[i] = nextLine().toCharArray();
            }

            long totalMax = 0;
            long totalMin = 0;

            for (int row = 0; row < N; row++) {
                long s1Count = 0, s2Count = 0;
                for (int col = 0; col < N; col++) {
                    if (s1[row][col] == '#') s1Count++;
                }
                for (int depth = 0; depth < N; depth++) {
                    if (s2[row][depth] == '#') s2Count++;
                }
                totalMax += s1Count * s2Count;
                totalMin += Math.max(s1Count, s2Count);
            }

            sb.append(totalMax).append(" ").append(totalMin).append("\n");
        }

        System.out.print(sb);
    }

    static void read_your_input() throws IOException {
        System.setIn(new FileInputStream("input.txt"));
    }
}