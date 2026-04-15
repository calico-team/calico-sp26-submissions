import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Laser {
    public Laser(){

    }

    public void solve() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for(int fff = 0; fff < t; fff++){
            String[] nprk = reader.readLine().split("\\s+");
            int k = Integer.parseInt(nprk[0]);
            int n = Integer.parseInt(nprk[1]);
            int m = Integer.parseInt(nprk[2]);
            int p = Integer.parseInt(nprk[3]);
            int q = Integer.parseInt(nprk[4]);

            int[][] xy = new int[n][m];
            int[] x = new int[k];
            int[] y = new int[k];


            for(int i = 0; i < k; i++){
                String[] xyin = reader.readLine().split("\\s+");
                x[i] = Integer.parseInt(xyin[0]);
                y[i] = Integer.parseInt(xyin[1]);
                xy[x[i]][y[i]] = 1;
            }

            boolean hit = false;
            int currentx = x[0];
            int currenty = y[0];    
            while(!hit){
                currentx += q;
                currenty += p;

                if(currentx > n-1){
                    currentx = currentx - n;
                }
                if(currenty > m-1){
                    currenty = currenty - m;
                }

                if(xy[currentx][currenty] == 1){
                    hit = true;
                }
            }

            for(int i = 0; i < k; i++){
                if(x[i] == currentx && y[i] == currenty){
                    System.out.println(i);
                }
            }

        }
    }

    public static void main(String[] args) throws IOException{
        new Laser().solve();
    }
}
