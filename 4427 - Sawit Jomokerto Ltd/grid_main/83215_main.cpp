#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll,2> pii;
ll MOD = 998244353;

ll fastexp(ll a, ll b) {
    if (!b) return 1;
    ll tmp = fastexp(a,b/2);
    tmp = (tmp*tmp)%MOD;
    if (b%2) tmp = (tmp*a)%MOD;
    return tmp;
}

//sasakoi
void kaomari_forever() {
    ll n; cin >> n;
    vector<ll> a;
    vector<ll> b;
    ll mx = 0;
    for (ll i = 0; i < n;i++) {
        ll x; cin >> x; a.push_back(x);
        b.push_back(x);
        mx = max(mx,x);
    }
    if (n == 3) {
        if (a[0] <= a[1] && a[1] <= a[2]) {
            b[1] = a[1];
        } else {
            if (abs(a[1]-a[0]) > abs(a[1]-a[2])) {
                b[1] = a[2];
            } else {
                b[1] = a[0];
            }
        }
    }
    for (ll i = 0; i < n;i++) {
        cout << b[i] << " ";
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--) {
        kaomari_forever();
    }
}