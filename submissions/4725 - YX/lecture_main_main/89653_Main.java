package UKCC;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt();
            StringBuilder ans = new StringBuilder();

            for (int i = 0; i < a; i++) {
                int n = sc.nextInt();
                int m = sc.nextInt();
                int k = sc.nextInt();
                sc.nextLine();

                String[] g = new String[n];
                for (int x = 0; x < n; x++) {
                    g[x] = sc.nextLine().trim();
                }

                int u = n + m - 1;
                int sh = m - 1;

                ArrayList<Integer>[] col = new ArrayList[u];
                for (int x = 0; x < u; x++) {
                    col[x] = new ArrayList<>();
                }

                for (int x = 0; x < n; x++) {
                    String s = g[x];
                    for (int j = 0; j < m; j++) {
                        if (s.charAt(j) == '-') {
                            int uu = x + j;
                            int vv = x - j + sh;
                            col[uu].add(vv);
                        }
                    }
                }

                int l = -1;
                int r = u - 1;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    int[] cnt = new int[u];
                    boolean ok = false;
                    int rr = -1;

                    int limu = u - mid;
                    int limv = u - mid;

                    for (int left = 0; left < limu; left++) {
                        while (rr + 1 <= left + mid) {
                            rr++;
                            for (int num : col[rr]) {
                                cnt[num]++;
                            }
                        }

                        int s = 0;
                        for (int x = 0; x <= mid; x++) {
                            s += cnt[x];
                        }
                        if (s >= k) {
                            ok = true;
                            break;
                        }

                        for (int down = 1; down < limv; down++) {
                            s += cnt[down + mid];
                            s -= cnt[down - 1];
                            if (s >= k) {
                                ok = true;
                                break;
                            }
                        }

                        if (ok) break;

                        for (int num : col[left]) {
                            cnt[num]--;
                        }
                    }

                    if (ok) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }

                int d = r;
                int[] cnt = new int[u];
                int rr = -1;
                int lu = 0;
                int lv = 0;
                boolean found = false;
                int limu = u - d;
                int limv = u - d;

                for (int left = 0; left < limu; left++) {
                    while (rr + 1 <= left + d) {
                        rr++;
                        for (int num : col[rr]) {
                            cnt[num]++;
                        }
                    }

                    int s = 0;
                    for (int x = 0; x <= d; x++) {
                        s += cnt[x];
                    }
                    if (s >= k) {
                        lu = left;
                        lv = 0;
                        found = true;
                        break;
                    }

                    for (int down = 1; down < limv; down++) {
                        s += cnt[down + d];
                        s -= cnt[down - 1];
                        if (s >= k) {
                            lu = left;
                            lv = down;
                            found = true;
                            break;
                        }
                    }

                    if (found) break;

                    for (int num : col[left]) {
                        cnt[num]--;
                    }
                }

                int got = 0;
                for (int x = 0; x < n && got < k; x++) {
                    String s = g[x];
                    for (int j = 0; j < m && got < k; j++) {
                        if (s.charAt(j) == '-') {
                            int uu = x + j;
                            int vv = x - j + sh;
                            if (uu >= lu && uu <= lu + d && vv >= lv && vv <= lv + d) {
                                ans.append(x).append(" ").append(j).append("\n");
                                got++;
                            }
                        }
                    }
                }
            }

            System.out.print(ans);

        
    }
}