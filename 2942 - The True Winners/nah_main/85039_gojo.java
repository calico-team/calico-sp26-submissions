import java.util.Scanner;

public class gojo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            long P = sc.nextLong();
            long R = sc.nextLong();
            int K = sc.nextInt();

            int[] E = new int[N];
            for (int i = 0; i < N; i++) {
                E[i] = sc.nextInt();
            }

            long power = P;
            boolean defeated = false;
            int cursesDefeated = 0;

            for (int i = 0; i < N; i++) {
                power -= E[i];
                cursesDefeated++;

                if (power < 0) {
                    defeated = true;
                    break;
                }

                if (cursesDefeated % K == 0) {
                    power += R;
                }
            }

            System.out.println(defeated ? "nah i'd lose" : "nah i'd win");
        }

        sc.close();
    }
}