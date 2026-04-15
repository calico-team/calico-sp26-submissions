import java.util.Scanner;

public class shadows_main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 0; t < T; t++) {
            int N = s.nextInt();
            s.nextLine();

            int[] shadow1 = new int[N];
            int[] shadow2 = new int[N];

            for (int i = 0; i < N; i++) {
                shadow1[i] = countHashtags(s.nextLine());
            }

            for (int i = 0; i < N; i++) {
                shadow2[i] = countHashtags(s.nextLine());
            }

            int min = 0;
            for (int i = 0; i < N; i++) {
                min += Math.max(shadow1[i], shadow2[i]);
            }

            int max = 0;
            for (int j = 0; j < N; j++) {
                int s1J = shadow1[j];
                int s2J = shadow2[j];
                max += s1J * s2J;
            }

            System.out.println(max + " " + min);
        }
    }

    public static int countHashtags(String string) {
        int counter = 0;
        for (int i = 0; i < string.length(); i++) {
            if (string.substring(i, i+1).equals("#")) {
                counter++;
            }
        }
        return counter;
    }
}
