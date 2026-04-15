import java.util.*;
import java.io.*;

public class piezoelectric {
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    for (int i = 0; i < T; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int L =  Integer.parseInt(st.nextToken());
      int W =  Integer.parseInt(st.nextToken());
      int E =  Integer.parseInt(st.nextToken());
      int R =  Integer.parseInt(st.nextToken());

      System.out.println((E/((L+W) * 2 * R)));
    }
    
    
  }
}