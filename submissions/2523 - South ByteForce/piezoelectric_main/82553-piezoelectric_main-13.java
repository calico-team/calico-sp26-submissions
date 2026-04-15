import java.util.*;
import java.io.*;

public class Q1 {
    public static int solve(int L, int W, int E, int R) {
        int perimeter = 2 * (L + W);
        int electricityPerLap = perimeter * R;
        return (E / electricityPerLap);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int L = Integer.parseInt(str[0]);
            int W = Integer.parseInt(str[1]);
            int E = Integer.parseInt(str[2]);
            int R = Integer.parseInt(str[3]);
            System.out.println(solve(L, W, E, R));
        }
    }
}