import java.util.Scanner;
import java.util.StringJoiner;
import java.util.Arrays;

public class tower
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        for(int i = 0; i < T; i++) {
            int N = sc.nextInt();
            long[] A = new long[N];
            StringBuilder B = new StringBuilder();
            
            // Fills in each value of A
            for(int j = 0; j < N; j++) {
                A[j] = sc.nextLong();
            }
            
            long[] sortedA = A.clone();
            Arrays.sort(sortedA);
            long median = sortedA[N / 2];

            StringJoiner sj = new StringJoiner(" ");
            for (int g = 0; g < N; g++) {
                sj.add(String.valueOf(median));
            }
            System.out.println(sj.toString());
        }
        sc.close();
	}
}
