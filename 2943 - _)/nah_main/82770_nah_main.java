import java.util.Scanner;

public class nah_main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 0; t < T; t++) {
            int N = s.nextInt();
            int P = s.nextInt();
            int R = s.nextInt();
            int K = s.nextInt();
            s.nextLine();

            //int[] E = new int[N];
            int power = P;
            int fail = 0;
            for (int i = 0; i < N; i++) {
                if (i != 0 && i % K == 0) {
                    power += R;
                }
                power -= s.nextInt();
                if (power < 0) {
                    fail = 1;
                }
            }
            s.nextLine();
            if (fail == 1) {
                System.out.println("nah i'd lose");
            } else {
                System.out.println("nah i'd win");
            }
        }
    }
}
