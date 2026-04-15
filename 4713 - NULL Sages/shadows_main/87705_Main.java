import java.util.Scanner;

public class Main {
    static int N;
    static boolean[][] a;
    static boolean[][] b;
    static int jugs_cave_image;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            N = sc.nextInt();
            a = new boolean[N][N];
            b = new boolean[N][N];
            for (int i = 0; i < N; i++) {
                String s = sc.next();
                for (int j = 0; j < N; j++) {
                    a[i][j] = s.charAt(j) == '#';
                }
            }
            for (int i = 0; i < N; i++) {
                String s = sc.next();
                for (int j = 0; j < N; j++) {
                    b[i][j] = s.charAt(j) == '#';
                }
            }
            int max = 0;
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    for (int z = 0; z < N; z++) {
                        if (a[x][y] && b[x][z]) max++;
                    }
                }
            }
            int min = 0;
            for (int x = 0; x < N; x++) {
                int cy = 0, cz = 0;
                for (int y = 0; y < N; y++) if (a[x][y]) cy++;
                for (int z = 0; z < N; z++) if (b[x][z]) cz++;
                min += Math.max(cy, cz);
            }
            System.out.println(max + " " + min);
        }
        sc.close();
    }
    static void read_your_input() {}
}