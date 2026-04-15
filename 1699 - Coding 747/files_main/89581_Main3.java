import java.util.Scanner;

public class Main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int testCount = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < testCount; i++) {
            String originalText = scanner.nextLine();
            String targetPattern = scanner.nextLine();

            System.out.println(applyMasking(originalText, targetPattern));
        }

        scanner.close();
    }

    private static String applyMasking(String source, String match) {
        StringBuilder outputBuilder = new StringBuilder();
        int patternPointer = 0;
        int patternLength = match.length();

        for (char currentSymbol : source.toCharArray()) {
            if (patternPointer < patternLength && currentSymbol == match.charAt(patternPointer)) {
                outputBuilder.append(currentSymbol);
                patternPointer++;
            } else {
                outputBuilder.append('#');
            }
        }

        return outputBuilder.toString();
    }
}