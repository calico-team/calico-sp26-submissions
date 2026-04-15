import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner inputProcessor = new Scanner(System.in);

        if (inputProcessor.hasNextInt()) {
            int totalTrials = inputProcessor.nextInt();

            for (int i = 0; i < totalTrials; i++) {
                long horizontalDim = inputProcessor.nextLong();
                long verticalDim = inputProcessor.nextLong();
                long targetEnergy = inputProcessor.nextLong();
                long consumptionRate = inputProcessor.nextLong();

                long distancePerLap = 2 * (horizontalDim + verticalDim);
                long energyUsedPerLap = distancePerLap * consumptionRate;

                long completedLaps = 0;
                if (energyUsedPerLap > 0) {
                    completedLaps = targetEnergy / energyUsedPerLap;
                }

                System.out.println(completedLaps);
            }
        }
        inputProcessor.close();
    }
}