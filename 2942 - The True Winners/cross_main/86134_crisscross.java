import java.util.Scanner;

public class crisscross
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        for(int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            for(int r = 0; r < N; r++) {
                StringBuilder grid = new StringBuilder();
                for(int c = 0; c < M; c++) {
                int num = (2 * r + c) % 5;
                    grid.append(num);
                    if (c < M - 1) grid.append(" ");
                }
                System.out.println(grid.toString());
            }
        }
        sc.close();
	}
}
