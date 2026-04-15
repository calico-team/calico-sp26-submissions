#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define l(a, b, i) for (ll i = a; i < b; i++)
#define rl(a, b, i) for (ll i = a; i >= b; i--)
#define vpair vector<pair<ll, ll>>
#define inf LLONG_MAX
#define ninf LLONG_MIN

void solve() {
    ll K, M, N, P, Q, X, Y; cin >> K >> N >> M >> P >> Q;
    vector<pair<ll, ll>> ast(K + 1);
    l(0, K, i) {
        cin >> X >> Y;
        ast[i] = {X, Y};
    }

    map<pair<ll, ll>, ll> mp;
    l(0, K, i) mp[ast[i]] = i; 

    ll sx = ast[0].first, sy = ast[0].second;

    l(0, N * M, i) {
        sx = (sx + Q) % N;
        sy = (sy + P) % M;

        if (mp.count({sx, sy})) {
            cout << mp[{sx, sy}] << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while (T--) solve();
}