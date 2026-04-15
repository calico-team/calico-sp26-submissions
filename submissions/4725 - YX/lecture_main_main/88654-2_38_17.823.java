package UKCC;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int K = sc.nextInt();
            sc.nextLine();

            int total = 0;
            int[][] seats = new int[N*M][2];
            for (int i = 0; i < N; i++) {
                String s = sc.nextLine();
                for (int j = 0; j < M; j++) {
                    if (s.charAt(j) == '-') {
                        seats[total][0] = i;
                        seats[total][1] = j;
                        total++;
                    }
                }
            }

            int best = N + M;
            int L = 0, R = N + M;
            while (L <= R) {
                int mid = (L + R) / 2;
                boolean ok = false;

                for (int st = 0; st < total && !ok; st++) {
                    int cnt = 1;
                    int x0 = seats[st][0];
                    int y0 = seats[st][1];

                    for (int i = st + 1; i < total; i++) {
                        int x = seats[i][0];
                        int y = seats[i][1];
                        int d = Math.abs(x - x0) + Math.abs(y - y0);
                        if (d <= mid) {
                            cnt++;
                            if (cnt >= K) {
                                ok = true;
                                break;
                            }
                        }
                    }
                }

                if (ok) {
                    best = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }

            int[] ans = new int[K];
            int idx = 0;
            int sx = seats[0][0];
            int sy = seats[0][1];
            for (int i = 0; i < total && idx < K; i++) {
                int x = seats[i][0];
                int y = seats[i][1];
                int d = Math.abs(x - sx) + Math.abs(y - sy);
                if (d <= best) {
                    ans[idx++] = i;
                }
            }

            for (int k : ans) {
                System.out.println(seats[k][0] + " " + seats[k][1]);
            }
        }
        sc.close();
    }
}