import java.util.*;
import java.io.*;

public class Q2 {
    public static String solve(int N, int P, int R, int K, int[] E) {
        long power = P;
        for (int i = 1; i <= N; i++) {
            power -= E[i - 1];
            if (power < 0)
                return "nah i'd lose";
            if (i % K == 0)
                power += R;
        }
        return "nah i'd win";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            String[] str = br.readLine().split(" ");
            int N = Integer.parseInt(str[0]);
            int P = Integer.parseInt(str[1]);
            int R = Integer.parseInt(str[2]);
            int K = Integer.parseInt(str[3]);
            String[] e = br.readLine().split(" ");
            int[] E = new int[N];
            for (int j = 0; j < N; j++) {
                E[j] = Integer.parseInt(e[j]);
            }
            System.out.println(solve(N, P, R, K, E));
        }
    }
}
