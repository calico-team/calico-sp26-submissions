import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Solution {
    /** 
     * Find the index of the first asteroid hit by the laser.
     * 		
     * K: Number of asteroids
     * N, M: Bounds for x- and y-coordinates
     * P, Q: Laser movement (P along y-axis, Q along x-axis)
     * X: List of x-coordinates of asteroids
     * Y: List of y-coordinates of asteroids
     */
    static int solve(int K, int N, int M, int P, int Q, int[] X, int[] Y) {
        int result = -1;
        int posX = X[0];
        int posY = Y[0];
        boolean firstMove = true;
        while(result == -1) {
            for(int i = 0; i<X.length; i++) {
                if(firstMove && i==0) {
                    firstMove = false;
                    continue;
                }
                if((X[i]-posX!=0 && Y[i]-posY!=0) || (X[i]-posX==0 && Y[i]-posY==0)) {
                    if((X[i]-posX)%Q==0 && (Y[i]-posY)%P==0) {
                        if((X[i]-posX)/Q == (Y[i]-posY)/P) {
                            result = i;
                            break;
                        }
                    }
                }
                
            }
            //amount to move the pos by 
            double xSteps = (double)(N-posX)/Q;
            double ySteps = (double)(M-posY)/P;
            
            double steps = Math.min(xSteps, ySteps);
            
            posX+=Q*((int)steps+1);
            posY+=P*((int)steps+1);
            //check if it's over the limit
            posX%=N;
            posY%=M;
        }
        return result;
    }
    
    /*
    16 12 8 4 20
    11 7 3 19 15
    6 2 18 14 10
    1 17 13 9 5
4
3 10 10 1 1
0 0
2 2
9 9
3 6 8 2 1
1 1
1 5
5 1
3 6 8 2 1
1 1
2 3
4 4
3 5 5 2 3
2 2
0 0
1 4

    
    
    */

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

