import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Solution {
    /**
     * Output whether Gojo will win the fight.
     *
     * N: Number of curses
     * P: Gojo's starting power
     * R: Amount of power Gojo can restore with Reverse Cursed Technique
     * K: The cooldown of Reverse Cursed Technique
     * E: List of power levels of curses
     */
    static String solve(int N, int P, int R, int K, int[] E) {
        String win = "nah i'd win";
        String lose = "nah i'd lose";
    	// need to go through each curse (based on n), and check power stuff
    	// if the total sum is less than P, he wins
        
        int numCurses = 0;
        int i = 0;
        
    	while (i < E.length) {
    		// perform curse
    		P -= E[i];
    		
    		// refresh power if possible
    		if (P <= 0 && numCurses >= K) {
    			P += R;
    			numCurses = 0;
    		}
    		
    		// check if lost
    		if (P < 0) {
    			return lose;
    		}
    		
    		numCurses++;
    		
    		i++;
    	}
    	
    	return win;
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

