import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            boolean cooked = false; int curr = 0;
            for (int i = 0; i < n; i++) {
                int curse = Integer.parseInt(st.nextToken());
                if(p<=0) {
                    cooked = true;
                    break;
                }
                p-=curse;
                curr++; curr%=k;
                if(curr==0&&p>=0) {
                    p+=r;
                }
            }
            if(p<0) cooked = true;
            bw.write(cooked?"nah i'd lose\n":"nah i'd win\n");
        }
        bw.flush();
    }

}