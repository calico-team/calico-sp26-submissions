import java.util.Scanner;

public class nah {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n,p,r,k;
        int cnt=0;
        int t=in.nextInt();
        int cur=0;
        boolean flag=false;
        for (int i = 0; i < t; i++) {
            n=in.nextInt();
            p=in.nextInt();
            r=in.nextInt();
            k=in.nextInt();
            for (int j = 0; j < n; j++) {
                cur=in.nextInt();
                cnt++;
                if(p<cur){
                    flag=true;
                }
                p-=cur;
                if(cnt==k){
                    p+=r;
                    cnt=0;
                }
            }
            if(flag) System.out.println("nah i'd lose");
            else System.out.println("nah i'd win");
            flag=false;
            cnt=0;
        }
    }
}
