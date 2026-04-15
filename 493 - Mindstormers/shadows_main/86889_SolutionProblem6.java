import java.util.Scanner;

public class SolutionProblem6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()){
            return;
        }
        int casesCount = sc.nextInt();
        while (casesCount-- > 0) {
            int n = sc.nextInt();
            int[] shadow1Counts = new int[n];
            int[] shadow2Counts = new int[n];

            for (int i = 0; i < n; i++) {
                String row = sc.next();
                int hashCount = 0;
                for (int j = 0; j < n; j++) {
                    if (row.charAt(j) == '#') {
                        hashCount++;
                    }
                }
                shadow1Counts[i] = hashCount;
            }
            for (int i = 0; i < n; i++) {
                String row = sc.next();
                int hashCount = 0;
                for (int j = 0; j < n; j++) {
                    if (row.charAt(j) == '#') {
                        hashCount++;
                    }
                }
                shadow2Counts[i] = hashCount;
            }
            long maxVol = 0;
            long minVol = 0;

            for (int i = 0; i < n; i++) {
                maxVol += (long) shadow1Counts[i] * shadow2Counts[i];
                minVol += Math.max(shadow1Counts[i], shadow2Counts[i]);
            }
            System.out.println(maxVol + " " + minVol);
        }
        sc.close();
    }
}