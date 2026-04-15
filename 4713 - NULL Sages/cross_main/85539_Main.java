import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        for (int i = 0; i < num; i++) {
            int row = input.nextInt();
            int col = input.nextInt();

            printValidGrid(row, col);
        }
    }

    public static void printValidGrid(int row, int col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int number = (i + 2 * j) % 5;
                System.out.print(number + " ");
            }
            System.out.println();
        }
    }
}