package calico;

import java.util.Scanner;

public class japanscanner {
    public static int foodstep(int l,int w,int e,int r){
        int per = (l+w)*r*2;
        return (e/(per));
        
    }
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in);
        int l = reader.nextInt();
        int w = reader.nextInt();
        int e = reader.nextInt();
        int r = reader.nextInt();
        System.out.println(japanscanner.foodstep(l,w,e,r));
    }
}
// 3
// 5 3 128 2
// 10 5 300 10
// 2 2 400 5