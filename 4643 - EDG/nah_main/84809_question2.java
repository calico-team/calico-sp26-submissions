import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        for(;a>0;a--){
            int b,c,d,e;
            b=s.nextInt();
            c=s.nextInt();
            d=s.nextInt();
            e=s.nextInt();
            int f[]=new int[b];
            for(int g=0;g<b;g++)f[g]=s.nextInt();
            int h=c;
            int i=0;
            boolean j=true;
            for(int g=0;g<f.length;g++){
                h-=f[g];
                if(h<0){
                    j=false;
                    break;
                }
                i++;
                if(i==e){
                    h+=d;
                    i=0;
                }
            }
            if(j)System.out.println("nah i'd win");
            else System.out.println("nah i'd lose");
        }
        s.close();
    }
}