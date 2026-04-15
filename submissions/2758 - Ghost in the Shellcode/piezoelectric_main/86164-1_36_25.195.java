import java.util.*;

public class PiezoElectricSolution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int L = sc.nextInt();
            int W = sc.nextInt();
            int E = sc.nextInt();
            int R = sc.nextInt();

            int perimeter = 2 * (L + W);
            int laps = 0;

            for (int energy = 0; energy < E; energy += R) {
                perimeter--;
                if (perimeter == 0) {
                    laps++;
                    perimeter = 2 * (L + W);
                }
            }
            System.out.println(laps);
        }
    }
}