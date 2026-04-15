import java.util.*;

public class Tester {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();
            long[] A = new long[N];
            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextLong();
            }
            long[] B = Arrays.copyOf(A, N);
            if (N > 1) {
                boolean changed = true;
                while (changed) {
                    changed = false;
                    for (int i = 1; i < N - 1; i++) {
                        long a = A[i];
                        long l = B[i - 1];
                        long r = B[i + 1];
                        long newB = a;
                        if ((l <= a && a <= r) || (r <= a && a <= l)) {
                            newB = a;
                        } else if ((a <= l && l <= r) || (r <= l && l <= a)) {
                            newB = l;
                        } else {
                            newB = r;
                        }
                        if (newB != B[i]) {
                            B[i] = newB;
                            changed = true;
                        }
                    }
                    for (int i = N - 2; i >= 1; i--) {
                        long a = A[i];
                        long l = B[i - 1];
                        long r = B[i + 1];
                        long newB = a;
                        if ((l <= a && a <= r) || (r <= a && a <= l)) {
                            newB = a;
                        } else if ((a <= l && l <= r) || (r <= l && l <= a)) {
                            newB = l;
                        } else {
                            newB = r;
                        }
                        if (newB != B[i]) {
                            B[i] = newB;
                            changed = true;
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                if (i > 0)
                    System.out.print(" ");
                System.out.print(B[i]);
            }
            System.out.println();
        }
    }
}