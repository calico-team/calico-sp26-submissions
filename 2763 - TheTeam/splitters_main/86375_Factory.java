// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class Factory {
    public static char[][] GRID;
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = s.nextInt();
        while (t-->0){
            int n = s.nextInt();
            int m = s.nextInt();
            GRID = new char[n][m];
            for (int i = 0; i<n; i++) GRID[i] = s.next().toCharArray();
            //for (char[] nums : GRID) pw.println(Arrays.toString(nums));

            List<Query> ans = new ArrayList<>();
            LinkedList<Query> q = new LinkedList<>();
            q.add(new Query(0, 0, 1, 1));
            while (!q.isEmpty()){
                Query curr = q.poll();
                char c = GRID[curr.x][curr.y];
                if (c=='<') {
                    if (curr.y==0) ans.add(curr);
                    else q.add(curr.left());
                }
                else if (c=='>') {
                    if (curr.y==m-1) ans.add(curr);
                    else q.add(curr.right());
                }
                else if (c=='^') {
                    if (curr.x==0) ans.add(curr);
                    else q.add(curr.up());
                }
                else if (c=='v') {
                    if (curr.x==n-1) ans.add(curr);
                    else q.add(curr.down());
                }
                else if (c=='S'){
                    int ct = 0;
                    if (GRID[curr.x][curr.y+1]!='<' && GRID[curr.x][curr.y+1]!='.') ct++;
                    if (GRID[curr.x][curr.y-1]!='>' && GRID[curr.x][curr.y-1]!='.') ct++;
                    if (GRID[curr.x-1][curr.y]!='v' && GRID[curr.x-1][curr.y]!='.') ct++;
                    if (GRID[curr.x+1][curr.y]!='^' && GRID[curr.x+1][curr.y]!='.') ct++;
                    //pw.println(ct);

                    if (GRID[curr.x][curr.y+1]!='<') {
                        Query qq = curr.right();
                        qq.den *= ct;
                        q.add(qq);
                    }
                    if (GRID[curr.x][curr.y-1]!='>') {
                        Query qq = curr.left();
                        qq.den *= ct;
                        q.add(qq);

                    }
                    if (GRID[curr.x-1][curr.y]!='v') {
                        Query qq = curr.up();
                        qq.den *= ct;
                        q.add(qq);
                    }
                    if (GRID[curr.x+1][curr.y]!='^') {
                        Query qq = curr.down();
                        qq.den *= ct;
                        q.add(qq);
                    }
                }
            }
            if (ans.isEmpty()) pw.println("0 1");
            else {
                Pair p = new Pair(0, 1);
                for (Query x : ans) p.add(x);
                pw.println(p.num+" "+p.den);
            }
        }
		pw.close();
	}
    static class Pair {
        public long num;
        public long den;
        public Pair(long num, long den){
            this.num = num;
            this.den = den;
        }
        public void add(Query q){
            long newX = (this.num*q.den)+(this.den*q.num);
            long newY = this.den*q.den;
            num = newX;
            den = newY;
            simplify();
        }
        public void simplify(){
            long gcd = calcGCD(num, den);
            num /= gcd;
            den /= gcd;
        }
        public long calcGCD(long a, long b){
            if (b==0) return Math.abs(a);
            else return calcGCD(b, a%b);
        }
    }
    static class Query{
        public int x;
        public int y;
        public long num;
        public long den;

        public Query(int a, int b, long c, long d){
            x = a;
            y = b;
            num = c;
            den = d;
        }
        
        public String toString(){
            return x+" "+y+" "+num+" "+den;
        }
        public Query left(){
            return new Query(x, y-1, num, den);
        }
        public Query right(){
            return new Query(x, y+1, num, den);
        }
        public Query up(){
            return new Query(x-1, y, num, den);
        }
        public Query down(){
            return new Query(x+1, y, num, den);
        }
    }
}
