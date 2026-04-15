#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcdExt(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0; y = 1; return b; }
    ll x1, y1;
    ll gcd = gcdExt(b % a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
// LONGLONGLONGLONGLONGLONGLONGLONGLONGLONGLONGLONG

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int K;
        ll N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<ll, ll>> ass(K);
        for (int i = 0; i < K; i++) cin >> ass[i].first >> ass[i].second;

        ll minT = -1;
        int best = -1;

        for (int i = 0; i < K; i++) {
            ll dx = (ass[i].first - ass[0].first + N)%N;
            ll dy = (ass[i].second - ass[0].second + M)%M;

            ll x, y;
            ll gX = gcdExt(Q, N, x, y);
            if (dx % gX != 0) continue;
            ll modX = N/gX;
            ll tX = ((x*(dx/gX))%modX + modX)%modX;

            ll gY = gcdExt(P, M, x, y);
            if (dy % gY != 0) continue;
            ll modY = M/gY;
            ll tY = ((x*(dy/gY))%modY + modY)%modY;

            ll k, temp;
            ll gCombined = gcdExt(modX, modY, k, temp);
            if ((tY - tX)%gCombined != 0) continue;

            ll period = (modX/gCombined)*modY;
            ll k_val = ((k*((tY - tX)/gCombined))%(modY/gCombined) + (modY/gCombined))%(modY/gCombined);

            ll t = (tX + k_val * modX)%period;

            if (i == 0) t = period;

            if (best == -1 || t < minT) {
                minT = t;
                best = i;
            }
        }
        cout << best << "\n";
    }
    return 0;
}