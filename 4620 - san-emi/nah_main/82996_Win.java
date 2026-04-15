import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Win {
    public Win(){

    }

    public void solve() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for(int fff = 0; fff < t; fff++){
            String[] nprk = reader.readLine().split("\\s+");
            int n = Integer.parseInt(nprk[0]);
            int p = Integer.parseInt(nprk[1]);
            int r = Integer.parseInt(nprk[2]);
            int k = Integer.parseInt(nprk[3]);

            int[] e = new int[n];
            String[] ein = reader.readLine().split("\\s+");

            for(int i = 0; i < n; i++){
                e[i] = Integer.parseInt(ein[i]);
            }

            int defeated = 0;
            boolean lost = false;
            for(int i = 0; i < n; i++){
                p -= e[i];
                if(p >= 0){
                    defeated++;
                }
                else{
                    lost = true;
                    break;
                }
                if(defeated == k){
                    p += r;
                    defeated = 0;
                }
            }

            if(lost){
                System.out.println("nah i'd lose");
            }
            else{
                System.out.println("nah i'd win");
            }



        }

    }

    public static void main(String[] args) throws IOException{
        new Win().solve();
    }
}
