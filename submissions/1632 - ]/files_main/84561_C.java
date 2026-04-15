import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            st = new StringTokenizer(br.readLine());
            String b = st.nextToken();
            char[] newA = new char[a.length()];
            int aI = 0;
            int bI = 0;
            while (bI < b.length()) {
                if(b.charAt(bI)!=a.charAt(aI)) newA[aI++]='#';
                else newA[aI++]=b.charAt(bI++);
            }
            for (aI=aI; aI < a.length(); aI++) {
                newA[aI]='#';
            }
//            System.out.println(Arrays.toString(newA));
            for (int i = 0; i < a.length(); i++) {
                bw.write(newA[i]+"");
            }
            bw.write("\n");
        }
        bw.flush();
    }

}