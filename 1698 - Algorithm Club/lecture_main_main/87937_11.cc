#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int r, c, u, v;
};

Pt pts[1000005];
int p[2005][2005];
int n, m, k, s;

bool check(int d) {
    for (int i = d + 1; i <= s; ++i) {
        for (int j = d + 1; j <= s; ++j) {
            if (p[i][j] - p[i - d - 1][j] - p[i][j - d - 1] + p[i - d - 1][j - d - 1] >= k) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m >> k;
        s = n + m;
        int pt_idx = 0;

        for (int i = 0; i <= s; ++i) {
            for (int j = 0; j <= s; ++j) {
                p[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j) {
                if (row[j] == '-') {
                    int u = i + j + 1, v = i - j + m;
                    pts[pt_idx++] = {i, j, u, v};
                    p[u][v]++;
                }
            }
        }

        for (int i = 1; i <= s; ++i) {
            for (int j = 1; j <= s; ++j) {
                p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
        }

        int low = 0, high = s, ans = s;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int fr = -1, fc = -1;
        for (int i = ans + 1; i <= s; ++i) {
            for (int j = ans + 1; j <= s; ++j) {
                if (p[i][j] - p[i - ans - 1][j] - p[i][j - ans - 1] + p[i - ans - 1][j - ans - 1] >= k) {
                    fr = i;
                    fc = j;
                    break;
                }
            }
            if (fr != -1) break;
        }

        int cnt = 0;
        for (int i = 0; i < pt_idx; ++i) {
            if (pts[i].u >= fr - ans && pts[i].u <= fr && pts[i].v >= fc - ans && pts[i].v <= fc) {
                cout << pts[i].r << " " << pts[i].c << "\n";
                if (++cnt == k) break;
            }
        }
    }
    return 0;
}