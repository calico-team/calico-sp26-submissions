import java.util.Scanner;
public class Main {
	   public static void main(String[] args) {
	        Scanner input = new Scanner(System.in);
	        int T = input.nextInt();
	        for (int i = 0; i < T; i++) {
	            int L = input.nextInt();
	            int W = input.nextInt();
	            int E = input.nextInt();
	            int R = input.nextInt();
	            System.out.println(calculateLaps(L, W, E, R));
	        }
	        input.close();
	    }

	    private static int calculateLaps(int L, int W, int E, int R) {
	        int perimeter = 2 * (L + W);
	        int electricityPerLap = perimeter * R;
	        return E / electricityPerLap;
	    }

}