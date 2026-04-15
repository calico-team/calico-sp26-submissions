import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class nah_template {

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

    /**
     * Output whether Gojo will win the fight.
     * <p>
     * N: Number of curses P: Gojo's starting power R: Amount of power Gojo can restore with Reverse Cursed Technique K:
     * The cooldown of Reverse Cursed Technique E: List of power levels of curses
     */
    static String solve(int N, int P, int R, int K, int[] E) {
        int power = P;
        int round = 0;
        for (int i = 0; i < N; i++) {
            if (round == K) {
                power += R;
                round -= K;
            }
            if (E[i] > power) return "nah i'd lose";
            round++;
            power -= E[i];
        }
        return "nah i'd win";
    }

}

