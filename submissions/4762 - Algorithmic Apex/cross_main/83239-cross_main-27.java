import java.io.*;
import java.util.*;

public class B {
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
                    e.printStackTrace();
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
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        StringBuilder out = new StringBuilder();

        int t = sc.nextInt();
        while (t-- > 0) {
            int M = sc.nextInt();
            int N = sc.nextInt();
            solve(M, N);
        }
    }

    static void solve(int M, int N){
        int[][] grid = new int[M][N];
        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                grid[i][j] = (2*i + j)%5;
            }
        }
        for(int i=0; i<M; ++i){
            for(int j=0; j<N; ++j){
                if (j > 0) System.out.print(" ");
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}





