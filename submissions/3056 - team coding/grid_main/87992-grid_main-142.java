import java.io.*;
import java.util.*;

class Solution {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        Arrays.sort(A);
        int median;
        if (A.length%2 == 0) {
            median = Math.min(A[A.length/2], A[A.length/2-1]);
        }
        else {
            median = A[A.length/2];
        }

        int[] newArr = new int[N];
        for(int i = 0; i<N;i++){
            newArr[i] = median;
        }
        return newArr;
    }

    static int check(int [] a, int [] b){
        int sum = 0;
        for(int i = 0;i<a.length-1;i++){
            sum = sum + Math.abs(a[i]-a[i+1]);
            sum = sum + Math.abs(b[i]-b[i+1]);
            sum = sum + Math.abs(a[i]-b[i]);
        }
        sum = sum + Math.abs(a[a.length-1]-b[a.length-1]);
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int T = (int) in.nval;
        for (int t = 0; t < T; t++) {
            in.nextToken(); int N = (int) in.nval;
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                in.nextToken();
                A[i] = (int) in.nval;
            }
            int[] result = solve(N, A);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                if (i > 0) sb.append(' ');
                sb.append(result[i]);
            }
            pw.println(sb);
        }
        pw.flush();
    }
}
