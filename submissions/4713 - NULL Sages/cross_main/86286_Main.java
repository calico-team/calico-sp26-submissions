import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int numberOfTest = input.nextInt();

        for (int i = 0; i < numberOfTest; i++) {
            int row = input.nextInt();
            int col = input.nextInt();
            printGrid(row, col);
        }
    }

    public static void printGrid(int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            StringBuilder rowString = new StringBuilder();

            for (int j = 0; j < cols; j++) {
                int number = (i + 2 * j) % 5;

                if (j == 0) {
                    rowString.append(number);
                } else {
                    rowString.append(" ");
                    rowString.append(number);
                }
            }
            System.out.println(rowString);
        }
    }
}