import java.util.Scanner;

public class Problem4 {
    /*public static int findHit(int px,int py, int addx, int addy) {
        px+k*addx
    }

     */
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int times = scan.nextInt();
        for(int a = 0; a<times; a++){
            int K = scan.nextInt();
            int N = scan.nextInt();
            int M = scan.nextInt();
            int P = scan.nextInt();
            int Q = scan.nextInt();
            int[] x = new int[K];
            int[] y = new int[K];
            for(int i=0; i<K; i++){
                x[i] = scan.nextInt();
                y[i] = scan.nextInt();
            }
            int posx = x[0];
            int posy = y[0];
            boolean hit = false;
            while(!hit){
                posx+=Q;
                posy+=P;
                if(posx > N-1){
                    posx = posx%N;
                }
                if(posy > M-1){
                    posy = posy%M;
                }
                for(int i=0; i<K; i++) {
                    if (x[i] == posx && y[i] == posy) {
                        System.out.println(i);
                        hit = true;
                        break;
                    }
                }

            }
        }
    }
}
