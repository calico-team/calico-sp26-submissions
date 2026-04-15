import java.util.*;
import java.io.*;

public class laser {
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    Set<String> dupes;
    Map<String, Integer> set;
    for (int i = 0; i < T; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int K = Integer.parseInt(st.nextToken());
      int N = Integer.parseInt(st.nextToken());
      int M = Integer.parseInt(st.nextToken());
      int P = Integer.parseInt(st.nextToken());
      int Q = Integer.parseInt(st.nextToken());

      set = new HashMap<>();
      dupes = new HashSet<>();
      st = new StringTokenizer(br.readLine());
      int startX = Integer.parseInt(st.nextToken());
      int startY = Integer.parseInt(st.nextToken());
      set.put((startX + " " + startY), 0);
      for (int j = 1; j < K; j++) {
        st = new StringTokenizer(br.readLine());
        String s = st.nextToken() + " " + st.nextToken();
        set.put(s, j);
      }
      while (true) {
        startX += Q;
        startY += P;
        if (startX >= N) {
          startX -= N;
        }
        if (startY >= M) {
          startY -= M;
        }
        String s = startX + " " + startY;
        
        if (dupes.contains(s)) {
          break;
        }
        else {
          dupes.add(s);
        }
        if (set.get(s) != null) {
          System.out.println(set.get(s));
          break;
        }
      }

    }
  }
}