import java.util.*;
public class calico_1 {
    public static void main (String[] args) {
        Scanner scan = new Scanner (System.in);

        int test = scan.nextInt();
        for (int i = 0; i < test; i++) {
            int l = scan.nextInt();
            int w = scan.nextInt();
            int e = scan.nextInt();
            int r = scan.nextInt();
            System.out.println(e / (((2*l) + (2*w)) * r));
        }


        scan.close();
    }
}
