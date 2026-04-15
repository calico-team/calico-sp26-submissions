import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] a = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(a);
            long median = 0;
            if(n%2==0) median = (a[n/2]+a[n/2-1])/2;
            else median = a[n/2];
            long medianCost = 0;
            for (int i = 0; i < n; i++) {
                medianCost+=Math.abs(a[i]-median);
            }
            long cost = 0;
            for (int i = 0; i < n-1; i++) {
                cost+=Math.abs(a[i]-a[i+1]);
            }
            if(cost*2<cost+medianCost){
                for (int i = 0; i < n-1; i++) {
                    bw.write(a[i]+" ");
                }
                bw.write(a[n-1]+"\n");
            }
            else {
                for (int i = 0; i < n-1; i++) {
                    bw.write(median+" ");
                }
                bw.write(median+"\n");
            }
        }
        bw.flush();
    }

}