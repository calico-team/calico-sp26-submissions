import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Solution {
    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {
        boolean hit = false;
        int xCord = X[0];
        int yCord = Y[0];
        int answer = 0;
        while(hit == false){
            if (xCord + Q <= N){
			    xCord += Q;
            }
            else{
                xCord = (xCord+Q)-N;
            }
            if (yCord + P <= M){
                yCord += P;
            }
            else{
                yCord = (yCord+P)-M;
            }
            for (int i = 0; i < K; i++){
                if (X[i] == xCord && Y[i] == yCord){
                    answer = i;
                    hit = true;
                }
            }
        }
        return answer;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        while (T-- > 0) {
            String[] temp = in.readLine().split(" ");
            int K = Integer.parseInt(temp[0]);
            int N = Integer.parseInt(temp[1]);
            int M = Integer.parseInt(temp[2]);
            int P = Integer.parseInt(temp[3]);
            int Q = Integer.parseInt(temp[4]);

            int[] X = new int[K];
            int[] Y = new int[K];
            for (int i = 0; i < K; i++) {
                String[] point = in.readLine().split(" ");
                X[i] = Integer.parseInt(point[0]);
                Y[i] = Integer.parseInt(point[1]);
            }

            out.println(solve(K, N, M, P, Q, X, Y));
        }

        out.flush();
    }
}

