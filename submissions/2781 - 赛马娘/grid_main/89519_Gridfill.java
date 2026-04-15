import java.io.*;
import java.util.*;

class Solution2 {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     *
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {

        int[] solutionarray = new int[N];
        if (A.length==1){
            solutionarray[0] = A[0];
            return solutionarray;
        }
        else if(A.length == 2){
            if(A[0]==A[1]){
                solutionarray[0]=A[0];
                solutionarray[1]=A[1];
                return solutionarray;
            }
            else{
                int average = (A[0]+A[1])/2;
                solutionarray[0]=average;
                solutionarray[1]=average;
                return solutionarray;
            }
        }
        else{
            if(A[0]==A[1]||A[1]==A[2]){
                solutionarray[0]=A[1];
                solutionarray[1]=A[1];
                solutionarray[2]=A[1];
                return solutionarray;
            }
            else if(A[0]==A[2]){
                solutionarray[0]=A[2];
                solutionarray[1]=A[2];
                solutionarray[2]=A[2];
                return solutionarray;
            }
            else{
                int smallestval = A[0];
                int largestval = A[0];
                for(int i = 0; i<A.length;i++){
                    int temp = A[i];
                    if(temp<smallestval){
                        smallestval = A[i];
                    }
                }
                for(int i = 0; i<A.length;i++){
                    int temp = A[i];
                    if(temp>largestval){
                        largestval = A[i];
                    }
                }
                int middle = -1;
                for(int i = 0; i<A.length;i++){
                    if(A[i]!=smallestval&&A[i]!=largestval){
                        middle = A[i];
                    }
                }
                solutionarray[0]=middle;
                solutionarray[1]=middle;
                solutionarray[2]=middle;
                return solutionarray;
            }
        }

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
