import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Gridfill {
    public Gridfill(){

    }

    public void solve() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for(int fff = 0; fff < t; fff++){
            int n = Integer.parseInt(reader.readLine());
            int[] a = new int[3];

            String[] ain = reader.readLine().split("\\s+");

            for(int i = 0; i < 3; i++){
                a[i] = Integer.parseInt(ain[i]);
            }

            if(a[0] < a[1] && a[1] < a[2]){
                System.out.println(a[0] + " " + a[1] + " " + a[2]);
            }
            else{
                Arrays.sort(a);
                System.out.println(a[1] + " " + a[1] + " " + a[1]);
            }
        }
    }

    public static void main(String[] args) throws IOException{
        new Gridfill().solve();
    }
    
}
