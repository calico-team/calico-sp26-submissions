import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numTestCases = scanner.nextInt();
        scanner.nextLine();

        for (int testCase = 0; testCase < numTestCases; testCase++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            String stringA = parts[0];
            String stringB = parts[1];

            String result = replaceWithHash(stringA, stringB);

            System.out.println(result);
        }

    }

    public static String replaceWithHash(String a, String b) {
        StringBuilder result = new StringBuilder();
        int bIndex = 0;

        for (int aIndex = 0; aIndex < a.length(); aIndex++) {
            char currentChar = a.charAt(aIndex);

            if (bIndex < b.length() && currentChar == b.charAt(bIndex)) {
                result.append(currentChar);
                bIndex++;
            } else {
                result.append('#');
            }
        }

        return result.toString();
    }
}