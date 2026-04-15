import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Laser {
    /**
     * Find the index of the first asteroid hit by the laser.
     * <p>
     * K: Number of asteroids
     * N, M: Bounds for x- and y-coordinates
     * P, Q: Laser movement (P along y-axis, Q along x-axis)
     * X: List of x-coordinates of asteroids
     * Y: List of y-coordinates of asteroids
     */
    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {
        // YOUR CODE HERE
        int[][] grid = new int[N][M];
        for (int i = 0; i < K; i++) {
            grid[X[i]][Y[i]] = i + 1;
        }
        boolean hit = false;
        int[] laser = {X[0], Y[0]};
        while (!hit) {
            laser[0] = (laser[0] + P);
            laser[1] = (laser[1] + Q);
            laser[0] = laser[0] >= N ? laser[0] % N + 1: laser[0];
            laser[1] = laser[1] >= M ? laser[1] % M + 1: laser[1];
            if (grid[laser[0]][laser[1]] != 0) {
                hit = true;
                return grid[laser[0]][laser[1]] - 1;
            }
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

