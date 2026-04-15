package UKCC;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] h = new int[n];
            for (int i = 0; i < n; i++) {
                h[i] = sc.nextInt();
            }

            List<Integer> val = new ArrayList<>();
            List<Integer> len = new ArrayList<>();
            List<Integer> pos = new ArrayList<>();

            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && h[j] == h[i]) j++;
                val.add(h[i]);
                len.add(j - i);
                pos.add(i);
                i = j;
            }

            int m = val.size();
            if (m == 1) {
                for (int k = 0; k < n; k++) System.out.print(val.get(0) + " ");
                System.out.println();
                continue;
            }

            int[] l = new int[m];
            int[] r = new int[m];
            boolean[] live = new boolean[m];
            for (int x = 0; x < m; x++) {
                l[x] = x - 1;
                r[x] = x + 1;
                live[x] = true;
            }
            r[m - 1] = -1;

            boolean updated;
            do {
                updated = false;
                int target = -1;

                for (int x = 0; x < m; x++) {
                    if (!live[x] || len.get(x) != 1) continue;
                    int L = l[x];
                    int R = r[x];
                    if (L < 0 || R < 0 || !live[L] || !live[R]) continue;

                    boolean peak = val.get(L) < val.get(x) && val.get(x) > val.get(R);
                    boolean valley = val.get(L) > val.get(x) && val.get(x) < val.get(R);
                    if (peak || valley) {
                        target = x;
                        break;
                    }
                }

                if (target == -1) break;
                updated = true;
                int x = target;
                int L = l[x];
                int R = r[x];
                if (val.get(x) > val.get(L) && val.get(x) > val.get(R)) {
                    val.set(x, Math.max(val.get(L), val.get(R)));
                } else {
                    val.set(x, Math.min(val.get(L), val.get(R)));
                }
                if (val.get(x) == val.get(L)) {
                    len.set(L, len.get(L) + len.get(x));
                    r[L] = r[x];
                    if (r[x] != -1) l[r[x]] = L;
                    live[x] = false;
                    x = L;
                }

                R = r[x];
                if (R != -1 && val.get(x) == val.get(R)) {
                    len.set(x, len.get(x) + len.get(R));
                    r[x] = r[R];
                    if (r[R] != -1) l[r[R]] = x;
                    live[R] = false;
                }

            } while (updated);

            int[] ans = new int[n];
            int cur = 0;
            while (cur != -1 && !live[cur]) cur = r[cur];
            while (cur != -1) {
                int st = pos.get(cur);
                int length = len.get(cur);
                int v = val.get(cur);
                for (int k = st; k < st + length; k++) ans[k] = v;
                cur = r[cur];
            }

            for (int num : ans) System.out.print(num + " ");
            System.out.println();
        }
    }
}
