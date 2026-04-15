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
            long[] B = new long[N];
            for (int i = 0; i < N; i++) {
                B[i] = A[i];
            }
            for (int i = 0; i < 20; i++) {
                boolean changed = false;
                long[] newB = new long[N];
                for (int j = 0; j < N; j++) {
                    List<Long> vals = new ArrayList<>();
                    vals.add(A[j]);
                    if (j > 0)
                        vals.add(B[j - 1]);
                    if (j < N - 1)
                        vals.add(B[j + 1]);
                    Collections.sort(vals);
                    long med = vals.get(vals.size() / 2);
                    newB[j] = med;
                    if (newB[j] != B[j])
                        changed = true;
                }
                B = newB;
                if (!changed)
                    break;
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