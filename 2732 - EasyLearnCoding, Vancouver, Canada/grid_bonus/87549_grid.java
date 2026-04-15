import java.util.Scanner;

public class grid {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        int n;
        int avg=0;
        for (int i = 0; i < t; i++) {
            n=in.nextInt();
            int []l=new int [n];
            for (int j = 0; j < n; j++) {
                l[j]=in.nextInt();
                avg+=l[j];
            }
            avg/=n;
            if(test(l,avg)==1){
                for (int j = 0; j < n; j++) {
                    System.out.println(avg+" ");
                }
            }
            else{
                for (int j = 0; j < n; j++) {
                    System.out.println(l[i]+" ");
                }
            }
        }
    }

    private static int test(int[]l, int avg) {
        int t1,t2;
        t1=0;
        t2=0;
        for (int i = 0; i < l.length; i++) {
            t1+=Math.abs(l[i]-avg);
        }
        for (int i = 0; i < l.length-1; i++) {
            t2+=Math.abs(l[i+1]-l[i]);
        }
        if(t1>t2){
            return 1;
        }
        return 2;
    }
}
