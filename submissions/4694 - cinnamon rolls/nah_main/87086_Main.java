import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;

        int T = sc.nextInt();

        while (T-- > 0) {
            // N: number of curses, P: starting power, R: power restored, K: curses needed for RCT [cite: 337-341]
            int N = sc.nextInt();
            long currentPower = sc.nextLong();
            long R = sc.nextLong();
            int K = sc.nextInt();

            long[] E = new long[N];
            for (int i = 0; i < N; i++) {
                E[i] = sc.nextLong();
            }

            boolean defeated = false;
            int cursesDefeated = 0;

            for (int i = 0; i < N; i++) {
                currentPower -= E[i];

                if (currentPower < 0) {
                    defeated = true;
                    break;
                }

                cursesDefeated++;

                if (cursesDefeated % K == 0) {
                    currentPower += R;
                }
            }

            if (defeated) {
                System.out.println("nah i'd lose");
            } else {
                System.out.println("nah i'd win");
            }
        }
    }
}