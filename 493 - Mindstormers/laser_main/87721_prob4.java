import java.util.*;

class prob4 {

    static int solve(int K_asteroids, int N, int M, int P_yaxis, int Q_xaxis, int[] X_positions, int[] Y_positions) {

        HashMap<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < K_asteroids; i++) {
            long key = (long) X_positions[i] * M + Y_positions[i];
            map.put(key, i);
        }
        int x = X_positions[0];
        int y = Y_positions[0];

        for (int t = 1; t <= N * M; t++) {
            x = (x + Q_xaxis) % N;
            y = (y + P_yaxis) % M;

            long key = (long) x * M + y;
            if (map.containsKey(key)) {
                int lazarbeam = map.get(key);
                return lazarbeam;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int K_asteroids = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();
            int P_yaxis = sc.nextInt();
            int Q_xaxis = sc.nextInt();

            int[] X_positions = new int[K_asteroids];
            int[] Y_positions = new int[K_asteroids];

            for (int i = 0; i < K_asteroids; i++) {
                X_positions[i] = sc.nextInt();
                Y_positions[i] = sc.nextInt();
            }

            System.out.println(solve(K_asteroids, N, M, P_yaxis, Q_xaxis, X_positions, Y_positions));
        }
    }
}
