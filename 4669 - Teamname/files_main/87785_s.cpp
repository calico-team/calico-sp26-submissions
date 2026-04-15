// ﷽
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll k,n,m,p,q;
    cin >> k >> n >> m >> p >> q;

    map<pair<ll,ll>, ll> s;

    ll x,y;
    cin >> x >> y;
    s[{x,y}] = -1;

    for(ll i = 1; i < k; i++){
        ll x1,y1;
        cin >> x1 >> y1;
        s[{x1,y1}] = i;
    }

    while(true){
        x = (p + x) % n;
        y = (q + y) % m;
        if(s.count({x,y})){
            ll temp = s[{x,y}];
            if(temp == -1) cout << 0 << "\n";
            else cout << temp << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}