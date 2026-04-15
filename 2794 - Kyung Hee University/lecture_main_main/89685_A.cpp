#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char grid[2001][2001];
int revtrisum[4001][2001], drevtrisum[4001][2002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        N <<= 1;
        M <<= 1;
        for (int i = 0; i <= N + M; i++) {
            for (int j = 0; j <= M; j++) {
                if (i < N && (i & 1) && (j & 1)) {
                    cin >> grid[i][j];
                    revtrisum[i][j] = grid[i][j] == '-';
                }
                else revtrisum[i][j] = 0;
                if (i) {
                    if (i - 1 < N && ((i - 1) & 1) && (j & 1)) revtrisum[i][j] += grid[i - 1][j] == '-';
                    if (j) revtrisum[i][j] += revtrisum[i - 1][j - 1];
                    else if (i - 1) revtrisum[i][j] += revtrisum[i - 2][0];
                    if (j + 1 <= M) revtrisum[i][j] += revtrisum[i - 1][j + 1];
                    else if (i - 1) revtrisum[i][j] += revtrisum[i - 2][M];
                    if (i - 1) revtrisum[i][j] -= revtrisum[i - 2][j];
                }
                //cout << "revtrisum[" << i << "][" << j << "] = " << revtrisum[i][j] << '\n';
            }
            drevtrisum[i][0] = revtrisum[i][0];
            for (int j = 1; j <= M; j++) {
                drevtrisum[i][j] = revtrisum[i][j - 1] + revtrisum[i][j];
                if (i) drevtrisum[i][j] -= drevtrisum[i - 1][j];
            }
            drevtrisum[i][M + 1] = revtrisum[i][M];
        }

        int l = 0, r = N + M, ans = r, ax = 0, ay = 0;;
        while (l <= r) {
            int mid = (l + r) >> 1, tmp = 0, tx = 0, ty = 0;;
            for (int i = 0; i <= N + M; i++) {
                for (int j = 0; j <= M; j++) {
                    int ttmp = revtrisum[i][j];
                    if (i >= mid + 1) {
                        if (j >= mid) ttmp -= drevtrisum[i - mid - 1][j - mid];
                        else if (mid - j + mid <= i) ttmp -= revtrisum[i + j - mid - mid - 1][0];
                        if (j + mid <= M) ttmp -= drevtrisum[i - mid - 1][j + mid + 1];
                        else if (j + mid - M + mid <= i) ttmp -= revtrisum[i - j - mid - mid + M - 1][M];
                        if (i - 1 >= mid << 1) ttmp += revtrisum[i - mid - mid - 1][j];
                    }
                    if (tmp <= ttmp) {
                        tmp = ttmp;
                        tx = i;
                        ty = j;
                    }
                    //if (mid == 1 && i == 2 && j == 4) cout << "feriojfweiof " << ttmp << '\n';
                }
            }
            //cout << "mid-tmp-tx-ty : " << mid << ' ' << tmp << ' ' << tx << ' ' << ty << '\n';
            if (tmp >= K) {
                ans = mid;
                ax = tx;
                ay = ty;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        vector<pii> anspt;
        //cout << "ans : " << ans << '\n' << "ax : " << ax << '\n' << "ay : " << ay << '\n';
        for (int i = ax - ans - ans; i <= ax && anspt.size() < K; i++) {
            for (int j = ay - ans + abs(ax - ans - i); j <= ay + ans - abs(ax - ans - i) && anspt.size() < K; j++) {
                //cout << i << ' ' << j << '\n';
                if (0 <= i && 0 <= j && j <= M && (i & 1) && (j & 1) && grid[i][j] == '-') anspt.push_back({i >> 1, j >> 1});
            }
        }
        //cout << '\n';
        for (pii i : anspt) cout << i.first << ' ' << i.second << '\n';
        //cout << '\n';
    }
}