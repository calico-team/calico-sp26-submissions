import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numTest = input.nextInt();

        for (int caseNum = 0; caseNum < numTest; caseNum++) {
            int row = input.nextInt();
            int col = input.nextInt();
            printValidGrid(row, col);
        }
    }

    public static void printValidGrid(int row, int col) {
        for (int i = 0; i < row; i++) {
            StringBuilder line = new StringBuilder();
            for (int j = 0; j < col; j++) {
                int value;
                if (i == 0) {
                    value = j % 2;
                } else if (i == row - 1) {
                    value = 4 - (j % 2);
                } else {
                    value = 1 + (j % 4);
                }

                if (j == 0) {
                    line.append(value);
                } else {
                    line.append(" ").append(value);
                }
            }
            System.out.println(line.toString());
        }
    }
}