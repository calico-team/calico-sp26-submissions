import java.util.*;
public class Nah {
    public static void main(String[] args) {
        Scanner scanner =  new Scanner(System.in);
        int t = scanner.nextInt();
        for(int a = 0; a < t; a++) {
            int n = scanner.nextInt();
            int p = scanner.nextInt();
            int r  = scanner.nextInt();
            int k = scanner.nextInt();
            int [] arr = new int[n];
            int powerLeft = p;
            for(int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            boolean bool = true;
            for(int i = 0; i < n; i++) {
                if((i)%k == 0 && i != 0) {
                    powerLeft += r;
                }
                if(powerLeft >= arr[i]) {
                    powerLeft -= arr[i];
                } else {
                    bool = false;
                    continue;
                }
            }
            if(bool) {
                System.out.println("nah i'd win");
            } else {
                System.out.println("nah i'd lose");
            }
        }
    }
}
