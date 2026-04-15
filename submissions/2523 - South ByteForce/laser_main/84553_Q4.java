import java.util.*;
import java.io.*;

public class Q4 {
    public static int solve(int K, int N, int M, int P, int Q, int[][] ast) {
        Map<Long, Integer> pos = new HashMap<>();
        for (int i = 0; i < K; i++) {
            long key = (long) ast[i][0] * M + ast[i][1];
            if (!pos.containsKey(key))
                pos.put(key, i);
        }

        int x = ast[0][0];
        int y = ast[0][1];

        int maxSteps = N * M;
        for (int t = 1; t <= maxSteps; t++) {
            x = (x + Q) % N;
            y = (y + P) % M;
            long key = (long) x * M + y;
            if (pos.containsKey(key))
                return pos.get(key);
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int K = Integer.parseInt(str[0]);
            int N = Integer.parseInt(str[1]);
            int M = Integer.parseInt(str[2]);
            int P = Integer.parseInt(str[3]);
            int Q = Integer.parseInt(str[4]);
            int[][] ast = new int[K][2];
            for (int j = 0; j < K; j++) {
                String[] a = br.readLine().split(" ");
                ast[j][0] = Integer.parseInt(a[0]);
                ast[j][1] = Integer.parseInt(a[1]);
            }
            System.out.println(solve(K, N, M, P, Q, ast));
        }
    }
}
