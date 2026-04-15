import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Main {
    /**
     * Find the index of the first asteroid hit by the laser.
     *
     * K: Number of asteroids
     * N, M: Bounds for x- and y-coordinates
     * P, Q: Laser movement (P along y-axis, Q along x-axis)
     * X: List of x-coordinates of asteroids
     * Y: List of y-coordinates of asteroids
     */
    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {
        // YOUR CODE HERE
        int start=0;
        int nx=(X[0]);
        int ny=(Y[0]);
        while(true) {
            nx = (nx + Q) % N;
            ny = (ny + P) % M;
            for (int i = 0; i < X.length; i++) {
                if (nx == X[i]) {
                    if (ny == Y[i]) {
                        return i;
                    }
                }
            }
        }
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

