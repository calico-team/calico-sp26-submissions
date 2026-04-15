import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int totalScenarios = sc.nextInt();

        while (totalScenarios-- > 0) {
            int challengeCount = sc.nextInt();
            long currentVitality = sc.nextLong();
            long recoveryValue = sc.nextLong();
            int recoveryInterval = sc.nextInt();

            long[] damageArray = new long[challengeCount];
            for (int j = 0; j < challengeCount; j++) {
                damageArray[j] = sc.nextLong();
            }

            System.out.println(executeSimulation(currentVitality, damageArray, recoveryValue, recoveryInterval));
        }
        sc.close();
    }

    private static String executeSimulation(long vitality, long[] trials, long heal, int interval) {
        boolean isAlive = true;

        for (int step = 0; step < trials.length; step++) {
            vitality -= trials[step];

            if (vitality < 0) {
                isAlive = false;
                break;
            }

            if ((step + 1) % interval == 0) {
                vitality += heal;
            }
        }

        return isAlive ? "nah i'd win" : "nah i'd lose";
    }
}