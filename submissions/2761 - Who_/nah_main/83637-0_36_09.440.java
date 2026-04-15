import java.util.*;

public class Tester {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine();
        while (t-- > 0) {
            boolean alive = true;
            int n = scanner.nextInt();
            int p = scanner.nextInt();
            int r = scanner.nextInt();
            int k = scanner.nextInt();
            scanner.nextLine();
            String[] curses = scanner.nextLine().split(" ");
            int[] curseValues = new int[n];
            System.out.println(Arrays.toString(curses));
            for (int i = 0; i < n; i++) {
                curseValues[i] = Integer.parseInt(curses[i]);
            }
            int count = 0;
            for (int i = 0; i < n; i++) {
            	if (count == k) {
                    p += r;
                    count = 0;
                }
                if (p - curseValues[i] >= 0) {
                    p -= curseValues[i];
                    count++;
                } else {
                    System.out.println("nah i'd lose");
                    alive = false;
                    break;
                }
                
            }
            if (alive) {
                System.out.println("nah i'd win");
            }
        }
    }
}