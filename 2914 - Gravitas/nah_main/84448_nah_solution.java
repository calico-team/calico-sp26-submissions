
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Solution {

    static String solve(int N, int P, int R, int K, int[] E) {

        int power = P;
        int kills = 0;

        int i = 0;

        while (i < N) {
            power = power - E[i];
            if (power < 0) {
                return "nah i'd lose";
            }
            kills = kills + 1;
            if (kills == K) {
                power = power + R;
                kills = 0;
            }
            i = i + 1;
        }
        return "nah i'd win";

    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] header = in.readLine().split(" ");
            int N = Integer.parseInt(header[0]);
            int P = Integer.parseInt(header[1]);
            int R = Integer.parseInt(header[2]);
            int K = Integer.parseInt(header[3]);

            int[] E = new int[N];
            String[] energy = in.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                E[j] = Integer.parseInt(energy[j]);
            }

            out.println(solve(N, P, R, K, E));
        }

        out.flush();
    }
}
