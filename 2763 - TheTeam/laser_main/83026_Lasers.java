// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class Lasers {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int t = s.nextInt();
        while (t-->0){
            int k = s.nextInt();
            int n = s.nextInt();
            int m = s.nextInt();
            int p = s.nextInt();
            int q = s.nextInt();
            int[][] asts = new int[k][2];
            int[][] grid = new int[n][m];

            for (int i = 0; i<k; i++){
                asts[i][0] = s.nextInt();
                asts[i][1] = s.nextInt();
                grid[asts[i][0]][asts[i][1]] = i+1;
            }

            int laserX = asts[0][0];
            int laserY = asts[0][1];

            while (true){
                laserX = (laserX+q)%n;
                laserY = (laserY+p)%m;
                if (grid[laserX][laserY]>0) {
                    pw.println(grid[laserX][laserY]-1);
                    break;
                }
            }

        }
		pw.close();
	}
}
