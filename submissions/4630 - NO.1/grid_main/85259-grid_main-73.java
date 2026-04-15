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
	            
	            
	            for (int i = 0; i < N; i++) {
	                System.out.print(a[i] + " ");
	            }
	            System.out.println();
	        }
	        
	        scanner.close();
	    }
}
