import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int T = sc.nextInt();

        while (T-- > 0) {
            long L = sc.nextLong();
            long W = sc.nextLong();
            long E = sc.nextLong();
            long R = sc.nextLong();

            long perimeter = 2 * (L + W);
            long electricityPerLap = perimeter * R;
            long laps = E / electricityPerLap;

            System.out.println(laps);
        }
    }
}