
import java.util.Scanner;

public class Main{
    public static void main(String[]args) {
        Scanner input = new Scanner(System.in);
        int L = input.nextInt();
        int W = input.nextInt();
        int E = input.nextInt();
        int R = input.nextInt();
        double P = 2*(L+W);
        int value = (int) (E/(P*R));
        System.out.print(value);
    }
}
