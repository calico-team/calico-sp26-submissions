import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numCases = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < numCases; i++) {
            int L = scanner.nextInt();
            int W = scanner.nextInt();
            int E = scanner.nextInt();
            int R = scanner.nextInt();
            scanner.nextLine();
            int perimeter = (L * 2) + (W * 2);
            int electricPerLap = perimeter * R;
            System.out.println(E / electricPerLap);
        }
    }
}