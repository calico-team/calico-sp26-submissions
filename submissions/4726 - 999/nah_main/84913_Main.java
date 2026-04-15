import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            int R = sc.nextInt();
            int K = sc.nextInt();

            int[] E = new int[N];
            for (int i = 0; i < N; i++) {
                E[i] = sc.nextInt();
            }

            int currentPower = P;
            int defeatCount = 0;
            boolean win = true;

            for (int dam : E) {
                currentPower -= dam;


                if (currentPower < 0) {
                    win = false;
                    break;
                }

                defeatCount++;

                if (defeatCount == K) {
                    currentPower += R;
                    defeatCount = 0;
                }
            }

            if (win) {
                System.out.println("nah i'd win");
            } else {
                System.out.println("nah i'd lose");
            }
        }
    }
}