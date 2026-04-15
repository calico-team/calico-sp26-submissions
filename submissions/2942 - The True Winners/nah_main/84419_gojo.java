import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            int N = sc.nextInt();
            long P = sc.nextLong();
            long R = sc.nextLong();
            int K = sc.nextInt();
            
            long power = P;
            int defeated = 0;
            boolean canUse = false;
            boolean lost = false;
            
            for (int i = 0; i < N; i++) {
                long e = sc.nextLong();
                power -= e;
                defeated++;
                
                if (power < 0) {
                    if (canUse) {
                        power += R;
                        canUse = false;
                    }
                    if (power < 0) {
                        lost = true;
                    }
                }
                
                if (defeated % K == 0) {
                    canUse = true;
                }
            }
            
            if (lost) System.out.println("nah i’d lose");
            else System.out.println("nah i’d win");
        }
        
        sc.close();
    }
}
