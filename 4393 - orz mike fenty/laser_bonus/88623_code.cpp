#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define f first
#define s second

ll T, N, X, Y, P, Q, lsr, ans;
vector<ll> srt;
vector<pair<pair<ll, ll>, ll>> pts;
map<ll, vector<ll>> lns;

ll fm(ll n) {
    return ((n % Y) + Y) % Y;
}

ll fc(pair<ll, ll> p) {
    return fm(Q * p.s - P * p.f);
}

ll nxt(ll c) {
    return fm(P * X + c);
}

void solve() {
    cin >> N >> X >> Y >> P >> Q;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        pts.push_back({{x, y}, i});
    }
    lsr = fc(pts[0].f);
    sort(pts.begin(), pts.end());
    for (pair<pair<ll, ll>, ll> i : pts) {
        lns[fc(i.f)].push_back(i.s);
    }
    for (ll i : lns[lsr]) {
        srt.push_back(i);
    }
    if (srt.back() != 0) {
        ans = 0;
        while (srt.size()) {
            if (srt.back() == 0) {
                break;
            }
            ans = srt.back();
            srt.pop_back();
        }
        cout << ans << '\n';
        srt.clear();
        pts.clear();
        lns.clear();
        return;
    }
    lsr = nxt(lsr);
    while (lsr != fc(pts[0].f)) {
        if (lns[lsr].size() > 0) {
            cout << lns[lsr][0] << '\n';
            srt.clear();
            pts.clear();
            lns.clear();
            return;
        }
        lsr = nxt(lsr);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}