import java.io.*;
import java.util.*;

public class Main {
    static int jugs_cave_image;
    public static void main(String[] args) throws IOException {
        read_your_input();
    }
    static void read_your_input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            boolean[][] s1 = new boolean[N][N];
            boolean[][] s2 = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                String line = br.readLine().trim();
                for (int j = 0; j < N; j++) {
                    s1[i][j] = line.charAt(j) == '#';
                }
            }
            for (int i = 0; i < N; i++) {
                String line = br.readLine().trim();
                for (int j = 0; j < N; j++) {
                    s2[i][j] = line.charAt(j) == '#';
                }
            }
            long max = 0;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    for (int z = 0; z < N; z++) {
                        if (s1[x][y] && s2[x][z])
                            max++;
                    }
                }
            }
            long min = 0;
            for (int x = 0; x < N; x++) {
                int cnt1 = 0, cnt2 = 0;
                for (boolean b : s1[x]){
                    if (b)
                        cnt1++;
                }
                for (boolean b : s2[x]){
                    if (b)
                        cnt2++;
                }
                min += Math.max(cnt1, cnt2);
            }
            System.out.println(max + " " + min);
        }
    }
}