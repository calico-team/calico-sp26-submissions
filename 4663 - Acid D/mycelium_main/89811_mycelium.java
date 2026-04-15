import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class mycelium {
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());

    for (int t = 0; t < T; t++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int gX = Integer.parseInt(st.nextToken());
      int gY = Integer.parseInt(st.nextToken());

      int mX = Integer.parseInt(st.nextToken());
      int mY = Integer.parseInt(st.nextToken());

      int totalM = 0;
      Queue<int[]> g = new LinkedList<>();
      Queue<int[]> m = new LinkedList<>();
      g.add(new int[]{gX + 200, gY + 200});
      m.add(new int[]{mX + 200, mY + 200});

      int[] dx = new int[]{-1, 1, 0, 0};
      int[] dy = new int[]{0, 0, 1, -1};
      
      int j = 2;
      int[][] grid = new int[401][401];
      
      while (!g.isEmpty() && !m.isEmpty()) {
        
        if (j % 7 == 0) {
          int[] currM = m.poll();
          for (int i = 0; i < 4; i++) {
            int nMX = currM[0] + dx[i];
            int nMY = currM[1] + dy[i];
            if (nMX >= 0 && nMX <= 400 && nMY >= 0 && nMY <= 400 && grid[nMX][nMY] != 1) {
              grid[nMX][nMY] = 1;
              m.add(new int[]{nMX, nMY});
              totalM++;
            }
          }
        }
        if (j % 2 == 0) {
          int[] currG = g.poll();
          for (int i = 0; i < 4; i++) {
            int nGX = currG[0] + dx[i];
            int nGY = currG[1] + dy[i];
            if (nGX >= 0 && nGX <= 400 && nGY >= 0 && nGY <= 400 && grid[nGX][nGY] != 2) {
              if (grid[nGX][nGY] == 1) {
                totalM--;
              }
              grid[nGX][nGY] = 2;
              g.add(new int[]{nGX, nGY});
            }
          }
        }
        
        j++;
      }
      System.out.println(totalM);
    }
    
  
  }
}
