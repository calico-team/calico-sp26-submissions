import java.util.Scanner;

public class grid_main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 0; t < T; t++) {
            int N = s.nextInt();
            s.nextLine();

            long[] A = new long[N];
            long[] b = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = s.nextLong();
                b[i] = A[i];
            }

            for (int i = 1; i < N - 1; i++) {
                if (b[i] > b[i-1] && b[i] > b[i+1]) {
                    if (b[i-1] < b[i+1]) {
                        b[i] = b[i+1];
                    }
                    else {
                        b[i] = b[i-1];
                    }
                }

                if (b[i] < b[i-1] && b[i] < b[i+1]) {
                    if (b[i-1] > b[i+1]) {
                        b[i] = b[i+1];
                    }
                    else {
                        b[i] = b[i-1];
                    }
                }
            }

            for (int i = 0; i < N; i++) {
                System.out.print(b[i]);
                if (i < N - 1) {
                    System.out.print(" ");
                }
            }
        }
    }
}
