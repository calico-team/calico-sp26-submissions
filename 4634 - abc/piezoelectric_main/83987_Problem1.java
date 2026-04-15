import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int times = in.nextInt();
        //System.out.println(times);
        in.nextLine();
        for(int i = 0; i < times; i++){
            int L = in.nextInt();
            int W = in.nextInt();
            int E = in.nextInt();
            int R = in.nextInt();
            int per = (L+W)*2;
            int step = E/R;
            if(step * R == E-1){
                step++;
            }
            System.out.println(step/per);
            in.nextLine();
        }
        in.close();
    }
}
