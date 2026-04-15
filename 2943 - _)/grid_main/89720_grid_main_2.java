import java.util.Scanner;

public class grid_main_2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 0; t < T; t++) {
            int N = s.nextInt();
            s.nextLine();

            if (N == 1) {
                int a = s.nextInt();
                s.nextLine();
                System.out.println(a);
            }
            else if (N == 2) {
                int a = s.nextInt();
                int b = s.nextInt();
                s.nextLine();
                System.out.println(a + " " + b);
            }
            else {
                int[] b = new int[3];
                for (int i = 0; i < N; i++) {
                    b[i] = s.nextInt();
                }
                int mid = 0;
                if (b[0] < b[1]) {
                    if (b[1] < b[2]) {
                        mid = b[1];
                    }
                    else {
                        mid = Math.max(b[0], b[2]);
                    }
                }
                else {
                    if (b[0] < b[2]) {
                        mid = b[0];
                    }
                    else {
                        mid = Math.max(b[1], b[2]);
                    }
                }
                System.out.println(mid + " " + mid + " " + mid);
            }
        }
    }
}
