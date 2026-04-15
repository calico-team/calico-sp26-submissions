import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class piezoelectric {
    /** 
	 * Return the number of laps needed to charge the car (rounded up)
	 * 
	 * L: Length of car
	 * W: Width of car
	 * E: Amount of electricity to generate
	 * R: Electricity generated per unit distance
	 */
    static int solve(int L, int W, int E, int R) {
        int perimeter = L*2 + W*2;
        double energyPerLap = perimeter*R; 
        return (int)Math.ceil(E/energyPerLap);
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        while (T-- > 0) {
            String[] temp = in.readLine().split(" ");
            int L = Integer.parseInt(temp[0]);
            int W = Integer.parseInt(temp[1]);
            int E = Integer.parseInt(temp[2]);
            int R = Integer.parseInt(temp[3]);

            out.println(solve(L, W, E, R));
        }

        out.flush();
    }
}