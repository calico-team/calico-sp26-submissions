import java.io.*;
import java.util.*;

class MyProgram {
    /**
     * Find an array B of N integers representing the filled-in second row,
     * chosen to minimize the sum of absolute differences of adjacent
     * numbers on the grid.
     * 
     * N: the number of columns in the 2 x N grid
     * A: array of N integers giving the first row of the grid
     */
    static int[] solve(int N, int[] A) {
        int[] answer = new int[N];
        int divider = 2;
        int counter1 = 0;
        int holyGrail = 0;
        int fuller = 0;
        for( int i = 0; i <N; i++){
            counter1 = 0;
            for(int i2 = 0; i2<N; i2++){
                if(A[i] == A[i2]){
                    counter1+=1;
                }
            }
            if(counter1 >= N/2){
                fuller = 1;
                holyGrail = A[i];
                break;
            }
        }
        for(int i = 0; i < N; i ++ ){
            int holder = 0;
            if(i == 0){
                holder += ((A[i]+A[i+2]+A[i+1])/3);
            }
            else if(i  == N-1){
                holder += ((A[i-1]+A[i]+A[i-2])/3);
            }
            else{
                holder += ((A[i-1]+A[i]+A[i+1])/3);
            }
            if(fuller == 1){
                answer[i] = holyGrail;
            }
            else{
                answer[i] = holder;
            }
            
        }
        return answer;
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