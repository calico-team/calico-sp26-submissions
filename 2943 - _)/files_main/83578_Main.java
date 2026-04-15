import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < testCases; i++) {
            String A = scanner.nextLine();
            String B = scanner.nextLine();
            String output = "";
            int counter = 0;
            for (int j = 0; j < A.length(); j++) {
                String letter = B.substring(counter, counter+1);
                if (A.substring(j, j+1).equals(letter)) {
                    output += letter;
                    counter++;
                } else {
                    output += "#";
                }
                if (counter == B.length()) {
                    break;
                }
            }
            System.out.println(output);
        }
    }
}