import java.util.*;
import java.io.*;

public class files {
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    for (int i = 0; i < T; i++) {
      String A = br.readLine();
      String B = br.readLine();
      StringBuilder sb = new StringBuilder();
      int k = 0;
      int j = 0;
      while (j < B.length()) {
        while (A.charAt(k) != B.charAt(j)) {
          k++;
          sb.append('#');
        }
        sb.append(B.charAt(j));
        k++;
        j++;

        
      }
      while (sb.length() < A.length()) {
        sb.append('#');
      }
      System.out.println(sb);
      
    }
  }
}