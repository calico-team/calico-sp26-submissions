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
            int[] curses = new int[N];
            for (int i = 0; i < N; i++) {
                curses[i] = sc.nextInt();
            }
            int power = P;
            int count = 0;
            boolean win = true;
            for (int damage : curses) {
                power -= damage;
                if (power < 0) {
                    win = false;
                }
                count++;
                if (count % K == 0) {
                    power += R;
                }
            }
            System.out.println(win ? "nah i'd win" : "nah i'd lose");
        }
        sc.close();
    }
}