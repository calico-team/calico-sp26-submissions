#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll k,n,m,p,q;
    cin >> k >> n >> m >> p >> q;
    map <pair <ll,ll>, ll> f;
    vector <pair <ll,ll>> l1;
    pair <ll,ll> cur;
    for (int i = 0; i < k; i++){
        ll x,y;
        cin >> x >> y;
        l1.push_back({x,y});
        if (i == 0){
            cur.first = x;
            cur.second = y;
        }
        f[{x,y}] = i + 1;
    }
    cur.first = (cur.first + q) % n;
    cur.second = (cur.second + p) % m;
    while (true){
        if (f[cur] != 0){
            cout << f[cur] - 1 << "\n";
            return;
        }
        cur.first = (cur.first + q) % n;
        cur.second = (cur.second + p) % m;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}