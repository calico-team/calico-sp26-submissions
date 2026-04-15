import java.util.Scanner;

public class SolutionProblem2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
                if (!sc.hasNextInt()) {
                    return;
                }
        int testCases = sc.nextInt();
        while (testCases-- > 0) {
            int N = sc.nextInt(); 
            long energy = sc.nextLong();
            long restore = sc.nextLong();
            int frequency = sc.nextInt();
            
            long[] E = new long[N];
            for (int i = 0; i < N; i++) {
                E[i] = sc.nextLong(); 
            }
            
            boolean failed = false;
            for (int i = 0; i < N; i++) {
                energy -= E[i];
                if (energy < 0) {
                    failed = true;
                    break;
                }
                if ((i + 1) % frequency == 0) {
                    energy += restore;
                }
            }
            if (failed) {
                System.out.println("nah i'd lose");
            } else {
                System.out.println("nah i'd win");
            }
        }
        sc.close();
    }
}