#include <bits/stdc++.h>

#include <cmath>

using namespace std;

int main() {
    int n;
    int T;
    int L;
    int W;
    int E;
    int R;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> L >> W >> E >> R;
        int p;
        p = 2 * (L + W);
        float s_r;
        s_r = E / R;
        int ans;
        ans = floor(s_r / p);
        cout << ans << endl;
    }

}