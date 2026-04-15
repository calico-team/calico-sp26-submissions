import java.io.*;
import java.util.*;
import java.lang.StringBuilder;
public class D {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        char nextChar() {
            return next().charAt(0);
        }
    }
    public static void main(String[] args){
        FastScanner sc = new FastScanner();
        StringBuilder sb = new StringBuilder();

        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int[] A = new int[n];
            for(int i=0;i<n; ++i){
                A[i] = sc.nextInt();
            }
            solve(n,A,sb);
        }
        System.out.print(sb);
        
        

    }


    static void solve(int n, int[] A, StringBuilder out){
        long[] l1 = new long[n];
        long[] r1 = new long[n];
        long bvals[] = new long[n];
        l1[0] = A[0];
        r1[0] = A[0];
        // abs value starts with the first value in A
        bvals[n-1]=A[n-1];
        for(int i=1; i<n; ++i){
            // update range for x using casework
            if(A[i]>r1[i-1]){
                l1[i] = r1[i-1];
                r1[i] = A[i];
            }
            else if(A[i]<l1[i-1]){
                l1[i] = A[i];
                r1[i] = l1[i-1];
            }
            else{
                l1[i] = A[i];
                r1[i] = A[i];
            }
        }

        
        // build b array by finding the min absolute value, max of min
        for(int i=n-2;i>=0; i--){
            long choice1 = l1[i];
            // minimize bi-bi+1
            long choice2 = Math.min(r1[i],bvals[i+1]);
            bvals[i] = Math.max(choice1, choice2);
        }
        for(int i=0;i<n; i++){
            if(i>0) out.append(' ');
            out.append(bvals[i]);
            
        }
        out.append('\n');

    }
}
