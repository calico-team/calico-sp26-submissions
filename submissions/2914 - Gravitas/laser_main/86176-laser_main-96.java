
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Solution {

    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {

        int laser1 = X[0];
        int laser2 = Y[0];

        int tries = 0;

        while (tries < 1000000) {
            laser1 = (laser1 + Q) % N;
            laser2 = (laser2 + P) % M;

            int rock = 0;

            while (rock < K) {
                if (laser1 == X[rock] && laser2 == Y[rock]) {
                    return rock;
                }
                rock = rock + 1;
            }

            tries = tries + 1;
        }

        return 0;

    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        while (T-- > 0) {
            String[] temp = in.readLine().split(" ");
            int K = Integer.parseInt(temp[0]);
            int N = Integer.parseInt(temp[1]);
            int M = Integer.parseInt(temp[2]);
            int P = Integer.parseInt(temp[3]);
            int Q = Integer.parseInt(temp[4]);

            int[] X = new int[K];
            int[] Y = new int[K];
            for (int i = 0; i < K; i++) {
                String[] point = in.readLine().split(" ");
                X[i] = Integer.parseInt(point[0]);
                Y[i] = Integer.parseInt(point[1]);
            }

            out.println(solve(K, N, M, P, Q, X, Y));
        }

        out.flush();
    }
}
