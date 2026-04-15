import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Tang {
    private char[][] grid;
    private int n, m;
    private Fraction[][] taken;

    public Tang(){

    }

    public long gcd(long a, long b){
        while(b != 0){
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    class Fraction{
        long num, dem;
        Fraction(long n, long d){
            long common = gcd(Math.abs(n), Math.abs(d));
            num = n/common;
            dem = d/common;
        }
        Fraction add(Fraction other){
            return new Fraction(this.num*other.dem+ other.num*this.dem, this.dem*other.dem);
        }
        Fraction divide(long x){
            return new Fraction(this.num,this.dem*x);
        }
        long numerator(){
            return num;
        }
        long denominator(){
            return dem;
        }
    }

    public boolean valid(int r, int c){
        return r >= 0 && r < n && c >= 0 && c<m;
    }

    public boolean conveyor(char c){
        return c == '^' || c == 'v' || c == '<' || c == '>';
    }

    //t means target - checks if you can go this way from splitter
    public boolean splitway(int sr, int sc, int tr, int tc){
        char t = grid[tr][tc];
        if(t == 'X'){
            return true;
        }
        if(!conveyor(t)){
            return false;
        }
        //checks pointing back
        if(tr < sr && t == 'v'){
            return false;
        }
        if(tr > sr && t == '^'){
            return false;
        }
        if(tc < sc && t == '>'){
            return false;
        }
        if(tc > sc && t == '<'){
            return false;
        }
        return true;
    }

    public void solve() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        for(int fff = 0; fff < t; fff++){
            String[] nm = reader.readLine().split("\\s+");
            n = Integer.parseInt(nm[0]);
            m = Integer.parseInt(nm[1]);

            grid = new char[n][m];
            taken = new Fraction[n][m];

            for(int i = 0; i < n; i++){
                String temp = reader.readLine();
                for(int j = 0; j < m; j++){
                    grid[i][j] = temp.charAt(j);
                }
            }
            Fraction collected = new Fraction(0, 1);
            if(exit(0, 0, grid[0][0])){
                collected = new Fraction(1, 1);
            }
            else {
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < m; c++){
                        char tile = grid[r][c];
                        if(conveyor(tile)){
                            //check if conveyor out of bounds
                            if (exit(r, c, tile)) {
                                collected = collected.add(prob(r, c));
                            }
                        }
                    }
                }
            }

            System.out.println(collected.numerator() + " " + collected.denominator());
        }
    }
    
    public boolean exit(int r, int c, char type){
        if(type == '^' && r == 0){
            return true;        
        } 
        if(type == 'v' && r == n-1){
            return true;        
        } 
        if(type == '<' && c == 0){
            return true;        
        } 
        if(type == '>' && c == m-1){
            return true;        
        } 
        return false;
    }

    public Fraction prob(int r, int c){
        if(r == 0 && c==0){
            return new Fraction(1,1);
        }
        if(taken[r][c] != null){
            return taken[r][c];
        }

        Fraction total = new Fraction(0,1);

        //check adj tiles that feed
        int[] dr = {-1,1,0,0};
        int[] dc = {0,0,-1,1};
        char[] d = {'v', '^', '>', '<'};

        //n - neighbor
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(valid(nr, nc)){
                char nchar = grid[nr][nc];

                //does it feed in
                if(nchar == d[i]){
                    total = total.add(prob(nr,nc));
                }
                else if(nchar == 'S'){// splitter
                    int options = countoption(nr, nc);
                    if(options > 0 && splitway(nr, nc, r, c)){
                        Fraction aftersplit = prob(nr, nc).divide(options);
                        total = total.add(aftersplit);
                    }
                } 
            }
        }

        return taken[r][c] = total;
    }

    //num ways to split
    public int countoption(int r, int c){
        int count = 0;
        int[] dr = {-1,1,0,0};
        int[] dc = {0,0,-1,1};
        char[] d = {'v', '^', '>', '<'};

        for(int i = 0; i < 4; i++){
            int nr = r+dr[i];
            int nc = c+ dc[i];
            if(valid(nr, nc)){
                char t = grid[nr][nc];
                if(t == 'X' || (conveyor(t) && t != d[i])){
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException{
        new Tang().solve();
    }
}
