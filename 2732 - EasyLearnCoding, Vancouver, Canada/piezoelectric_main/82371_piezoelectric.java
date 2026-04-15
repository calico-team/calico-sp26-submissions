import java.util.Scanner;

public class piezoelectric {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l,w,e,r,total;
        int n=in.nextInt();
        for(int i=0;i<n;i++) {
            l = in.nextInt();
            w = in.nextInt();
            e = in.nextInt();
            r = in.nextInt();
            total = (l + w) * 2 * r;
            System.out.println(e/total);
        }
    }
}
