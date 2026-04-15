import java.util.Scanner;
import java.util.StringJoiner;

public class Main4{
    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);

        if (!inputScanner.hasNextInt()) return;
        
        int batchCount = inputScanner.nextInt();

        while (batchCount-- > 0) {
            int rowLimit = inputScanner.nextInt();
            int colLimit = inputScanner.nextInt();

            for (int r = 0; r < rowLimit; r++) {
                StringJoiner rowAssembler = new StringJoiner(" ");
                for (int c = 0; c < colLimit; c++) {
                    int cellValue = (2 * r + c) % 5;
                    rowAssembler.add(String.valueOf(cellValue));
                }
                System.out.println(rowAssembler.toString());
            }
        }
        inputScanner.close();
    }
}