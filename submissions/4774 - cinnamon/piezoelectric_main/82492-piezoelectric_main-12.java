import java.util.*;
import java.io.*;

public class piezoelectric {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        input.nextLine();
        while (t > 0) {
            int l = input.nextInt();
            int w = input.nextInt();
            int e = input.nextInt();
            int r = input.nextInt();
            System.out.println(e / ((2*l + 2*w) * r));
            input.nextLine();
        }
    }
}