// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class NahWin {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int t = s.nextInt();
        while (t-->0){
            int n = s.nextInt();
            int p = s.nextInt();
            int r = s.nextInt();
            int k = s.nextInt();
            boolean works = true;
            for (int i = 1; i<=n; i++){
                int a = s.nextInt();
                p -= a;
                if (p<0) works = false;
                if (i%k==0) p += r;
            }
            pw.println(works?"nah i'd win":"nah i'd lose");
        }
		pw.close();
	}
}
