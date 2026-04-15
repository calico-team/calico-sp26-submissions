import java.util.Scanner;

public class files {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        String s1,s2;
        int c;
        String s="";
        c=0;
        boolean flag=true;
        for (int i = 0; i < t; i++) {
            s1=in.next();
            s2=in.next();
            for(int j=0;j<s1.length();j++){
                if(s1.substring(j,j+1).equals(s2.substring(c,c+1))&&flag){
                    if(c==s2.length()-1){
                        flag=false;
                        c--;
                    }
                    c++;
                    s=s+s1.substring(j,j+1);
                }
                else{
                    s=s+"#";
                }
            }
            c=0;
            System.out.println(s);
            s="";
            flag=true;
        }
    }
}
