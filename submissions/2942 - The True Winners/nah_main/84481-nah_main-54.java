import java.util.*;

public class gojo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int size = 2 * N - 1;

            for (int r = 0; r < size; r++) {
                StringBuilder sb = new StringBuilder();
                for (int c = 0; c < size; c++) {
                    int d = Math.min(Math.min(r, c),
                            Math.min(size - 1 - r, size - 1 - c));

                    if (d % 2 == 0)
                        sb.append('x');
                    else
                        sb.append(' ');
                }
                System.out.println(sb);
            }

            if (t < T - 1) System.out.println();
        }
    }
}
