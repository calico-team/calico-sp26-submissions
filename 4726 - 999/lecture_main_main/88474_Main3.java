import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t > 0) {
            t--;
            int n = s.nextInt();
            int m = s.nextInt();
            int k = s.nextInt();
            s.nextLine();

            List<int[]> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String str = s.nextLine();
                for (int j = 0; j < m; j++) {
                    if (str.charAt(j) == '-') {
                        v.add(new int[]{i , j});
                    }
                }
            }

            int l = 0, r = n + m;
            int best = n + m;
            while (l <= r) {
                int md = (l + r) / 2;
                boolean ok = false;
                for (int i = 0; i < v.size(); i++) {
                    List<int[]> cur = new ArrayList<>();
                    cur.add(v.get(i));
                    for (int j = i + 1; j < v.size(); j++) {
                        int[] p = v.get(j);
                        boolean can = true;
                        for (int[] c : cur) {
                            int d = Math.abs(p[0] - c[0]) + Math.abs(p[1] - c[1]);
                            if (d > md) {
                                can = false;
                                break;
                            }
                        }
                        if (can) {
                            cur.add(p);
                            if (cur.size() == k) {
                                ok = true;
                                break;
                            }
                        }
                    }
                    if (ok) break;
                }
                if (ok) {
                    best = md;
                    r = md - 1;
                } else {
                    l = md + 1;
                }
            }

            List<int[]> ans = new ArrayList<>();
            for (int i = 0; i < v.size(); i++) {
                if (ans.size() == k) break;
                int[] p = v.get(i);
                boolean ok = true;
                for (int[] q : ans) {
                    int d = Math.abs(p[0] - q[0]) + Math.abs(p[1] - q[1]);
                    if (d > best) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans.add(p);
                }
            }

            for (int[] p : ans) {
                System.out.println(p[0] + " " + p[1]);
            }
        }
        s.close();
    }
}