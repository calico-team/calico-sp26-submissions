package UKCC;

import java.util.Scanner;

public class Main {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            sc.nextLine();

            for(int t=0; t<T; t++){
                String A = sc.nextLine();
                String B = sc.nextLine();
                String res = "";
                int j = 0;

                for(int i=0; i<A.length(); i++){
                    if(j < B.length() && A.charAt(i) == B.charAt(j)){
                        res += A.charAt(i);
                        j++;
                    }else{
                        res += "#";
                    }
                }
                System.out.println(res);

        }
    }
}
