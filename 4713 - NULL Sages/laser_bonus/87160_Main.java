import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int K = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();
            int P = sc.nextInt();
            int Q = sc.nextInt();
            int[][] asteroids = new int[K][2];
            for (int i = 0; i < K; i++) {
                asteroids[i][0] = sc.nextInt();
                asteroids[i][1] = sc.nextInt();
            }
            int lazarbeam = -1;
            int startX = asteroids[0][0];
            int startY = asteroids[0][1];
            int currX = startX;
            int currY = startY;
            while (true) {
                currX = (currX + Q) % N;
                currY = (currY + P) % M;
                for (int i = 0; i < K; i++) {
                    if (asteroids[i][0] == currX && asteroids[i][1] == currY) {
                        lazarbeam = i;
                    }
                }
                if (lazarbeam != -1) {
                    break;
                }
            }
            System.out.println(lazarbeam);
        }
        sc.close();
    }
}