import java.util.Scanner;

public class Main {
    static int jugs_cave_image;
    public static void main(String[] args) {
        read_your_input();
    }
    static void read_your_input() {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            boolean[][] s1 = new boolean[n][n];
            boolean[][] s2 = new boolean[n][n];
            for (int i=0; i<n; i++) {
                String line = sc.next();
                for (int j=0; j<n; j++) {
                    s1[i][j] = line.charAt(j) == '#';
                }
            }
            for (int i=0; i<n; i++) {
                String line = sc.next();
                for (int j=0; j<n; j++) {
                    s2[i][j] = line.charAt(j) == '#';
                }
            }
            int max = 0;
            for (int x=0; x<n; x++) {
                for (int y=0; y<n; y++) {
                    for (int z=0; z<n; z++) {
                        if (s1[x][y] && s2[x][z])
                            max++;
                    }
                }
            }
            int min = 0;
            for (int x=0; x<n; x++) {
                int c1 = 0, c2 = 0;
                for (boolean b : s1[x]){
                    if (b)
                        c1++;
                }
                for (boolean b : s2[x]){
                    if (b)
                        c2++;
                }
                min += Math.max(c1, c2);
            }
            System.out.println(max + " " + min);
        }
        sc.close();
    }
}