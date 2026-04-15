import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String A=scanner.nextLine();
        String B=scanner.nextLine();
        String[] C=new String[A.length()];
        ArrayList<String> b = new ArrayList<>();
        int ord=0;
        for(int i=0;i<B.length();i++){
            b.add(B.substring(i,i+1));
        }
        for(int i=0;i<A.length();i++){
            C[i]="#";
        }

        for(int i=0;i<A.length();i++){
            if(A.substring(i,i+1).equals(b.get(ord))){
                C[i]=b.get(ord);
                ord++;
                if(ord==b.size())break;
            }
        }
        for(int i=0;i<A.length();i++){
            System.out.print(C[i]);
        }
    }
}
