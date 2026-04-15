import java.util.*;
import java.io.*;

public class nah {
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    for (int i = 0; i < T; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int N =  Integer.parseInt(st.nextToken());
      int P =  Integer.parseInt(st.nextToken());
      int R =  Integer.parseInt(st.nextToken());
      int K =  Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      int[] E = new int[N];
      int kills = 0;
      int j = 0;
      for (j = 0; j < N; j++) {
        int curse = Integer.parseInt(st.nextToken());
        if (P < curse) {
          break;
        }
        P-=curse;
        kills++;
        if (kills == K) {
          kills = 0;
          P += R;
        }
      }
      if (j == N) {
        System.out.println("nah i'd win");
      }
      else {
        System.out.println("nah i'd lose");
      }

    }
  }
}