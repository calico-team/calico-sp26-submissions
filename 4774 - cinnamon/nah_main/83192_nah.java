import java.util.*;
import java.io.*;

public class nah {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        input.nextLine();
        while (t > 0) {
            int n = input.nextInt();
            int p = input.nextInt();
            int r = input.nextInt();
            int k = input.nextInt();
            input.nextLine();
            int killed = 0;
            while (n > 0) {
                int e = input.nextInt();
                if (killed == k) {
                    p += r;
                    killed = 0;
                }
                if (p - e < 0) {
                    System.out.println("nah i'd lose");
                    break;
                }
                p -= e;
                killed++;
                n--;
                if (n == 0) System.out.println("nah i'd win");
            }
            input.nextLine();
            t--;
        }
    }
}