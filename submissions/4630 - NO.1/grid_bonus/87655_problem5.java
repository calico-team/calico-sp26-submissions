import java.util.Arrays;
import java.util.Scanner;

public class problem5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        
        while (T-- > 0) {
            int N = scanner.nextInt();
            long[] a = new long[N];
            
            for (int i = 0; i < N; i++) {
                a[i] = scanner.nextLong();
            }
            
            
            long[] sortedA = a.clone();
            Arrays.sort(sortedA);
            long median = sortedA[N / 2];
            
            
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                sb.append(median).append(" ");
            }
            System.out.println(sb.toString().trim());
        }
        
        scanner.close();
    }
}
