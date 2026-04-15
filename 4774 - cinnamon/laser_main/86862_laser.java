import java.util.*;
import java.io.*;

public class laser {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        input.nextLine();
        while (t > 0) {
            int k = input.nextInt();
            int n = input.nextInt();
            int m = input.nextInt();
            int p = input.nextInt();
            int q = input.nextInt();
            input.nextLine();
            int[][] map = new int[k][2];
            int idx = 0;
            while (k > 0) {
                map[idx][0] = input.nextInt();
                map[idx][1] = input.nextInt();
                input.nextLine();
                idx++;
                k--;
            }
            int x = map[0][0];
            int y = map[0][1];
            while (true) {
                boolean b = false;
                y += p;
                x += q;
                double dx;
                double dy;
                if (q > p) {
                    dx = 1;
                    dy = (double)p/q;
                    for (int e = 0; e < q; e++) {
                        if (x + (dx * e) != (int)(x + (dx * e)) || y + (dy * e) != (int)(y + (dy * e))) continue;
                        for (int i = 0; i < map.length; i++) {
                            if (x + (dx * e) == (double)map[i][0]) {
                                if (y + (dy * e) == (double)map[i][1]) {
                                    System.out.println(i);
                                    b = true;
                                    break;
                                }
                            }
                        }
                        if (b) break;
                    }
                    if (b) break;
                }
                else {
                    dx = (double)q/p;
                    dy = 1;
                    for (int e = 0; e < p; e++) {
                        if (x + (dx * e) != (int)(x + (dx * e)) || y + (dy * e) != (int)(y + (dy * e))) continue;
                        for (int i = 0; i < map.length; i++) {
                            if (x + (dx * e) == (double)map[i][0]) {
                                if (y + (dy * e) == (double)map[i][1]) {
                                    System.out.println(i);
                                    b = true;
                                    break;
                                }
                            }
                        }
                        if (b) break;
                    }
                    if (b) break;
                }
                boolean c = false;
                if (y >= m) {
                    y -= m;
                    c = true;
                }
                if (x >= n) {
                    x -= n;
                    c = true;
                }
                if (c && q > p) {
                    dx = -1;
                    dy = -(double)p/q;
                    for (int e = 0; e < q; e++) {
                        if (x + (dx * e) != (int)(x + (dx * e)) || y + (dy * e) != (int)(y + (dy * e))) continue;
                        for (int i = 0; i < map.length; i++) {
                            if (x + (dx * e) == (double)map[i][0]) {
                                if (y + (dy * e) == (double)map[i][1]) {
                                    System.out.println(i);
                                    b = true;
                                    break;
                                }
                            }
                        }
                        if (b) break;
                    }
                    if (b) break;
                }
                else if (c) {
                    dx = -(double)q/p;
                    dy = -1;
                    for (int e = 0; e < p; e++) {
                        if (x + (dx * e) != (int)(x + (dx * e)) || y + (dy * e) != (int)(y + (dy * e))) continue;
                        for (int i = 0; i < map.length; i++) {
                            if (x + (dx * e) == (double)map[i][0]) {
                                if (y + (dy * e) == (double)map[i][1]) {
                                    System.out.println(i);
                                    b = true;
                                    break;
                                }
                            }
                        }
                        if (b) break;
                    }
                    if (b) break;
                }
            }
            t--;
        }
    }
}