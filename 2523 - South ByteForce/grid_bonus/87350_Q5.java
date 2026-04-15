import java.util.*;
import java.io.*;

public class Q5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < t; i++) {
            int N = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] A = new long[N];
            for (int j = 0; j < N; j++) {
                A[j] = Long.parseLong(st.nextToken());
            }

            PriorityQueue<Long> left = new PriorityQueue<>(Collections.reverseOrder());
            PriorityQueue<Long> right = new PriorityQueue<>();

            long[] low = new long[N];
            long[] high = new long[N];

            for (int k = 0; k < N; k++) {
                if (k > 0) {
                    long maxLeft = left.peek();
                    long minRight = right.peek();
                    left.clear();
                    right.clear();
                    left.add(maxLeft);
                    right.add(minRight);
                }

                left.add(A[k]);
                right.add(A[k]);

                if (left.peek() > right.peek()) {
                    long leftTop = left.poll();
                    long rightTop = right.poll();
                    left.add(rightTop);
                    right.add(leftTop);
                }

                low[k] = left.peek();
                high[k] = right.peek();
            }

            long[] b = new long[N];
            b[N - 1] = low[N - 1];
            for (int l = N - 2; l >= 0; l--)
                b[l] = Math.max(low[l], Math.min(high[l], b[l + 1]));

            for (int m = 0; m < N; m++) {
                if (m > 0)
                    System.out.print(' ');
                System.out.print(b[m]);
            }
            System.out.println();
        }
    }
}
