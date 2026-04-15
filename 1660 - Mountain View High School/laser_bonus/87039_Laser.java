import java.io.*;
import java.util.StringTokenizer;

public class Laser{
    public static void main(String[] args) throws IOException {
        Laser code = new Laser();
        code.solve();
    }

    public void solve() throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(r.readLine());
        int t = Integer.parseInt(st.nextToken());

        for(int sigma = 0; sigma<t; sigma++){
            st = new StringTokenizer(r.readLine());
            int numAst = Integer.parseInt(st.nextToken());
            long xDim = Long.parseLong(st.nextToken());
            long yDim = Long.parseLong(st.nextToken());
            long ySlope = Long.parseLong(st.nextToken());
            long xSlope = Long.parseLong(st.nextToken());

            long[] astX = new long[numAst];
            long[] astY = new long[numAst];

            for(int sus = 0; sus<numAst; sus++){
                st = new StringTokenizer(r.readLine());
                astX[sus] = Long.parseLong(st.nextToken());
                astY[sus] = Long.parseLong(st.nextToken());
            }

            long xStart = astX[0];
            long yStart = astY[0];

            //for each asteroid congruences are:
            //P*t = x-xStart (mod N)
            //P*t = y-yStart (mod M)

            //for each asteroid solve these congruences for each T mod M and T mod N 
            //then find lowest T mod (lcm(M,N )) to find lowest T is general for all ast

            long lowT = Long.MAX_VALUE;
            long index = -1;
            for(int i = 0; i<numAst; i++){
                //P*t = astX[i]-xStart (mod xDim)
                long changeX = (astX[i] - xStart) % xDim;
                if(changeX<0){ //check if change is negative
                    changeX+=xDim;
                }

                long[] xSolve = modularCongruence(xSlope, changeX, xDim);
                
                //P*t = astY[i]-xStart (mod N)
                long changeY = (astY[i] - yStart) % yDim;
                if(changeY<0){ //check if change is negative
                    changeY+=yDim;
                }

                long[] ySolve = modularCongruence(ySlope, changeY, yDim);

                //final
                if(xSolve != null && ySolve != null){ //gotta check both solutsoins are valid
                    long[] fin = linearCongruence(xSolve[0], xSolve[1], ySolve[0], ySolve[1]);
                    if (fin != null) { //if exists type type
                        long smallT = fin[0];
                        
                        if (smallT == 0) {
                            smallT = fin[1]; //cant be zero cuz statment
                        }
                        
                        if (smallT < lowT){
                            lowT = smallT;
                            index = i;
                        }
                    }
                }
            }
            pw.println(index);
        }

        pw.close();
    }

    public long[] GCD(long a, long b){
        if (b == 0){
            return(new long[] {a, 1, 0});
        }

        long[] fin = GCD(b, a%b);
        long g = fin[0];
        long x = fin[2];
        long y = fin[1] - (a/b)*fin[2];

        return(new long[] {g, x, y});
    }

    public long[] modularCongruence(long A, long B, long M){ //congruence func
        //Ax = B (mod m)
        A = (A%M + M)%M;
        B = (B%M + M)%M;

        long[] gcd = GCD(A, M);
        long g = gcd[0];
        
        if (B%g != 0){
            return null;
            //never gonna hit this aseroid 
        }
        
        long mNew = M/g;
        long inv = (gcd[1]%mNew + mNew)%mNew;
        long t0 = (inv*((B/g)%mNew))%mNew;
        
        return(new long[]{t0, mNew});
    }

    public long[] linearCongruence(long t1, long m1, long t2, long m2){ //func for the end
        long diff = t2 - t1;
        diff = (diff%m2 + m2)%m2; //positive
        
        long[] fin = modularCongruence(m1, diff, m2);
        if (fin == null){
             return null; 
             //cant hit both axis at same time. right?
        }
        
        long xdd = fin[0];
        long lcm = m1*fin[1];
        long t = (t1 + xdd*m1)%lcm;
        
        return(new long[]{t, lcm});
    }
}