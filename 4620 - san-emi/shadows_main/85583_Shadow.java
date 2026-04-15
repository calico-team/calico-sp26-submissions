import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Shadow {
    public Shadow(){

    }

    public void solve() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for(int fff = 0; fff < t; fff++){
            int n = Integer.parseInt(reader.readLine());
            String[] so = new String[n];
            for(int i = 0; i < n; i++){
                String temp = reader.readLine();
                so[i] = temp;
            }
            String[] st = new String[n];
            for(int i = 0; i < n; i++){
                String temp = reader.readLine();
                st[i] = temp;
            }

            int max = 0;
            int min = 0;

            for(int i = 0; i < n; i++){
                int one = count(so[i]);
                int two = count(st[i]);

                max += one*two;
                min += Math.max(one,two);
            }

            System.out.println(max + " " + min);

        }

        
    }

    public int count(String x){
        int total = 0;

        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) == '#'){
                total++;
            }
        }

        return total;
    }

    public static void main(String[] args) throws IOException{
        new Shadow().solve();
    }
}
